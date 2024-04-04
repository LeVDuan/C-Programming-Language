#include <stdio.h>

int Bai1() {
    int n, i = 2, flag = 0;
    printf("Nhập số nguyên N: ");
    scanf("%d",&n);
    printf("%d = ", n);
    while (n > 1) {
        if (n % i == 0) {
            if(flag == 0) {
                printf("%d", i);
                flag = 1;
            } else {
                printf(" x %d", i);
            }
            n /= i;
        } else {
            i++;
        }
    }
    printf("\n");
    return 0;
}

// Hàm kiểm tra số nguyên tố
int isPrime(int n) {
    if (n <= 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

int Bai2() {
    int n, nextPrime;
    printf("Nhập số nguyên N: ");
    scanf("%d",&n);
    printf("Số nguyên tố đầu tiên lớn hơn %d là: ", n);
    if(n <= 0) {
        n = 1;
    }
    nextPrime = n + 1;
    while(isPrime(nextPrime) == 0) {
        nextPrime = n + 1;
    }
    printf("%d\n", nextPrime);
    return 0;
}

int Bai3() {
    double PI = 0, tmp = 0, flag = 0;
    printf("PI/4 = ");
    for(long i = 1; i < 1000000000; i+=2) {
        if(flag == 0) {
            tmp = tmp + 1/(double)i;
            if(i < 12){
                printf(" + 1/%ld", i);
            }
            flag = 1;
        } else if(flag == 1) {
            tmp = tmp - 1/(double)i;
            if(i < 12) {
                printf(" - 1/%ld", i);
            }
            flag = 0;
        }
    }
    PI = tmp * 4;
    printf(" + ...\nPI = %lf\n", PI);
    printf("\n");
    return 0;
}

int main() {
     int chose = -1; 
    while(1){
        printf("1. In ra tích của các thừa số nguyên tố của một số\n"
                       "2. In ra số nguyên tố đầu tiên lớn hơn một giá trị N\n"
                       "3. Tính số PI theo công thức: PI/4 = 1-1/3+1/5-1/7+1/9-1/11+...\n"
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