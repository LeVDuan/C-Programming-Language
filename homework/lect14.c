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
typedef struct day {
    int day;
    int month;
} day_t;
char srcFileC[256];
day_t day[366];
int minTemp[366], maxTemp[366], humidity[366];

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

int delCmtC(const char* srcFile) {
    FILE* f = fopen(srcFile, "a+w");
    FILE* cf = fopen("copy.c", "w");
    if(f == NULL) {
        printf("Can't open this file!\n");
        return -1;
    }
    char buff[256];
    while (fscanf(f,"%[^\n]\n", buff) != EOF) {
        strcat(buff, "\n");
        // printf("%s", buff);
        for(int i = 0; i < strlen(buff); i++) {
            if(buff[i] == '/' && buff[i+1] == '/') {
                buff[i] = '\n';
                buff[i+1] = '\0';
            }
        }
        fputs(buff, cf);
        memset(buff,100, sizeof(char));
    }
    fclose(f);
    fclose(cf);
    remove(srcFile);
    rename("copy.c", srcFile);
    return 0;
}

int readWeatherNote(const char* logFile) {
    char buff[256];
    FILE *f = fopen(logFile, "r"); 
    if(f == NULL) {
        printf("Can't open this file\n");
        return -1;  
    }
    int i = 0;
    while(fscanf(f,"%d/%d %d-%d %d", &day[i].day, &day[i].month, &minTemp[i], &maxTemp[i], &humidity[i]) != EOF) {
        // printf("%d/%d %d-%d %d\n", day[i].day, day[i].month, minTemp[i], maxTemp[i], humidity[i]);
        i++;
    }
    return 0;
}

double monthTempAVG(int month) {
    double avg = 0;
    int count = 0;
    for(int i = 0; i < 366; i ++) {
        if(day[i].month == month) {
            count++;
            avg = avg + (double)(minTemp[i] + maxTemp[i])/2;
        }
    }
    // printf("%d - %lf - %lf\n", count, avg, avg/count);
    return avg/count;
}

int wetDriestMonth(int *wettest, int * driest) {
    double avgMonth[13];
    double wMonth = 0, dMonth = 0;
    memset(avgMonth, 13, sizeof(double));
    for(int month = 1; month < 13; month++) {
        int  count = 0;
        avgMonth[month] = 0;
        for(int i = 0; i < 366; i++) {
            if(day[i].month == month) {
                count++;
                avgMonth[month] = avgMonth[month] + (double)humidity[i];
            }
        }
        avgMonth[month] = avgMonth[month]/(double)count;
        printf("\t%d - count; %d - avg: %.3lf\n", month, count ,avgMonth[month]);

        if(avgMonth[month] > wMonth) {
            wMonth = avgMonth[month];
        }
        if(avgMonth[month] < dMonth || dMonth == 0) {
            dMonth = avgMonth[month];
        }
    }
    printf("\t\twet: %.3lf  dry: %.3lf\n", wMonth, dMonth);


    for(int month = 1; month < 13; month++) {
        if(avgMonth[month] == wMonth) {
            *wettest = month;
        }
        if(avgMonth[month] == dMonth) {
            *driest = month;
        }
    }
    return 0;
}

int main() {
    int chose = -1, wettestMonth, driestmonth;
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
                printf("\tNhập tên file nguồn C: ");
                scanf("%s", srcFileC);
                delCmtC(srcFileC);
                break;
            case 3:
                readWeatherNote("weatherLog.txt");
                for(int i = 1; i < 13; i++){
                    printf("\tNhiệt độ trung bình tháng %d: %.3lf\n", i, monthTempAVG(i));
                }
                wetDriestMonth(&wettestMonth, &driestmonth);
                printf("\tTháng hanh khô nhất là tháng %d\n\tTháng ẩm ướt nhất là tháng %d\n", driestmonth, wettestMonth);
                break;
            default:
                printf("Invalid!\n");
                break;
        }
        chose = -1;
    }
    return 0;
}