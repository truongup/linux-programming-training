# Bài tập 1: Tạo và Chạy Luồng Cơ bản

## Yêu cầu

Viết một chương trình bắt tín hiệu **SIGINT** (được gửi khi nhấn `Ctrl+C`) và in ra thông báo khi nhận được tín hiệu này.

### Các bước thực hiện

1. Sử dụng hàm `signal()` để đăng ký một hàm xử lý cho tín hiệu **SIGINT**.
2. Trong hàm xử lý, in ra thông báo **"SIGINT received"** mỗi khi nhận được tín hiệu SIGINT.
3. Chương trình sẽ tiếp tục chạy cho đến khi nhận được SIGINT lần thứ **3**, sau đó kết thúc.

> Gợi ý: Sử dụng một biến đếm toàn cục để đếm số lần tín hiệu SIGINT được nhận và kiểm tra biến này trong hàm xử lý.

## Câu hỏi

**Nếu bỏ qua tín hiệu SIGINT, chuyện gì sẽ xảy ra khi nhấn Ctrl+C?**
