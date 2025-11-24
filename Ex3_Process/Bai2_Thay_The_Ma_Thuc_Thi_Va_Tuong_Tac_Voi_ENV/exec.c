#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define IS_CHILD_PROCESS 0  // dùng để xác định phải process con không

int main() {
    int status; // status trả về của process con

    // thiết lập biến môi trường
    char env_cmd[25];
    printf("Please, set enviroment variable: ");
    scanf("%s", env_cmd);   // ví dụ: ls, date, ...

    setenv("MY_CMD", env_cmd, 0);   // set biến env

    pid_t child_id = fork(); // tạo một tiến trình con


    // nếu tạo process con thành công
    if(child_id >= 0) {
        if(child_id == IS_CHILD_PROCESS) {
            // nếu là process con
            printf("I'm child process, my PID is: %d\n", getpid());


            printf("I'm child process, before call exec\n");    // trước khi gọi system call exec

            execlp(env_cmd, env_cmd, NULL);

            printf("I'm child process, after call exec\n");    // trước khi gọi system call exec
            exit(100);
        }

        else {
            // nếu là process cha
            printf("I'm parent process, my PID is: %d\n", getpid());

            // đợi status process con trả về
            wait(&status);

            printf("I'm parent process, my status recv is: %d\n", WEXITSTATUS(status));

        }
    }

    // tạo process con thất bại
    else {
        return -1;
    }

    unsetenv("MY_CMD");   // un-set biến env
    return 0;
}