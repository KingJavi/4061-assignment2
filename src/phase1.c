#include "phase1.h"
// You are free to use your own logic. The following points are just for getting started
/* 	Data Partitioning Phase - Only Master process involved
	1) 	Create 'MapperInput' folder
	2) 	Traverse the 'Sample' folder hierarchy and insert the text file paths
		to Mapper_i.txt in a load balanced manner
	3) 	Ensure to keep track of the number of text files for empty folder condition

*/

static int mapperFileIndex;  //this will keep track of which mapperFile we are putting
                             //txt files into

void traverseDir(char *path, int numMappers, FILE *fp[])
{

  struct dirent *de; //create dirent struct of our parent directory

  DIR *dr = opendir(path); //pointer to directory, in our case it is a test case
  if (dr == NULL)         //if we couldnt open it throw error
  {
    printf("\nCould not open given directory.\n");
  }

  //shouldnt need, tells us where we at
  /*
  char dirbuff[PATH_MAX];
  printf("\n%s\nWHATWHAT\n", getcwd(dirbuff, PATH_MAX));
  */

  while ((de = readdir(dr)) != NULL)    //while there are still more files to traverse
  {
    if (de->d_type == DT_DIR)     //if current file is a directory, call recursively
    {
    char newpath[PATH_MAX];   //create string to put new path name
    snprintf(newpath, sizeof(newpath), "%s/%s", path, de->d_name);  //copy new path over
    traverseDir(newpath, mapperFiles, fp, m);      //recursive call
    } //if
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

    } //else

  } //while

  closedir(dr);

  return ;
}


void phase1(char *folder, int numMappers) // probably change var name
{
  int i;
  char *buffer[numMappers][BUFF_SIZE]; //used for sprintf
  char *mapperFiles[numMappers]; //names, MIGHT NOT NEED ----DELETE MAYBE
  FILE * fp[numMappers]; //pointers to text files

  mkdir("MapperInput", 0700); //0 if successful, ERROR CASE NEEDED
  chdir("MapperInput"); //moves into MapperInp

  for(i = 0; i < numMappers; i++)
  {
      sprintf(buffer[i],"Mapper_%d", i);
      mapperFiles[i] = buffer[i]; //storing text file names
      fp[i] = fopen(mapperFiles[i], "w"); //creating text files
  }

  chdir("..");//brings us back, might not need

  traverseDir(folder, numMappers, fp); //puts paths into txt files

  return ;
}
