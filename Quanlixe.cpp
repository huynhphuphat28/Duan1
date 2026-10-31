#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Quanlixe {
	//tieu chuan
    char ma[5];
    char tenxe[50];
    float gia;
    int soluongton;
    
    // Thong so ky thuat
    char dongco[150];
    char congsuat[100];
    char momen[100];
    char hopso[100];
    char nhienlieu[100];
    char dungtich[50];
    char trongluong[50];
    char chieucao[50];
    char kichthuoc[100];

    // Thong so rieng cua xe dien
    char pin[100];
    char quangduong[100];
    char thoigiansac[100];
    char vantoc[50];
};

void Canhbaotonkho(struct Quanlixe ds[], int n);
void Danhsachxe(struct Quanlixe ds[], int n);
void Giaodich(struct Quanlixe ds[], int n, float *doanhthu);
void Tonkho(struct Quanlixe ds[], int n);
void Doanhthu(float doanhthu);
void Thongtinkhachhang();

int main() {
	int n = 10;
	srand((unsigned int)time(NULL));
    
    struct Quanlixe ds[n] = {
        // Xe ban chay
        {
            "1", "Honda Wave Alpha 110", 19500000, 30,
            "Xang, 4 ky, 1 xi-lanh, lam mat bang khong khi, 109.2 cc",
            "6.12 kW tai 7500 vong/phut",
            "8.44 Nm tai 5500 vong/phut",
            "Co khi, 4 so tron",
            "Khoang 1.72 lit/100 km",
            "3.7 lit", "96 kg", "770 mm",
            "1913 x 689 x 1076 mm",
            "Khong co", "Khong ap dung",
            "Khong ap dung", "Khong ap dung"
        },

        {
            "2", "Honda Future 125 FI", 31500000, 15,
            "Xang, 4 ky, 1 xi-lanh, lam mat bang khong khi, PGM-FI",
            "6.83 kW tai 7500 vong/phut",
            "10.2 Nm tai 5500 vong/phut",
            "Co khi, 4 so tron",
            "Khoang 1.47 lit/100 km",
            "4.6 lit", "104 kg", "756 mm",
            "1931 x 711 x 1083 mm",
            "Khong co", "Khong ap dung",
            "Khong ap dung", "Khong ap dung"
        },

        {
            "3", "Yamaha Sirius", 22000000, 30,
            "SOHC, 4 thi, 2 van, lam mat bang khong khi, 110.3 cc",
            "5.9 kW tai 8000 vong/phut",
            "9.5 Nm tai 5500 vong/phut",
            "Co khi, 4 so tron",
            "Khoang 2.08 lit/100 km",
            "4.2 lit", "96 - 100 kg", "770 mm",
            "1890 x 665 x 1035 mm",
            "Khong co", "Khong ap dung",
            "Khong ap dung", "Khong ap dung"
        },

        {
            "4", "Yamaha Exciter 155 VVA", 50000000, 25,
            "4 thi, 4 van, SOHC, VVA, lam mat bang dung dich, 155.1 cc",
            "13.2 - 13.6 kW tai 9500 vong/phut",
            "14.4 Nm tai 8000 - 8500 vong/phut",
            "Co khi, 6 cap",
            "Khoang 2.07 - 2.09 lit/100 km",
            "5.4 lit", "120 - 124 kg", "795 mm",
            "1975 x 665 x 1085 - 1100 mm",
            "Khong co", "Khong ap dung",
            "Khong ap dung", "Khong ap dung"
        },

        // Xe tay ga nu
        {
            "5", "Honda SH Mode 125", 64000000, 20,
            "eSP+ 4 van, 4 ky, 1 xi-lanh, lam mat bang chat long, phun xang dien tu",
            "8.2 kW tai 8500 vong/phut",
            "11.7 Nm tai 5000 vong/phut",
            "Tu dong, vo cap",
            "Khoang 2.12 - 2.16 lit/100 km",
            "5.6 lit", "116 kg", "765 mm",
            "1950 x 668 x 1110 mm",
            "Khong co", "Khong ap dung",
            "Khong ap dung", "Khong ap dung"
        },

        {
            "6", "Honda Vision 110", 32000000, 25,
            "eSP, 4 ky, 1 xi-lanh, lam mat bang khong khi, PGM-FI, Idling Stop",
            "6.59 kW tai 7500 vong/phut",
            "9.29 Nm tai 6000 vong/phut",
            "Tu dong, vo cap",
            "Khoang 1.85 - 1.87 lit/100 km",
            "4.9 lit", "94 - 98 kg",
            "761 mm (ban tieu chuan) / 785 mm (ban the thao)",
            "1871 x 686 x 1101 mm (ban tieu chuan); 1925 x 686 x 1126 mm (ban the thao)",
            "Khong co", "Khong ap dung",
            "Khong ap dung", "Khong ap dung"
        },

        // Xe tay ga nam
        {
            "7", "Honda Vario (125cc)", 41000000, 30,
            "eSP, 4 ky, 2 van, SOHC, lam mat bang chat long, PGM-FI",
            "8.19 kW tai 8500 vong/phut",
            "10.79 - 10.8 Nm tai 5000 vong/phut",
            "Tu dong, vo cap",
            "Khoang 1.9 - 2.16 lit/100 km",
            "5.5 lit", "111 - 113 kg", "769 mm",
            "1918 x 679 x 1066 mm",
            "Khong co", "Khong ap dung",
            "Khong ap dung", "Khong ap dung"
        },

        {
            "8", "Honda Air Blade (125cc)", 42400000, 25,
            "eSP+ 4 van, 4 ky, 1 xi-lanh, lam mat bang chat long, PGM-FI",
            "8.75 kW tai 8500 vong/phut",
            "11.3 Nm tai 6500 vong/phut",
            "Tu dong, vo cap",
            "Khoang 2.12 lit/100 km",
            "4.4 lit", "110 - 111 kg", "775 mm",
            "1884 x 686 x 1085 mm",
            "Khong co", "Khong ap dung",
            "Khong ap dung", "Khong ap dung"
        },

        // Xe dien
        {
            "9", "VinFast Evo200", 18800000, 15,
            "Dong co Inhub dat tai banh sau",
            "1500 W danh dinh, 2500 W cuc dai",
            "Tai lieu khong cung cap",
            "Tai lieu khong neu",
            "Khong su dung xang",
            "Khong co binh xang", "100 kg", "750 mm",
            "1804 x 683 x 1127 mm",
            "Pin LFP, 3.5 kWh",
            "Khoang 203 - 205 km/lan sac",
            "Khoang 10 gio (sac 400W), 4 gio (sac nhanh 1000W)",
            "70 km/h"
        },

        {
            "10", "VinFast Vento S", 49200000, 15,
            "Side Motor (dong co ben)",
            "5200 W toi da",
            "Tai lieu khong cung cap",
            "Tu dong, vo cap",
            "Khong su dung xang",
            "Khong co binh xang", "122 kg", "780 mm",
            "1863 x 691 x 1100 mm",
            "Pin LFP, 3.5 kWh",
            "Khoang 160 km/lan sac",
            "Khoang 6 gio",
            "89 km/h"
        }
    };

    float doanhthu = 0;
    int chon = 0;
    do {
    	Canhbaotonkho(ds,n);
        printf("         ******** <<<ENGREN>>>  *******\n");
        printf("           |1. Danh sach xe cua hang|\n");
        printf("           |------------------------|\n");
        printf("           |2. Quay giao dich       |\n");
        printf("           |------------------------|\n");
        printf("           |3. Ton kho              |\n");
        printf("           |------------------------|\n");
        printf("           |4. Xem doanh thu        |\n");
        printf("           |------------------------|\n");
        printf("           |5. Thoat                |\n");
        printf("           |------------------------|\n");
        printf("           Nhap lua chon: ");
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
	


void randomqua() {
   
    const char *Danhsachqua[] = {
        "Tai nghe",
        "Mu bao hiem",
        "Voucher giam gia",
        "The cao đien thoai"
    };
    int soluongqua = sizeof(Danhsachqua) / sizeof(Danhsachqua[0]);
    int indexngaunhien = rand() % soluongqua;
    printf("Chuc mung! Ban da trung : %s\n", Danhsachqua[indexngaunhien]);
    
   
}

void KiemtrasoRandom() {
    int mangrandom[5];
    int Y = 0;
    int sonhap=0;
	printf("Quy khach vui long chon 1 so tu 1-100:");
	scanf("%d",&sonhap); 
	if (sonhap>=1&&sonhap<=100){
	

    //printf("5 so ngau nhien duoc tao ra la: ");
    for (int i = 0; i < 5; i++) {
        mangrandom[i] = 1 + rand() % 100;
        //printf("%d ", mangrandom[i]);

        if (mangrandom[i] == sonhap) {
            Y = 1;
        }
    }
    printf("\n");
     printf("--- BAT DAU QUAY SO NGAU NHIEN ---\n");
    if (Y == 1) {
        printf("Chuc mung! So %d ban nhap da trung thuong\n", sonhap);randomqua();
		
    } else {
        printf("Rat tiec! Ban khong nhan duoc phan thuong\n", sonhap);
    }
}
else ("Ban khong muon mang qua ve à!!");

}
	


void Thongsoxe(struct Quanlixe ds[], int n) {
    char ma[5];
    int thongso = 0;

    printf("\n===== XEM THONG SO KY THUAT =====\n");
    printf("Nhap ma xe muon xem (1 - 10): ");
    scanf("%4s", ma);

    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma, ma) == 0) {
            thongso = 1;

            printf("\n========================================\n");
            printf("       THONG SO KY THUAT CUA XE\n");
            printf("========================================\n");

            printf("Ma xe: %s\n", ds[i].ma);
            printf("Ten xe: %s\n", ds[i].tenxe);

            printf("\n--- THONG SO DONG CO ---\n");
            printf("Dong co: %s\n", ds[i].dongco);
            printf("Cong suat cuc dai: %s\n", ds[i].congsuat);
            printf("Mo-men xoan cuc dai: %s\n", ds[i].momen);
            printf("Hop so: %s\n", ds[i].hopso);

            printf("\n--- NHIEN LIEU / NANG LUONG ---\n");
            printf("Nhien lieu: %s\n", ds[i].nhienlieu);
            printf("Dung tich binh xang: %s\n", ds[i].dungtich);

            printf("\n--- KICH THUOC VA TRONG LUONG ---\n");
            printf("Trong luong: %s\n", ds[i].trongluong);
            printf("Chieu cao yen: %s\n", ds[i].chieucao);
            printf("Kich thuoc (D x R x C): %s\n", ds[i].kichthuoc);

            // Thong tin rieng cua xe dien
            if (strcmp(ds[i].ma, "9") == 0 ||
                strcmp(ds[i].ma, "10") == 0) {

                printf("\n--- THONG SO PIN VA VAN HANH ---\n");
                printf("Loai pin: %s\n", ds[i].pin);
                printf("Quang duong: %s\n", ds[i].quangduong);
                printf("Thoi gian sac: %s\n", ds[i].thoigiansac);
                printf("Van toc toi da: %s\n", ds[i].vantoc);
            }

            printf("\nGia ban tai cua hang: %.0f VND\n", ds[i].gia);
            printf("So luong ton kho: %d chiec\n", ds[i].soluongton);

            printf("========================================\n");
            break;
        }
    }

    if (thongso == 0) {
        printf("\nKhong tim thay ma xe!\n");
    }
}

