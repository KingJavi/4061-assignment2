#include "phase1.h"
// You are free to use your own logic. The following points are just for getting started
/* 	Data Partitioning Phase - Only Master process involved
	1) 	Create 'MapperInput' folder
	2) 	Traverse the 'Sample' folder hierarchy and insert the text file paths
		to Mapper_i.txt in a load balanced manner
	3) 	Ensure to keep track of the number of text files for empty folder condition

*/

static int mapperFileIndex = 0;  //this will keep track of which mapperFile we are putting txt files into
static int numtxtFiles = 0;

void traverseDir(char *pathName, int numMappers, FILE *fp[])
{
  DIR *path = opendir(pathName); //pointer to directory, in our case it is a test case
  if (path == NULL)              //if we couldnt open it throw error
  {
    printf("\nCould not open given directory.\n");
  }

  struct dirent *de; //create dirent struct of dir

  while ((de = readdir(path)) != NULL)    //while there are still more files to traverse
  {

    if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) //skip both cases
      continue;

    if (de->d_type == DT_DIR)     //if current file is a directory, need to call recursively
    {
      char newpath[PATH_MAX];   //create string to put new path name
      snprintf(newpath, sizeof(newpath), "%s/%s", pathName, de->d_name);  //copy new path over
      traverseDir(newpath, numMappers, fp);      //recursive call
    }
    else //current directory is not a folder (ie it is a .txt file) ************
    {
      char newpath[PATH_MAX];   //create string to put new path name
      snprintf(newpath, sizeof(newpath), "%s/%s", pathName, de->d_name);  //copy new path over

      char txtFileName[] = ""; //string that wil hold current txt file name

      fprintf(fp[mapperFileIndex%numMappers], newpath);     //print the filepath of the txt file to the Mapper file
      fprintf(fp[mapperFileIndex%numMappers], "\n");

      mapperFileIndex++; //increment mapperFileIndex
      numtxtFiles++;
    } //else

  } //while

  close(path);

  return ;
}


int phase1(char *pathName, int numMappers, FILE *fp[]) // probably change var name
{
  int i;
  char *buffer[numMappers][BUFF_SIZE]; //used for sprintf
  char *mapperFiles[numMappers]; //names, MIGHT NOT NEED ----DELETE MAYBE

  mkdir("MapperInput", 0700); //0 if successful, ERROR CASE NEEDED
  chdir("MapperInput"); //moves into MapperInp

  for(i = 0; i < numMappers; i++)
  {
      sprintf(buffer[i],"Mapper_%d.txt", i);
      mapperFiles[i] = buffer[i]; //storing text file names
      fp[i] = fopen(mapperFiles[i], "w"); //creating text files
  }

  chdir("..");//brings us back, might not need

  traverseDir(pathName, numMappers, fp); //puts paths into txt files

  return numtxtFiles;
}
