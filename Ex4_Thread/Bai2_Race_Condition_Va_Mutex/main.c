#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>

#define NUMBER_OF_THREADS   3
#define MAX_OF_COUNTER 1000000

pthread_t tid[NUMBER_OF_THREADS];   // lưu trữ thread id 1, 2 và 3
pthread_mutex_t counter_mutex;      // mutex - dùng để quản lý biến counter
int counter = 0;                    // dùng để đếm


static void *thread_inc(void *args) {
    pthread_t id = pthread_self();      // lấy ID của thread hiện tại

    for(int i = 0 ; i < MAX_OF_COUNTER; i++) {
        pthread_mutex_lock(&counter_mutex);

        counter++;
        
        pthread_mutex_unlock(&counter_mutex); // mở khóa

    } 

    return NULL;
}

int main() {
    int ret;    // return value

    pthread_mutex_init(&counter_mutex, NULL);  // khởi tạo mutex

    // tạo thread
    for(int index = 0 ; index < NUMBER_OF_THREADS ; index++) {
        ret = pthread_create(&tid[index], NULL, &thread_inc, NULL);   
    }

    // join thread
    for(int index = 0 ; index < NUMBER_OF_THREADS ; index++) {
        pthread_join(tid[index], NULL);  // nhận value exit của thread 
    }
    
    printf("Final, counter = %d\n", counter);
    return 0;
}