# Bài tập 2: Sử dụng Tín hiệu SIGALRM để Tạo Timer

## Yêu cầu

Viết chương trình tạo một bộ đếm thời gian bằng cách sử dụng tín hiệu **SIGALRM**.

### Các bước thực hiện

1. Sử dụng hàm `alarm()` để đặt thời gian kích hoạt SIGALRM mỗi giây.
2. Khi nhận tín hiệu SIGALRM, chương trình sẽ tăng biến đếm và in ra dòng:
   **"Timer: <giây> seconds"**.
3. Dừng chương trình sau khi đếm đến **10 giây**.

> Gợi ý: Sử dụng `signal()` để đăng ký xử lý tín hiệu SIGALRM, và đặt `alarm(1)` để bộ đếm lặp lại hằng giây.

## Câu hỏi

**Điều gì xảy ra nếu không gọi lại `alarm(1)` trong hàm xử lý?**

<br>

# Giải thích
- Bản chất hàm alarm(...) nó chỉ set một lần, ví dụ alarm(5) tức là 5 giây, sau 5 giây thì coi như xong.
- Vì vậy nếu không đặt alarm(1) trong hàm xử lý, thì nó chỉ gọi đến đó 1 lần
- Và chương trình sẽ bị treo nếu không exit phù hợp