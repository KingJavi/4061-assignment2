#ifndef PHASE3_H
#define PHASE3_H
// Add Guard to header file
// Function prototype for
//			reduce function that will receive list from all the Mappers to create a single list
//			the single list is then written to ReducerResult.txt

//clean these up later
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h> //SHOULD NOT NEED -----------------------------

void phase3(int numMappers, int pipes[numMappers]);

#endif
