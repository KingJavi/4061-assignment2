#include "phase1.h"
// You are free to use your own logic. The following points are just for getting started
/* 	Data Partitioning Phase - Only Master process involved
	1) 	Create 'MapperInput' folder
	2) 	Traverse the 'Sample' folder hierarchy and insert the text file paths
		to Mapper_i.txt in a load balanced manner
	3) 	Ensure to keep track of the number of text files for empty folder condition

*/

void traverseDir(char *path, int numMappers, FILE *fp[], char *mapperFiles[])
{
  
}

void phase1(char *folder, int numMappers) // probably change var name
{
  int i;
  char *mapperFiles[numMappers]; //names
  char buffer[BUFF_SIZE]; //used for sprintf
  FILE * fp[numMappers]; //pointers to text files

  mkdir("MapperInput", 0700); //0 if successful, ERROR CASE NEEDED
  chdir("MapperInput"); //moves into MapperInp dir/file

  for(i = 0; i < numMappers; i++)
  {
      sprintf(buffer,"Mapper_%d", i);
      mapperFiles[i] = buffer; //storing text file names
      fp[i] = fopen(mapperFiles[i], "w"); //creating text files
  }
  chdir("..");//brings us back, might not need





  return ;
}
