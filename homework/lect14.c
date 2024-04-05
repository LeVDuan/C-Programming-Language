// Viết chương trình tạo ra tệp văn bản F3 từ việc ghép nội dung hai tệp văn bản F1 và F2.
// Viết một chương trình cho phép cắt hết chú thích của một chương trình C được lưu trữ trong một tệp. Tên tệp chương trình được nhập vào từ bàn phím. Giả thiết rằng chương trình không có lỗi cú pháp.
// Giả thiết một tệp dữ liệu thu thập về thời tiết trong một năm có định dạng theo mỗi dòng là:
// <ngày>/<tháng> <nhiệt độ thấp nhất>-<nhiệt độ cao nhất> <độ ẩm>
// 1/1 11-17 70
// 2/1 12-17 75
// ...
// Hãy viết chương trình đọc dữ liệu của tệp này và in ra nhiệt độ trung bình của các tháng trong năm, tháng khô hanh nhất và tháng ẩm ướt nhất.

#include <stdio.h>
#include <string.h>

int mergeFile(const char* fileName1, const char* fileName2) {
    FILE* fp1 = fopen(fileName1, "r");
    FILE* fp2 = fopen(fileName2, "r");
    FILE* output = fopen("F3.txt", "w+");
    char ch = fgetc(fp1);
    while(ch != EOF) {
        fputc(ch, output);
        ch = fgetc(fp1);
    }
    ch = fgetc(fp2);
    while (ch != EOF) {
        fputc(ch, output);
        ch = fgetc(fp2);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(output);
    return 0;
}

int skipCmtC(const char* srcFile) {
    FILE* f = fopen(srcFile, "a+t");
    if(f == NULL) {
        printf("Can't open this file!\n");
        return -1;
    }
    // char buff[100], src[10000];
    // while(fscanf(f,"%[^\n]", buff)) {
    //     printf("|%s|\n",buff);
    // }
    fclose(f);
    printf("\n");
    return 0;
}

int readWeatherNote(const char* srcFile) {
    return 0;
}

int main() {
    int chose = -1;
    while(1){
        printf("\n----------------------------------------------------------------------\n"
                       "1. Ghép hai tệp văn bản\n"
                       "2. Cắt chú thích trong mã nguồn C\n"
                       "3. Đọc ghi chú thời tiết\n"
                       "0. Thoát\n"
                       "Chose: ");
        scanf("%d",&chose);
        switch (chose) {
            case 0:
                printf("Exit ...\n");
                return 0;
            case 1:
                mergeFile("F1.txt", "F2.txt");
                break;
            case 2:
                skipCmtC("srcC.c");
                break;
            case 3:
                
                break;
            default:
                printf("Invalid!\n");
                break;
        }
        chose = -1;
    }
    return 0;
}