void Danhsachxe(struct Quanlixe ds[], int n) {
	system("cls");
    printf("\t             ==<<===< <<<ENGREN>>> >====>>==\n");
    printf("MA\t|\tTEN XE                    \t\t|\tGIA\t        |\tTON KHO\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t|\t%-30s\t\t|\t%.2f\t|\t%d\n",
               ds[i].ma,
               ds[i].tenxe,
               ds[i].gia,
               ds[i].soluongton);
    }
    char xem;
    printf("\nBan co muon xem thong so ky thuat khong? (C/K): ");
    scanf(" %c", &xem);
    if (xem == 'C' || xem == 'c') {
        Thongsoxe(ds, n);}
    
}

void Giaodich(struct Quanlixe ds[], int n, float *doanhthu) {
    char ma[5];
    int soluong = 0;
    int timthay = 0;
    char nhap[100];
    char *ketThuc;
    printf("===== BAN SAN PHAM =====\n");
    printf("Nhap ma san pham: ");
    scanf("%s", ma);
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].ma, ma) == 0) {
            timthay = 1;
            printf("San pham: %s\n", ds[i].tenxe);
			printf("Nhap so luong ban: ");

             do {
                scanf("%99s", nhap);

                long soLuongNhap = strtol(nhap, &ketThuc, 10);

                if (ketThuc == nhap || *ketThuc != '\0' ||soLuongNhap <= 0 || soLuongNhap > 100) {getchar();printf("So luong khong hop le! Vui long nhap lai: ");
				}
                else {
                    soluong = (int)soLuongNhap;
                    break;}

} while (1);
            
            
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
                system("cls");
                printf("Ban hang thanh cong!\n Chuc mung quy khach da so huu chiec %s\n",ds[i].tenxe);
                printf("Thanh tien: %.2f VND\n",
                       ds[i].gia * soluong);
                printf("Ton kho con lai: %d\n",
                       ds[i].soluongton);
                       KiemtrasoRandom();
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
void Canhbaotonkho(struct Quanlixe ds[], int n) {
    for (int i = 0; i < n; i++) {
        if (ds[i].soluongton < 5) {
            printf("\n*** CANH BAO: %s sap het hang! Con %d chiếc!!!! ***\n",
                   ds[i].tenxe,
                   ds[i].soluongton);
        }
    }
}
	 