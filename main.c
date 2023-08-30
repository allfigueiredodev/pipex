#include "pipex.h"

int main(void)
{
	int pid = fork();
	int n;
	
	if(pid == 0)
		n = 1;
	else
		n = 6;
	if(pid != 0){
		wait(NULL);
	}

	int i = n;
	if(pid != 0)
	{
		while(i < n + 5)
		{
			printf("%d ", i + 1000);
			fflush(stdout);
			i++;
		}
	}
	else
	{
		while(i < n + 5)
		{
			printf("%d ", i);
			fflush(stdout);
			i++;
		}
	}
	if(pid != 0)
		printf("\n");
	return(0);
}