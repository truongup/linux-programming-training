#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void sigint_handler(int num_sig) {
    static int count_exit = 0;
    count_exit++;
    printf("SIGINT received\n");

    if(count_exit == 3) 
        exit(EXIT_SUCCESS);
}

int main() {
    signal(SIGINT, sigint_handler);     // catch tín hiệu interrupt
    while(1);
    return 0;
}