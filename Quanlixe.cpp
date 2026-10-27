#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Quanlixe {
    char ma[5];
    char tenxe[50];
    float gia;
    int soluongton;
};

void Danhsachxe(struct Quanlixe ds[], int n);
void Giaodich(struct Quanlixe ds[], int n, float *doanhthu);
void Tonkho(struct Quanlixe ds[], int n);
void Doanhthu(float doanhthu);

int main() {
	int n = 10;
    struct Quanlixe ds[n] = {
    	//phothong
        {"1", "Honda Wave Alpha 110", 19500000, 30},
        {"2", "Honda Future 125 FI", 31500000, 15},
        {"3", "Yamaha Sirius", 22000000, 30},
        {"4", "Yamaha Exciter 155 VVA", 50000000, 25},
        //nu
        {"5", "Honda SH Mode 125", 64000000, 20},
        {"6", "Honda Vision 110", 32000000, 25},
        //nam
        {"7", "Honda Vario (125cc)", 41000000, 30},
        {"8", "Honda Air Blade (125cc)", 42400000, 25},
        //xedien
        {"9", "VinFast Evo200", 18800000, 15},
        {"10", "VinFast Vento S", 49200000, 15}
    };
    float doanhthu = 0;
    int chon = 0;
    do {
        printf("=======ENGREN=======\n");
        printf("                                               1. Danh sach xe cua hang\n");
        printf("                                               2. Quay giao dich\n");
        printf("                                               3. Ton kho \n");
        printf("                                               4. Xem doanh thu\n");
        printf("                                               5. Thoat\n");
        printf("                                               Nhap lua chon: ");
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                Danhsachxe(ds, n);
                break;
            case 2:
                Giaodich(ds, n, &doanhthu);
                break;
            case 3:
                Tonkho(ds, n);
                break;
            case 4:
                Doanhthu(doanhthu);
                break;
            case 5:
                printf("Hen gap lai quy khach!");
                break;
            default:
                printf("Lua chon khong hop le!");
        }
        getchar();
        if (chon != 5) {
            printf("\n\nNhan Enter de quay lai menu...");
            getchar();
        }
        else {
		printf("\nChuc Quy khach mot ngay tot lanh!!!");
		}
    } while (chon != 5);
    return 0;
}

//void random

void Danhsachxe(struct Quanlixe ds[], int n) {
    printf("\t====== ENGREN ======\n");
    printf("MA\t|\tTEN XE                    \t\t|\tGIA\t        |\tTON KHO\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t|\t%-30s\t\t|\t%.2f\t|\t%d\n",
               ds[i].ma,
               ds[i].tenxe,
               ds[i].gia,
               ds[i].soluongton);
    }
}

void Giaodich(struct Quanlixe ds[], int n, float *doanhthu) {
    char ma[5];
    int soluong = 0;
    int timthay = 0;
    printf("===== BAN SAN PHAM =====\n");
    printf("Nhap ma san pham: ");
    scanf("%s", ma);
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma, ma) == 0) {
            timthay = 1;
            printf("San pham: %s\n", ds[i].tenxe);
            printf("Gia: %.2f VND\n", ds[i].gia);
            printf("Ton kho: %d\n", ds[i].soluongton);
            printf("Nhap so luong ban: ");
            scanf("%d", &soluong);
            if (soluong <= 0) {
                printf("So luong ban khong hop le!");
            }
            else if (soluong > ds[i].soluongton) {
                printf("Khong du hang trong kho!");
            }
            else {
                ds[i].soluongton -= soluong;
                *doanhthu += ds[i].gia * soluong;
                //system("cls");
                printf("Ban hang thanh cong!\n");
                printf("Thanh tien: %.2f VND\n",
                       ds[i].gia * soluong);
                printf("Ton kho con lai: %d\n",
                       ds[i].soluongton);
            }
            break;
        }
    }
    if (!timthay) {
        printf("Khong tim thay san pham co ma: %s", ma);
    }
}

void Tonkho(struct Quanlixe ds[], int n) {
    printf("===== TON KHO =====\n");
    for (int i = 0; i < n; i++) {
        printf("%-15s : %d\n",
               ds[i].tenxe,
               ds[i].soluongton);
    }
}
void Doanhthu(float doanhthu) {
    printf("===== DOANH THU =====\n");
    printf("Tong doanh thu: %.2f VND\n", doanhthu);
}
	 