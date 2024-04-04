#include <stdio.h>

int Bai1() {
    printf("1. Tìm giá trị lớn nhất trong 3 số nguyên\n");
    int a, b, c;
    printf("Nhập 3 số nguyên: ");
    scanf("%d %d %d", &a, &b, &c);

    if(a > b) {
        if( a > c) printf("Max: %d\n", a);
        else printf("Max: %d\n", c);
    } else {
        if( b > c) printf("Max: %d\n", b);
        else printf("Max: %d\n", c);
    }
    return 0;
}

int Bai2() {
    printf("Giải phương trình ax + b = 0\n");
    double a, b, result;
    printf("Nhập a: ");
    scanf("%lf", &a);
    printf("Nhập b: ");
    scanf("%lf", &b);

    if(a == 0) {
        if(b == 0) printf("Phương trình có vô số nghiệm\n");
        else printf("Phương trình vô nghiệm\n");
    } else {
        result = -b/a;
        printf("Phương trình có 1 nghiệm: x = %.3lf\n", result);
    }
    return 0;
}

int main() {
    int chose = -1; 
    while(1){
        printf("1. Tìm giá trị lớn nhất trong 3 số nguyên\n"
                       "2. Giải phương trình ax + b = 0\n"
                       "0. Thoát\n"
                       "Chose excercise: ");
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
            default:
                printf("Invalid!\n");
                break;
        }
        chose = -1;

    }
    return 0;
}