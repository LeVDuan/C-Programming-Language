#include <stdio.h>
#include <stdio_ext.h>
typedef struct item {
    char    code[15];
    char    name[40];
    double price;
}item_t;

void printMenu(item_t* menu, int number){
    printf( "=======================MENU=========================\n");
    printf("%-20s %-20s %-20s\n", "Dish code", "Dish", "Price");
    printf("%-20s %-20s %-20s\n", "_________", "____", "_____");

    for(int i = 0; i < number; i++) {
        printf("%-20s %-20s %-20.2lf\n", menu[i].code, menu[i].name, menu[i].price);
    }

}
int main() {
    int number, i; // number of dishes on the menu
    FILE *fp = fopen("./menu.txt", "r");
    if(fp == NULL) {
        printf("Can't open this file\n");
        return -1;
    }
    fscanf(fp,"%d", &number);
    item_t menu[number];
    for(i = 0; i < number; i++){
        fscanf(fp,"%s %s %lf", menu[i].code, menu[i].name, &menu[i].price);
    }
    printMenu(menu, number);
    return 0;
}