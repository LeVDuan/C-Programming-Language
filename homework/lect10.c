#include <stdio.h>

int nhapdayso(int a[]){
    int i = 0;
    while(1) {
        printf("\tNhập -1 để kết thúc nhập\n\tNhập phần tử thứ %d: ", i + 1);
        scanf("%d", &a[i]);
        if(a[i] == -1) {
            return i;
        }
        i++;
    }
    return i;
}

int timmax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if(a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int main() {
    int arr1[100], n1, arr2[100], n2;
    printf("Nhập mảng 1: \n");
    n1 = nhapdayso(arr1);
    printf("Nhập mảng 2: \n");
    n2 = nhapdayso(arr2);
    printf("Max array 1: %d\nMax array 2: %d\n", timmax(arr1, n1), timmax(arr2, n2));
    return 0;
}