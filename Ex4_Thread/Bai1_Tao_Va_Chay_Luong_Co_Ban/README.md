# Bài tập 1: Tạo và Chạy Luồng Cơ bản

Bài tập này giới thiệu các thao tác nền tảng nhất với luồng: tạo một luồng thực
thi mới từ luồng chính và chờ đợi luồng đó hoàn thành.

## Yêu cầu

1. Viết một chương trình C tạo ra hai luồng.
2. Mỗi luồng, khi bắt đầu thực thi, sẽ in ra một chuỗi thông báo kèm theo ID
   của nó (ví dụ: "Thread với ID `<thread_id>` đang chạy!").
3. Luồng chính phải sử dụng hàm `pthread_join()` để đợi cả hai luồng con kết
   thúc hoàn toàn trước khi chương trình chính kết thúc.

## Câu hỏi phân tích

- Giải thích vai trò và các tham số chính của hàm `pthread_create()` và
  `pthread_join()`.
- Một luồng kết thúc khi nào?

<br>

# Giải thích:

## Hàm `pthread_create()`

```c
int pthread_create(
    pthread_t *threadID, 
    const pthread_attr_t *attr, 
    void *(*start)(void *), 
    void *arg
);

Mô tả các đối số của `pthread_create`

- **Đối số đầu tiên**: Một khi tiến trình được gọi thành công, đối số đầu tiên sẽ giữ thread ID của thread mới được tạo.

- **Đối số thứ hai**: Thông thường giá trị này đặt thành `NULL`.

- **Đối số thứ ba**: Là một con trỏ hàm (function pointer). Mỗi một thread sẽ chạy riêng một function, địa chỉ của function này sẽ được truyền tại đối số thứ ba để linux biết được thread này bắt đầu chạy từ đâu.

- **Đối số thứ tự**: Đối số `arg` được truyền vào có kiểu `void`, điều này cho phép ta truyền bất kỳ kiểu dữ liệu nào vào hàm xử lý của thread. Hoặc giá trị này có thể là `NULL` nếu ta không muốn truyền bất cứ đối số nào. Điều này sẽ được thể hiện rõ ràng hơn trong ví dụ dưới đây.

- **Giá trị trả về**: Return về `0` nếu thành công, một số dương khi lỗi.
```

<br>

## Hàm `pthread_join()`

```c
int pthread_join(pthread_t thread, void **retval);

- pthread_join() sẽ block cho đến khi một thread kết thúc
- thread_id sẽ được truyền vào đối số thread để xác định là sẽ catch thread nào
```

<br>

## Một Luồng Kết Thúc Khi Nào ?
  - Có bốn cách để kết thúc
    - Gọi exit(...) kết thúc toàn bộ thread và process mình gọi
    - Kết thúc bình thường không tác động gì
    - Kết thúc chủ động với hàm `pthread_exit()`
    - Kết thúc thụ động, là main kết thúc thread `pthread_cancle()`
