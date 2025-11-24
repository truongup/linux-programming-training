#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
	/*	lưu trong stack frame */
	int status = 0;

	// tạo child process, hàm này trả về pid của process con
	int ret = fork();
	
	// process con
	if(ret == 0) {
		printf("I'm child process, my pid is %d\n", getpid());
		exit(10);	// thoát process con
	}
	
	// process cha
	else {
		printf("I'm parent process, my pid is %d\n", getpid());
		printf("I'm parent process, my child pid is %d\n", ret);
		
		wait(&status);	// đợi child process trả về
		
		// nếu child process kết thúc 1 cách bình thường: WIFEXITED
		if(WIFEXITED(status)) {
			printf("I'm parent process, status exit of child process is: %d\n", WEXITSTATUS(status)); 
		}
	}
	
	return 0;
}
