#ifndef PHASE1_H
#define PHASE1_H
// Add Guard to header file (google what are guards)
// Function prototypes to
//			Traverse the Folder
//			Partition the text file paths to 'm' files

#define BUFF_SIZE 9

void phase1(char *folder, int numMappers);

void traverseDir(char *path, int numMappers, FILE *fp[], char *mapperFiles[]);

//clean these up later
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <stdio.h> //SHOULD NOT NEED -----------------------------


#endif

/*-----------------------------------------------------------------------------------
#include "phase1.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>


// You are free to use your own logic. The following points are just for getting started
/* 	Data Partitioning Phase - Only Master process involved
	1) 	Create 'MapperInput' folder
	2) 	Traverse the 'Sample' folder hierarchy and insert the text file paths
		to Mapper_i.txt in a load balanced manner
	3) 	Ensure to keep track of the number of text files for empty folder condition

*/
static int mapperFileIndex;  //this will keep track of which mapperFile we are putting
                             //txt files into

void traverseDir(char* path, char* mapperFiles, FILE* fp, int m)
{

  struct dirent *de;      //create dirent struct of our parent directory
  int i = 0;              //counter that keeps track of which mapper.txt file
                          //we want to write to

  DIR *dr = opendir(path);    //open the directory

  if (dr == NULL)         //if we couldnt open it throw error
  {
    printf("\nCould not open given directory.\n");
  }

  while ((de = readdir(dr)) != NULL)    //while there are still more files to traverse
  {
    if (de->d_type == DT_DIR)     //if current file is a directory, call recursively
    {

      char newpath[PATH_MAX];   //create string to put new path name
      snprintf(newpath, sizeof(newpath), "%s/%s", path, de->d_name);  //copy new path over
      traverseDir(newpath, mapperFiles, fp, m);      //recursive call

    }

    else    //current directory is not a folder (ie it is a .txt file) ************
    {

      char newpath[PATH_MAX];   //create string to put new path name
      snprintf(newpath, sizeof(newpath), "%s/%s", path, de->d_name);  //copy new path over

      char txtFileName[] = "";            //string that wil hold current txt file name
			strcpy(txtFileName, de->d_name);    //copy that name to the string

			strcat(newpath, "/");               //add a slash to the end of filepath
			strcat(newpath, txtFileName);       //add the filename to end of filepath

      fprintf(fp, newpath);     //print the filepath of the txt file to the Mapper file
      fprintf(fp, "\n");

      mapperFileIndex++;    //increment mapperFileIndex

    }

  }

  closedir(dr);
}

void phase1(char* path, int m)
{

  mkdir("MapperInput", 0700);        //create directory to put mapper.txt files in
  //do error check, 0 if succesful

  //dont think we will need this line to next line -----------------------------------
  //char cwd[PATH_MAX];
  //getcwd(cwd, sizeof(cwd));          //get current working directory and put it in 'cwd'
  //printf("\ncwd is: %d\n", cwd);     //see if we got cwd correctly

  //strcat(cwd, "MapperInput");           //create full FP to MapperInput
  //char MapperInputFilepath[PATH_MAX];   //create string to put in Mapper Input FP
  //strcpy(MapperInputFilepath, cwd);     //copy that FP into our string
  //next line ------------------------------------------------------------------------

  FILE *fp[m];           //array that will hold filepointers to mapperFiles
  char buffer[m][100];   //array that will hold the txt filenames
  char *mapperFiles[m];  //array of all of our Mapper_i.txt files
  chdir("MapperInput");  //change the current directory to the folder we created so
                         //when we crate txt files they are in there.

  for (int i = 0 ; i < m ; i++)
  {
    sprintf(buffer[i], "Mapper%d", i);   //put current txt filename in buffer
    mapperFiles[i] = buffer[i];          //store current txt filename in array of filenames
    fp[i] = fopen(mapperFiles[i], "a");  //store filepointer in array of fps
    //printf("%s\n", mapperFiles[i]);    //test to see if filling array worked
  }

  //traverse the entire directory and fill the Mapper.txt files
  traverseDir(path, *mapperFiles, *fp, m);

  //chdir("..");  //go back out to parent directory if we have to

}
-------------------------------------------------------------------------------------*/
