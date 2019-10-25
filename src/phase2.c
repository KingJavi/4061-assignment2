#include "phase2.h"
// You are free to use your own logic. The following points are just for getting started
/* 	Map Function
	1)	Each mapper selects a Mapper_i.txt to work with
	2)	Creates a list of letter, wordcount from the text files found in the Mapper_i.txt
	3)	Send the list to Reducer via pipes with proper closing of ends
*/

void phase2(int numMappers, int pipes[numMappers][2], FILE *fp[])
{
  int i;
  int j;
  char 
  char *txtFilePath;
  char buffer[100];
  char letters[26];
  int numletters[26];


  for(i = 0; i < numMappers; i++)
  {
    for(j = 0; j < numMappers; j++)
    {
      pipes[i][0];
    }
  }


  return ;
}
