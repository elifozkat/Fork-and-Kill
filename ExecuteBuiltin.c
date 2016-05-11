
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;

	pid = fork();
	char* elif[]={"gnome-calculator",NULL};
	printf("The value of pid %d\n", pid);

	if (pid == 0) { /* child process */
	  printf("Child process id %d\n", getpid());
	  execvp("gnome-calculator", elif);
	
	}
	else if (pid > 0) { /* parent process */
	  sleep(3);
	  kill(pid, SIGKILL);
	  printf("Child is killed and its process id %d\n", pid);
	 
	}
	return 0;
}
