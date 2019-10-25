#include "main.h"

int main(int argc, char *argv[])
{
	// argument count check.
	if(argc != 3)
	{
		fprintf(stderr,"Wrong number of arguments");
		return 0;
	}

	char *pathName = argv[1]; //root folder to be traversed
	int numMappers = atoi(argv[2]); //num of mapper processes

	//just make a function call to code in phase1.c
	//phase1 - Data Partition Phase
	if(phase1(pathName, numMappers) == 0)
	{
		fprintf(stderr,"Empty directory");
		return 0;
	}

	//create pipes

	//just make a function call to code in phase2.c
	//phase2 - Map Function

	//just make a function call to code in phase3.c
	//phase3 - Reduce Function

	//phase4
	//wait for all processes to reach this point

	//just make a function call to code in phase4.c
	//master process reports the final output

	return 0;

}
