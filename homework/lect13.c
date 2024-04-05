// •Một phân số được biểu diễn bằng một cấu trúc gồm hai trường tử số 
// và mẫu số 
// •Viết hàm cho phép nhập giá trị cho một phân số
// •Viết hàm hiển thị một phân số ra màn hình
// •Xây dựng các hàm để tính một phân số rút gọn, tổng, hiệu, tích, 
// thương của hai phân số 
// •Viết một chương trình để thử nghiệm các hàm đã xây dựng với hai 
// phân số được nhập vào, sau đó tính tổng, hiệu, tích và thương của 
// chúng.

#include <stdio.h>

typedef struct PhanSo {
    int tuSo;
    int mauSo;
} phanSo_t;

void inPhanSo(phanSo_t ps) {
    printf("\t\t%d\n", ps.tuSo);
    printf("\t\t—\n");
    printf("\t\t%d\n", ps.mauSo);
}

int nhapPhanSo(phanSo_t* ps) {
    printf("\tNhập tử số: ");
    scanf("%d",&(*ps).tuSo);
    printf("\tNhập mẫu số: ");
    scanf("%d", &(*ps).mauSo);

    inPhanSo(*ps);
    return 0;
}

int UCLN(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b; 
        } else {
            b -= a; 
        }
    }
    return a; 
}

int phanSoRutGon(phanSo_t *ps) {
    int ucln = UCLN((*ps).tuSo, (*ps).mauSo);
    (*ps).tuSo = (*ps).tuSo/ucln;
    (*ps).mauSo = (*ps).mauSo/ucln;
    return 0;
}

phanSo_t tong(phanSo_t *ps1,phanSo_t *ps2) {
    phanSo_t sum;
    phanSoRutGon(ps1);
    phanSoRutGon(ps2);
    sum.tuSo = (*ps1).tuSo*(*ps2).mauSo + (*ps1).mauSo*(*ps2).tuSo;
    sum.mauSo = (*ps1).mauSo * (*ps2).mauSo;
    phanSoRutGon(&sum);
    return sum;
}

phanSo_t hieu(phanSo_t *ps1,phanSo_t *ps2) {
    phanSo_t diff;
    phanSoRutGon(ps1);
    phanSoRutGon(ps2);
    diff.tuSo = (*ps1).tuSo*(*ps2).mauSo - (*ps1).mauSo*(*ps2).tuSo;
    diff.mauSo = (*ps1).mauSo * (*ps2).mauSo;
    phanSoRutGon(&diff);
    return diff;
}


phanSo_t tich(phanSo_t *ps1,phanSo_t *ps2) {
    phanSo_t pro;
    phanSoRutGon(ps1);
    phanSoRutGon(ps2);
    pro.tuSo = (*ps1).tuSo * (*ps2).tuSo;
    pro.mauSo = (*ps1).mauSo * (*ps2).mauSo;
    phanSoRutGon(&pro);
    return pro;
}

phanSo_t thuong(phanSo_t *ps1,phanSo_t *ps2) {
    phanSo_t quo;
    phanSoRutGon(ps1);
    phanSoRutGon(ps2);
    quo.tuSo = (*ps1).tuSo * (*ps2).mauSo;
    quo.mauSo = (*ps1).mauSo * (*ps2).tuSo;
    phanSoRutGon(&quo);
    return quo;
}

int main() {
    int chose = -1;
    phanSo_t ps1, ps2, sum, diff, pro, quo;
    while(1){
        printf("\n----------------------------------------------------------------------\n"
                       "1. Nhập hai phân số\n"
                       "2. Tính phân số rút gọn\n"
                       "3. Tính tổng hai phân số\n"
                       "4. Tính hiệu hai phân số\n"
                       "5. Tính tích hai phân số\n"
                       "6. Tính thương hai phân số\n"
                       "0. Thoát\n"
                       "Chose: ");
        scanf("%d",&chose);
        switch (chose) {
            case 0:
                printf("Exit ...\n");
                return 0;
            case 1:
                printf("Nhập phân số thứ nhất: \n");
                nhapPhanSo(&ps1);
                printf("Nhập phân số thứ hai: \n");
                nhapPhanSo(&ps2);
                break;
            case 2:
                phanSoRutGon(&ps1);
                phanSoRutGon(&ps2);
                printf("Phân số sau rút gọn: \n Phân số 1: \n");
                inPhanSo(ps1);
                printf("Phân số 2: \n");
                inPhanSo(ps2);
                break;
            case 3:
                sum = tong(&ps1, &ps2);
                printf("Tổng hai phân số là: \n");
                inPhanSo(sum);
                break;
            case 4:
                diff = hieu(&ps1, &ps2);
                printf("Hiệu hai phân số là: \n");
                inPhanSo(diff);
                break;
            case 5:
                pro = tich(&ps1, &ps2);
                printf("Tích hai phân số là: \n");
                inPhanSo(pro);
                break;
            case 6:
                quo = thuong(&ps1, &ps2);
                printf("Thương hai phân số là: \n");
                inPhanSo(quo);
                break;
            default:
                printf("Invalid!\n");
                break;
        }
        chose = -1;
    }
    return 0;
}