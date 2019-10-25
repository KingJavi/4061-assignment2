#ifndef PHASE2_H
#define PHASE2_H
// Add Guard to header file
// Function prototypes for
//			map function that will go through text files in the Mapper_i.txt to get the (letter, wordcount)

//clean these up later
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> //SHOULD NOT NEED -----------------------------

void phase2(int numMappers, int pipes[numMappers][2], FILE *fp[]);

#endif
