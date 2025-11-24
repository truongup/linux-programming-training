#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

pthread_t tid1, tid2;   // lưu trữ thread id 1 và 2

void *thread_handler(void *args) {
    pthread_t cur_tid = pthread_self();     // lấy id thread

    if(pthread_equal(cur_tid, tid1) == 1) {
        // đây là thread 1
        printf("I'm thread 1, my id: %lu\n", (unsigned long)cur_tid);

        int *exit_1 = malloc(1 * sizeof(int));
        *exit_1 = 100;
        pthread_exit(exit_1);
    }

    else {
        printf("I'm thread 2, my id: %lu\n", (unsigned long)cur_tid);

        int *exit_2 = malloc(1 * sizeof(int));
        *exit_2 = 200;
        pthread_exit(exit_2);

    }
}

int main() {
    int ret;    // return value


    // Tạo thread 1
    ret = pthread_create(&tid1, NULL, &thread_handler, NULL);
    if(ret) {
        printf("Error when creating thread 1 ...\n");
        return -1;
    }

    // Tạo thread 2
    ret = pthread_create(&tid2, NULL, &thread_handler, NULL);
    if(ret) {
        printf("Error when creating thread 2 ...\n");
        return -1;
    }

    // Main thread
    pthread_t main_id = pthread_self();
    printf("I'm main thread, my id: %lu\n", (unsigned long) main_id);

    int *status_exit1 = NULL;
    pthread_join(tid1, (void **)&status_exit1);  // nhận value exit của thread 1

    int *status_exit2 = NULL;
    pthread_join(tid2, (void **)&status_exit2);   // nhận value exit của thread 2

    printf("Thread 1, value exit = %d\n", *status_exit1);
    printf("Thread 2, value exit = %d\n", *status_exit2);

    free(status_exit1);
    free(status_exit2);

}