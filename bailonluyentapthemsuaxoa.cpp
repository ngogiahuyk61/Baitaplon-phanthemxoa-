// Them phan tu vao mang 1 chieu 
#include <stdio.h>
#include<string.h>
#define MAX 1000
void NhapMang(int a[], int n){
    for(int i = 0;i < n; i++){
        printf("\n	Nhap stt san pham %d: ", i);
        scanf("%d", &a[i]);
    }
}
void XuatMang(int a[], int n){
    for(int i = 0;i<n;i++){
        printf("%4d", a[i]);
    }
}
void ThemPhanTu(int a[], int &n, int val, int pos){
	fflush(stdin);
    if(n >= MAX){
        return;
    }
    if(pos < 0){
        pos = 0;
    }
    else if(pos > n){
        pos = n;
    }
    for(int i = n; i > pos; i--){
        a[i] = a[i-1];
    }
    a[pos] = val;
    ++n;
} 
void XoaPhanTu(int a[], int &n, int pos){
    if(n <= 0){
        return;
    }
    if(pos < 0){
        pos = 0;
    }
    else if(pos >= n){
        pos = n-1;
    }
    for(int i = pos; i < n - 1; i++){
        a[i] = a[i+1];
    }
    --n;
}
void Menu(){
	int chon, flat=1;
	while(flat){
		printf("\n1. Nhap so luong san pham.\n");
		printf("\n2. Them so luong san pham.\n");
		printf("\n3. Xoa bot so luong san pham.\n");
		printf("\n4. Thoat.\n");
		scanf("%d", &chon);
		switch(chon){
			case 1:
				int a[MAX],n;
				fflush(stdin); 
				printf("Nhap so luong san pham: ");
				scanf ("%d", &n);
				NhapMang(a,n);
				printf("\nSo  san pham la:");
				XuatMang(a, n);
				break;
			case 2:
				int val, pos;
				printf("\nNhap so  can them: ");
				scanf("%d", &val);
				printf("\nNhap vi tri muon them: ");
    			scanf("%d", &pos);
    			ThemPhanTu(a, n, val, pos);
    			printf("\nBill sau khi them: ");
    			XuatMang(a, n);
    			break;
			case 3:
				printf("\nNhap vi tri muon xoa san pham: ");
    			scanf("%d", &pos);
    			XoaPhanTu(a, n, pos);
    			printf("\nBill sau khi xoa san pham: ");
   				XuatMang(a, n);
    			printf("\nDone!");
				break;
			case 4:
				flat=0;		
		}
	}
}
int main(){	
	Menu();
}
