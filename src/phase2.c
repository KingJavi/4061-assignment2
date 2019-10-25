#include "phase2.h"
// You are free to use your own logic. The following points are just for getting started
/* 	Map Function
	1)	Each mapper selects a Mapper_i.txt to work with
	2)	Creates a list of letter, wordcount from the text files found in the Mapper_i.txt
	3)	Send the list to Reducer via pipes with proper closing of ends
*/

void readMapper(char *filename, int * numLetters)
{

  char *line_buf = NULL;
  size_t line_buf_size = 0;
  ssize_t line_size;
  FILE *fp = fopen(filename, "r");

  chdir("MapperInput");
  line_size = getline(&line_buf, &line_buf_size, fp);
  countLetters(line_buf, numLetters);
  chdir("..");


  while (line_size > 0)
  {
    chdir("MapperInput");
    line_size = getline(&line_buf, &line_buf_size, fp);
    countLetters(line_buf, numLetters);
    //printf("%s", line_buf);
    chdir("..");

  }

  free(line_buf);
  fclose(fp);

  return;
}

void countLetters(char *filename, int * numLetters)
{
  int c;
  FILE *fp = fopen(filename, "r");
  while ((c = fgetc(fp)) != EOF)
  {
    if (c == 'a' || c == 'A')
      numLetters[0]++;
    if (c == 'b' || c == 'B')
      numLetters[1]++;
    if (c == 'c' || c == 'C')
      numLetters[2]++;
    if (c == 'd' || c == 'D')
      numLetters[3]++;
    if (c == 'e' || c == 'E')
      numLetters[4]++;
    if (c == 'f' || c == 'F')
      numLetters[5]++;
    if (c == 'g' || c == 'G')
      numLetters[6]++;
    if (c == 'h' || c == 'H')
      numLetters[7]++;
    if (c == 'i' || c == 'I')
      numLetters[8]++;
    if (c == 'j' || c == 'J')
      numLetters[9]++;
    if (c == 'k' || c == 'K')
      numLetters[10]++;
    if (c == 'l' || c == 'L')
      numLetters[11]++;
    if (c == 'm' || c == 'M')
      numLetters[12]++;
    if (c == 'n' || c == 'N')
      numLetters[13]++;
    if (c == 'o' || c == 'O')
      numLetters[14]++;
    if (c == 'p' || c == 'P')
      numLetters[15]++;
    if (c == 'q' || c == 'Q')
      numLetters[16]++;
    if (c == 'r' || c == 'R')
      numLetters[17]++;
    if (c == 's' || c == 'S')
      numLetters[18]++;
    if (c == 't' || c == 'T')
      numLetters[19]++;
    if (c == 'u' || c == 'U')
      numLetters[20]++;
    if (c == 'v' || c == 'V')
      numLetters[21]++;
    if (c == 'v' || c == 'W')
      numLetters[22]++;
    if (c == 'v' || c == 'X')
      numLetters[23]++;
    if (c == 'v' || c == 'Y')
      numLetters[24]++;
    if (c == 'v' || c == 'Z')
      numLetters[25]++;
  }
  close(fp);
  return ;
}

void phase2(int numMappers,  int * numLetters)
{
  int i;

  char *buffer[numMappers][1000];

  for(i = 0 ; i < numMappers ; i++)
  {
    sprintf(buffer[i],"Mapper_%d.txt", i);
    readMapper(buffer[i], numLetters);
  }

  return ;
}
