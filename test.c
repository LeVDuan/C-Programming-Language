#include <stdio.h>
#include <string.h>


char* catDauCachThua(char* str) {
    int i = 0, len = strlen(str);
    int k = len-1;
    while(str[k] == ' ') {
        k--;
    }
    while(str[i] == ' ') {
        i++;
    }
    str[k+1] = '\0';
    str+=i;


    len =  strlen(str);
    k = 0;
    int isSpace = 0;
    char tmp[len];

    for(i = 0; i < len; i ++) {
        if(str[i] != ' ') {
            isSpace = 0;
            tmp[k] = str[i];
            k++;
        } else {
            isSpace++;
            if(isSpace == 1) {
                tmp[k] = ' ';
                k++;
            }
        }
    }
    tmp[k] = '\0';
    strcpy(str, tmp);
    // printf("'%s'\n", result);
    return str;

}

int main() {

    char name[100] = "   Le    Duan   Hai  Nguyen    Duong    ";
    printf("'%s'", catDauCachThua(name));
    return 0;
};