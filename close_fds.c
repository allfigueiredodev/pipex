#include "pipex.h"

void close_unused_fds(int (* fds)[2], int pid, int total_fds)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < total_fds)
	{
		if(fds[i][j] != fds[pid - 1][j])
		{
			close(fds[i][j]);
			printf("closed: fd[%d][%d]\n", i, j);
		}
		i++;
	}
	i = 0;
	j = 1;
	while(i < total_fds)
	{
		if(fds[i][j] != fds[pid][j])
		{
			close(fds[i][j]);
			printf("closed: fd[%d][%d]\n", i, j);
		}
		i++;	
	}
}

void close_all_fds(int (* fds)[2], int total_fds)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(i < total_fds)
	{
		close(fds[i][j]);
		close(fds[i][j + 1]);
		i++;
	}
}

// int main(void)
// {
// 	int fds[5][2];
// 	int i = 0;

// 	while(i <= 4)
// 	{
// 		pipe(fds[i]);
// 		i++;
// 	}
// 	// close_unused_fds(fds, 4, 5);
// 	close_all_fds(fds, 5);
// }

//fd[0][0]  - pid1
//fd[0][1] 	
//fd[1][0]	- pid2
//fd[1][1]  - pid1
//fd[2][0]
//fd[2][1]	- pid2
//fd[3][0]
//fd[3][1]
//fd[4][0]
//fd[4][1]