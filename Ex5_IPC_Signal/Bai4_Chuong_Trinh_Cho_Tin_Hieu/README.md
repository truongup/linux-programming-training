# Bài tập 4: Chương trình chờ tín hiệu kết hợp chờ người dùng nhập liệu

## Yêu cầu

Viết một chương trình có thể nhận tín hiệu đồng thời cho phép người dùng nhập liệu từ bàn phím.

### 1. Cơ chế chờ nhiều nguồn vào

- Sử dụng `select()` **hoặc** `poll()` để:
  - Cho phép chương trình vừa chờ tín hiệu,
  - Vừa nhận dữ liệu nhập từ bàn phím,
  - Mà **không bị gián đoạn** khi đang đọc dữ liệu.

### 2. Xử lý tín hiệu SIGINT

- Khi chương trình nhận tín hiệu `SIGINT` (ví dụ nhấn `Ctrl + C`),
- In ra thông báo:
  ```text
  SIGINT received.
