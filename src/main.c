#include "main.h"

/*
./mapreduce ../Testcases/TestCase2 32
*/

int main(int argc, char *argv[])
{
	// argument count check.
	if(argc != 3)
	{
		fprintf(stderr,"Wrong number of arguments\n");
		return 0;
	}

	char *pathName = argv[1]; //root folder to be traversed
	int numMappers = atoi(argv[2]); //num of mapper processes
	FILE * fp[numMappers]; //pointers to text files
	int pipes[numMappers][2]; //for pipes
	FILE * fpReducer = fopen("ReducerResult.txt", "w");
	FILE * fpFinal = fopen("FinalResult.txt", "w");
	int i;

	fprintf(fpReducer, "bang");
	fprintf(fpFinal, "bang");

	//phase1 - Data Partition Phase
	if(phase1(pathName, numMappers, fp) == 0)
	{
		fprintf(stderr,"Empty directory");
		return 0;
	}

	//create pipes
	for(i = 0; i < numMappers; i++)
	{
		pipe(pipes[i]);
	}

	phase2(numMappers, pipes, fp);

/*
	//just make a function call to code in phase3.c
	//phase3 - Reduce Function
	phase3(numMappers, pipes[i]);

*/
	//phase4
	//wait for all processes to reach this point
	//WE ALREADY WAITED

	//just make a function call to code in phase4.c
	//master process reports the final output

	return 0;

}
