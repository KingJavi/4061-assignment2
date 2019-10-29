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

	if(numMappers > 32)
	{
		fprintf(stderr,"Too many mappers, less 32 or less required\n");
		return 0;
	}

	FILE * fp[numMappers]; //pointers to text files
	int pipes[numMappers][2]; //for pipes
	FILE * fpReducer = fopen("ReducerResult.txt", "w");
	FILE * fpFinal = fopen("FinalResult.txt", "w");
	int i;
	char c;
	int numLetters[26];
	char letters[26];
	for(c = 'A', i = 0; i < 26; c++, i++)
		letters[i] = c;

	char *mapperFiles[numMappers]; //names

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

	phase2(numMappers, numLetters); //names);

	char buffer[numMappers][1000];
	for(i = 0; i < numMappers; i++)
	{
		sprintf(buffer[i],"MapperInput/Mapper_%d.txt", i);
		countLetters(buffer[i], numLetters);
	}

	for(i = 0; i < 26; i++)
	{
		fprintf(fpFinal, "%c %d\n", letters[i], numLetters[i]);
		fprintf(fpReducer, "%c %d\n", letters[i], numLetters[i]);
		printf("%c %d\n", letters[i], numLetters[i]);
	}

	fclose(fpFinal);
	fclose(fpReducer);
/*
	//just make a function call to code in phase3.c
	//phase3 - Reduce Function
	phase3(numMappers, pipes[i]);

*/
	//phase4
	//wait for all processes to reach this point

	//just make a function call to code in phase4.c
	//master process reports the final output

	return 0;

}
