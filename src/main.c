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
	FILE * fp[numMappers]; //pointers to text files

	//phase1 - Data Partition Phase
	if(phase1(pathName, numMappers, fp) == 0)
	{
		fprintf(stderr,"Empty directory");
		return 0;
	}

	//create pipes
	pid_t *Mapperpids[numMappers];
  int fdread[2];
  int fdwrite[2];



	if(Parentpid > 0)
	{
		for (i = 1 ; i <= numMappers ; i++)
		{
		  Mapperpids[i] = fork();
		}
	}

	//just make a function call to code in phase2.c
	//phase2 - Map Function
	phase2()

	//just make a function call to code in phase3.c
	//phase3 - Reduce Function

	//phase4
	//wait for all processes to reach this point

	//just make a function call to code in phase4.c
	//master process reports the final output

	return 0;

}
