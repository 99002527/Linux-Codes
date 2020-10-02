#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


/*
5. Write a program to compile & link any c/c++ program within child process by launching gcc using execl/execlp.
*/

int main(){

	char line[1024];

	pid_t pid=fork();

	if(pid==0){

		printf("enter filename\n");

		gets(line);

		execl("/bin/gcc","gcc",line,NULL);

		exit(127);

	}

	else{

		waitpid(pid,0,0);

	}

	return 0;

	}

