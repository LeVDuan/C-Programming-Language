#include <stdio.h>

int Bai1() {
    for(int i = 1; i <= 9; i++) {
        printf("%d%d\t",i, 10 - i);
    }
    printf("\n");
    return 0;
}

int Bai2() {
    long long int a1 = 1, a2 = 2, a3 = 0;
    printf("%lld %lld ", a1, a2);
    for(int i = 0; i < 100; i++) {
        a3 = a2 + a1;
        printf("%lld ", a3);

        a1 = a2;
        a2 = a3;
    }
    printf("\n");
    return 0;
}

int Bai3() {
    int n;
    printf("Nhập số nguyên n (1~9): ");
    scanf("%d",&n);
    if( 0 < n && n < 10) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                printf("%d",j);
            }
            printf("\n");
        }
    }
    return 0;
}

int main() {
     int chose = -1; 
    while(1){
        printf("1. In các số có 2 chữ số có tổng là 10\n"
                       "2. In 100 số đầu tiên của dãy số sau: 1 2 3 5 8 13 21...\n"
                       "3. In ra một tam giác với số nguyên n\n"
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
            case 3:
                Bai3();
                break;
            default:
                printf("Invalid!\n");
                break;
        }
        chose = -1;

    }
    return 0;
}