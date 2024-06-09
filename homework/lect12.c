#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int removeExtraSpacesStr(char *str) {
    int len, j = 0;
    len = strlen(str);

    for(int i = 0; i < len; i++) {
        if(!(str[i] == ' ' && str[i+1] == ' ')) {
            str[j++] = str[i];
        }
    }
    str[j] ='\0';
    return 0;
}

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

int wordCountStr(char *str) {
    removeExtraSpacesStr(str);
    int count = 1;
    for(int i = 1; i < strlen(str) - 1; i++) {
        if(str[i] == ' ' && str[i+1] != ' ') {
            count++;
        }
    }
    return count;
}


char* reverseStr(char *str) {
    removeExtraSpacesStr(str);
    int len = strlen(str);
    char *tmpStr = (char *)malloc(len*sizeof(char));
    strcpy(tmpStr, str);

    for(int i = 0; i < len; i++) {
        str[i] = tmpStr[len-1 - i];
    }

    free(tmpStr);
    return str;
}

typedef struct string {
    char string[50];
} string_t;

int separateWordStr(char *str, string_t *list){
    removeExtraSpacesStr(str);

    int words = wordCountStr(str);
    int len = strlen(str), j = 0;
    char *resStr = (char*)malloc(len*sizeof(char));
    char* result[words];

    result[j] = resStr;
    j++;
    for(int i = 0; i < len; i++) {
        resStr[i] = str[i];
        if(str[i - 1] == ' ') {
            resStr[i - 1] = '\0';
            result[j] = &(resStr[i]);
            j++;
        }
    }
    resStr[len] = '\0';
    strcpy(list[0].string,result[0]);
    strcpy(list[1].string,result[1]);
    strcpy(list[2].string,result[2]);

    free(resStr);
    return words;
}

int main() {
    int chose = -1, n;
    char str[100] = "Le   Văn  Duan";
    string_t list[50];
    printf("Nhập xâu: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    while(1){
        printf("\n----------------------------------------------------------------------\n"
                       "1. Cắt bỏ các dấu cách thừa trong một xâu\n"
                       "2. Đếm số từ hiện có trong một xâu\n"
                       "3. Đảo ngược xâu\n"
                       "4. Tách một xâu họ và tên thành hai xâu mới cho phần họ và phần tên\n"
                       "0. Thoát\n"
                       "Chose: ");
        scanf("%d",&chose);
        switch (chose) {
            case 0:
                printf("Exit ...\n");
                return 0;
            case 1:
                removeExtraSpacesStr(str);
                printf("kết quả bỏ các dấu cách thừa: |%s|\n", str);
                break;
            case 2:
                printf("Xâu \"%s\" có %d từ\n", str,wordCountStr(str));
                break;
            case 3:
                reverseStr(str);
                printf("Xâu đảo ngược là: |%s|",str);
                break;
            case 4:
                n = separateWordStr(str, list);
                for(int i = 0; i < n; i++) {
                    printf("\t%s\n",list[i].string);
                }
                break;
            default:
                printf("Invalid!\n");
                break;
        }
        chose = -1;
    }
    return 0;
}