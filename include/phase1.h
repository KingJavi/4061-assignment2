#ifndef PHASE1_H
#define PHASE1_H
// Add Guard to header file (google what are guards)
// Function prototypes to
//			Traverse the Folder
//			Partition the text file paths to 'm' files

//clean these up later
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> //SHOULD NOT NEED -----------------------------

#define BUFF_SIZE 13 //"Mapper_##.txt"

int phase1(char *pathName, int numMappers, FILE *fp[]);
void traverseDir(char *pathName, int numMappers, FILE *fp[]);

#endif
