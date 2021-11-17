#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
    
    printf("Start of parent process\n");
    int process;
    process = fork();
    if (process) process = fork();
    if (!process) {
        printf("child pid: %d\n", getpid());
        srand(time(NULL));
        int sec = (rand() % 4) + 2;
        sleep(sec);
        printf("End of child process\n");
        return sec;
    }
    else {
        int status, sec;
        sec = wait(&status);
        printf("child pid: %d\nseconds asleep: %d\n", sec, WEXITSTATUS(status));
        printf("End of parent program\n");
    }
    return 0;
}