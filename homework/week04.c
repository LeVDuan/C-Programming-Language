#include <stdio.h>
#include <string.h>
#define PI 3.14159
void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int Bai1(){
    double r = 0;
    printf("Bài 1: Tính diện tích và chu vi Hình tròn\nNhập bán kính: ");
    scanf("%lf",&r);
    printf("Diện tích: %.3lf\nChu vi: %.3lf\n", PI*r*r, 2*PI*r);
    return 1;
}

int Bai2(){
    double c = 0, f = 0;
    int mode;
    while(1) {
        printf("Bài 2: Chuyển đổi nhiệt độ\n"  
                   "1. C -> F\n"
                   "2. F -> C\n"
                   "Chọn chế độ: \n");
        scanf("%d",&mode);
        if( mode == 1) {
            printf("Nhập nhiệt độ celsius: ");
            scanf("%lf",&c);
            f = c * 1.8 + 32;
            printf("Nhiệt độ Fahrenheit: %.3lf\n", f);
            return 1;
        } else if( mode == 2) {
            printf("Nhập nhiệt độ fahrenheit: ");
            scanf("%lf",&f);
            c = (f -32) / 1.8;
            printf("Nhiệt độ celsius: %.3lf\n", c);
            return 1;
        } else {

            printf("Invalid mode!\n");
        }
    }
    
    return 1;
}

int Bai5(){
    
    int n = 0;
    printf("Bài 5: Tính Tổng và Trung Bình Của Dãy Số\nNhập số n: ");
    scanf("%d",&n);
    int sum = (n + 1)*n/2;
    double avg = (n + 1)/2;
    printf("Tổng: %d\nTrung bình: %.3lf\n", sum, avg);
    return 1;    
}

int Bai7(){
    int day, month, year;
    printf("Bài 7: Định dạng Ngày Tháng\nNhập \"ngày tháng năm\": ");
    scanf("%d %d %d", &day, &month, &year);
    printf("%d/%d/%d\n", day, month, year);
    return 1;  
}

int Bai8(){
    int second, minute, hour;
    printf("Bài 7: Định dạng Thời gian\nNhập số (0~86400): ");
    scanf("%d", &second);
    hour = second/3600;
    minute = (second - hour*3600)/60;
    second = second - hour*3600 - minute*60;
    printf("%d:%d:%d\n", hour, minute, second);
    return 1;
}

int Bai9(){
    printf("Bài 9: In số dưới dạng bảng: ");
    int i, j;
    for(i = 1; i <= 5; i++) {
        for(j = 1; j <= 5; j++) {
            printf("%2d ", i*j);
        }
        printf("\n");
    }
    return 1;
}

int Bai10(){
    printf("Bài 10: Định dạng đầu ra sản phẩm\n");
    char name[40], price[30];
    printf("Tên sản phẩm: ");
    clearBuffer();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Giá: ");
    // clearBuffer();
    fgets(price, sizeof(price), stdin);
    price[strcspn(price, "\n")] = '\0';
    printf("-------------------------------\n");
    printf("%-30s%-20s\n","Ten san pham", "Gia");
    printf("%-30s%-20s\n",name, price);
}

int Bai11(){
    printf("Bài 11: In thông tin sinh viên\n");
    char name[40], code[10];
    double avg;
    
    printf("Tên sinh viên: ");
    clearBuffer();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Mã sinh viên: ");
    // clearBuffer();
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';

    printf("Điểm trung bình: ");
    scanf("%lf", &avg);

    printf("----------------------------------------------------\n");
    printf("%-20s%-20s%-20s\n","Ten sinh vien", "Ma sinh vien", "Diem trung binh");
    printf("%-20s%-20s%-20.3lf\n", name, code, avg);
    return 1;
}

int Bai12(){
    printf("Bài 12: Định dạng bảng lương nhân viên\n");
    char name[40];
    int workHour, salaryPerHour;
    double sumSalary;
    
    printf("Nhập tên nhân viên: ");
    clearBuffer();
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Nhập số giờ làm: ");
    scanf("%d", &workHour);

    printf("Nhập lương mỗi giờ: ");
    scanf("%d",&salaryPerHour);

    sumSalary = workHour * salaryPerHour;
    printf("----------------------------------------------------\n");
    printf("%-20s%-20s%-20s%-20s\n", "Ten nhan vien", "So gio lam", "Luong moi gio", "Tong luong");
    printf("%-20s%-20d$%-20d$%-20.0lf\n", name, workHour, salaryPerHour, sumSalary);
}


int main() {
    int chose = -1; 
    while(1){
        printf("Chose excercise (1~12, 0 to exit): ");
        scanf("%d",&chose);
        switch (chose) {
            case 0:
                printf("Exit ...\n");
                return 0;
            case 1:
                Bai1();
                break;
            case 2:
                Bai2();
                break;
            case 5:
                Bai5();
                break;
            case 7:
                Bai7();
                break;
            case 8:
                Bai8();
                break;
            case 9:
                Bai9();
                break;
            case 10:
                Bai10();
                break;
            case 11:
                Bai11();
                break;
            case 12:
                Bai12();
                break;
            default:
                printf("Invalid!\n");
                break;
        }
        chose = -1;

    }
    return 0;
}