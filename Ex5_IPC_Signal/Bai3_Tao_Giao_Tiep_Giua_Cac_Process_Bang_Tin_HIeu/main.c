#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

void sigusr1_handler(int num_sig) {
    static int count = 0;
    printf("Received signal from parent...\n");
    count++;
    
    if(count == 5)
        exit(EXIT_SUCCESS); // EXIT_SUCCESS = 0
    
}

int main() {
    int status;

    // tạo process con
    int child_pid = fork();

    if(child_pid == 0) {
        // đăng ký signal user1 trong child process
        signal(SIGUSR1, sigusr1_handler);

        printf("I'm child process, my pid = %d...\n", getpid());
        
        while(1);   // nếu không có while này process con sẽ bị kết thúc sớm
    }

    else if(child_pid > 0) {
        printf("I'm parent process, my pid = %d...\n", getpid());

        for(int i = 0 ; i < 5 ; i++) {
            // mỗi 2 giây gửi tín hiệu
            sleep(2);
            kill(child_pid, SIGUSR1);
        }

        wait(&status);
        printf("I'm parent process, status exit is: %d\n", status);
    }
    return 0;
}