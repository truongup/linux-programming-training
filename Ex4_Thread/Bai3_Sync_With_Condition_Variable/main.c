#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TIMES 10    // số lần lặp lại
int limit_box = 0;
int box = 0;
int flag_ready = 0;

pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;    // condition varibale
pthread_mutex_t lock;                               // mutex - dùng để quản lý biến counter

pthread_t producer_id, consumer_id;                 // thread id

static void *producer(void *args) {
    for(int times = 0 ; times < TIMES ; times++) {

        // while này sẽ chờ cho đến khi thằng consumer trả flag về 0 với bắt đầu vào lock mutex
        while(flag_ready != 0);

        printf("I'm producer, my thread id is: %lu\n", (unsigned long)pthread_self());

        // Lưu ý: Yêu cầu của bài toán là producer phải cung cấp đủ 10 box
        // Thì consumer mới được lấy
        pthread_mutex_lock(&lock);
        printf("\nI'm producer, I lock mutex\n");

        while(box < limit_box) {
            box++;
            printf("I'm producer, numbers of box provided: %d\n", box);
            sleep(1);
        }

        flag_ready = 1;                  // báo là đã sẵn sàng

        pthread_cond_signal(&cond); // gửi signal trước để consumer sẵn sàng take lock mutex
        printf("I'm producer, I send condition variable signal\n");

        pthread_mutex_unlock(&lock); // mở khóa
        printf("I'm producer, I unlock mutex\n\n");
    }

    pthread_exit(NULL);
}


static void *consumer(void *args) {
    for(int times = 0 ; times < TIMES ; times++) {
        limit_box = (rand() % 10) + 1;  // limit [1 - 10]

        printf("TIMES: %d, limit box: %d \n", times + 1, limit_box);
        printf("I'm consumer, my thread id is: %lu\n", (unsigned long)pthread_self());

        // Quy tắc khi dùng condition variable đó là trước khi gọi pthread_cond_wait thì mutex phải bị lock
        pthread_mutex_lock(&lock);
        printf("I'm consumer, I lock mutex (First)\n");

        while(flag_ready == 0) {
            // khi gọi pthread_cond_wait sẽ gọi pthread_mutex_unlock
            // và sẽ chờ cho đến khi có signal 
            printf("I'm consumer, I unlock mutex (First)\n");

            pthread_cond_wait(&cond, &lock); 
        }

        printf("I'm consumer, I lock mutex (Second)\n");

        printf("I'm consumer, I get box: %d\n", box);

        box = 0;
        limit_box = 0;
        

        pthread_mutex_unlock(&lock); // mở khóa
        printf("I'm consumer, I unlock mutex (Second)\n");

        flag_ready = 0;  // reset cho vòng sau

        printf("\n --------------------------------------- \n\n");
    }

    pthread_exit(NULL);
}
int main() {
    // khởi tạo mutex
    pthread_mutex_init(&lock, NULL);                               
    
    // tạo thread
    int ret;
    ret = pthread_create(&consumer_id, NULL, &consumer, NULL);
    ret = pthread_create(&producer_id, NULL, &producer, NULL);          
    

    /**
        flag_ready = 0
    */
    pthread_join(producer_id, NULL);
    pthread_join(consumer_id, NULL);

    return 0;
}