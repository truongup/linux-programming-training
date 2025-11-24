#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define IS_CHILD_PROCESS 0  // dùng để xác định phải process con không

int main() {
    pid_t child_id = fork();    // tạo process con

    // nếu tạo process con thành công
    if(child_id >= 0) {
        if(child_id == IS_CHILD_PROCESS) {
            // nếu là process con
            printf("I'm child process, my PID is: %d\n", getpid());
            exit(100);
        }

        else {
            // nếu là process cha
            printf("I'm parent process, my PID is: %d\n", getpid());
            sleep(10);  // process cha ngủ trong thời gian 10s
        }
    }

    // tạo process thất bại
    return 0;
}