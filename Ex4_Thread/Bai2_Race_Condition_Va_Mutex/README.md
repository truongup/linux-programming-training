# Bài tập 2: Vấn đề "Race Condition" và Giải pháp Mutex

Bài tập này minh họa vấn đề "race condition" – một lỗi kinh điển trong lập trình
đa luồng – và giới thiệu Mutex (Mutual Exclusion) như một giải pháp cơ bản để
đảm bảo sự an toàn khi truy cập tài nguyên chia sẻ.

Yêu cầu:  
1. Viết chương trình khai báo một biến toàn cục `long long counter = 0;`.  
2. Tạo ra ba luồng. Mỗi luồng thực thi một vòng lặp để tăng giá trị của `counter`
   lên 1,000,000 lần.  
3. Sử dụng một `pthread_mutex_t` để bảo vệ thao tác tăng `counter`. Mỗi luồng
   phải khóa (lock) mutex trước khi tăng và mở khóa (unlock) ngay sau đó.  
4. Luồng chính dùng `pthread_join()` để đợi cả ba luồng hoàn thành, sau đó in
   ra giá trị cuối cùng của `counter`.

Câu hỏi phân tích:  
• Tại sao cần phải sử dụng mutex trong bài toán này?  
• Điều gì sẽ xảy ra nếu chúng ta bỏ qua việc sử dụng mutex? Giải thích tại
  sao kết quả cuối cùng có thể không chính xác và không ổn định.

<br>

# Giải thích:
1. Trong bài toán này chúng ta phải sử dụng mutex, vì:
   - Nếu không có mutex, thì các thread có thể truy cập gần như đồng thời vào biến Counter
   - Việc truy cập gần như đồng thời vào biến counter sẽ không thay đổi giá trị biến như mình mong muốn
   - Khi sử dụng Mutex, mà mutex đang bị lock thì bên thread khác phải đợi mutex được nhả ra

2. Nếu không dùng mutex, thì giá trị counter cuối cùng sẽ không bao giờ bằng được 3.000.000
   - Vì cùng một thời điểm sẽ có nhiều thread cùng truy cập vào tăng biến counter
   - Điều này sẽ làm cho biến counter không thực sự tăng theo số lượng thread

3. Dưới đây sẽ là đoạn code khi không dùng mutex
```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int counter = 0;
    
void *increase(void *args) {
    // lấy id thread
    pthread_t tid = pthread_self();
    
    for(int i = 0 ; i < 100000 ; i++) {
        printf("I'm thread, my tid = %d\n", (unsigned int)tid);
        counter++;
    }
    return NULL;
}

int main() {
    int ret;
    pthread_t tid[5];   // lưu trữ id của thread tạo ra
    
    // tạo thread
    printf("I'm main, counter = %d\n", counter);
    printf("I'm main, now i will creating thread...\n");
    for(int i = 0 ; i < 5 ; i++) {
        pthread_create(&tid[i], NULL, &increase, NULL);
    }
    
    // join thread
    for(int i = 0 ; i < 5 ; i++) {
        pthread_join(tid[i], NULL);
    }
    
    printf("AT THE END, Counter = %d\n", counter);
    
    return 0;
}
