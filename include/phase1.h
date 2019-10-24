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
