#include "pipex.h"

// int main(void)
// {
// 	int pid = fork();
// 	int n;
	
// 	if(pid == 0)
// 		n = 1;
// 	else
// 		n = 6;
// 	if(pid != 0){
// 		wait(NULL);
// 	}

// 	int i = n;
// 	if(pid != 0)
// 	{
// 		while(i < n + 5)
// 		{
// 			printf("%d ", i + 1000);
// 			fflush(stdout);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while(i < n + 5)
// 		{
// 			printf("%d ", i);
// 			fflush(stdout);
// 			i++;
// 		}
// 	}
// 	if(pid != 0)
// 		printf("\n");
// 	return(0);
// }

int main(int argc, char *argv[])
{
	static char *newargv[] = { "printf", "hello world\n", NULL };
	static char *newenviron[] = { NULL };

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	newargv[0] = argv[1];

	execve(argv[1], newargv, newenviron);
	perror("execve");   /* execve() returns only on error */
	exit(EXIT_FAILURE);
}