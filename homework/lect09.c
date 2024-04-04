#include <stdio.h>

int nhapso(){
    int a;
    printf("Nhập một số: ");
    scanf("%d",&a);
    return a;
}

int max(int a, int b) {
    if( a > b) {
        return a;
    } else return b;
}

int main() {
    int a, b, c;
    a = nhapso();
    b = nhapso();
    c = nhapso();

    printf("Max: %d\n", max(max(a,b), c));

    return 0;
}