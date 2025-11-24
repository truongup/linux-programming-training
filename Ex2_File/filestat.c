#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void print_type_file(mode_t st_mode) {
    printf("TYPE: ");

    if (S_ISLNK(st_mode)) {
        printf("Symbolic link\n");
    }
        
    else if (S_ISREG(st_mode)) {
        printf("Regular file\n");
    }
        
    else if (S_ISDIR(st_mode)) {
        printf("Directory\n");
    }       
}

int main(int argc, void *argv[]) {
    // Nếu không có tham số nào được cung cấp, hãy in ra hướng dẫn sử dụng (ví dụ: Usage: ./filestat <file_path>) và thoát.
    if(argc != 2) {
        // bởi vì main là 1 đối số khi chạy chương trình
        // nên nếu mình có truyền thêm đối số thì phải là từ 2 trở lên
        printf("Usage: ./filestat <file_path> \n");
        return -1;
    }


    struct stat info_stat;   // struct chứa thông tin lấy được
    
    int ret = lstat(argv[1], &info_stat);

    if(ret == 0) {
        // đọc file thành công

        print_type_file(info_stat.st_mode);
        printf("SIZE: %ld bytes\n", info_stat.st_size);

        char timebuf[100];
        struct tm *tminfo = localtime(&info_stat.st_mtime);
        strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tminfo);
        printf("Last Modified: %s\n", timebuf);
    }

    return 0;
}