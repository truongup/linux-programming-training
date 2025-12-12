#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

int seconds = 0;
void sigalarm_handler(int num_sig) {
    seconds++;

    printf("Timer %d seconds\n", seconds);

    alarm(1);   // set lại arlarm 1 giây

    // kết thúc tất cả sau 10 giây
    if(seconds == 10) 
        exit(EXIT_SUCCESS);
}

int main() {
    signal(ALRM, sigalarm_handler);     // catch tín hiệu alarm
    
    alarm(1);
    while(1);
    return 0;
}