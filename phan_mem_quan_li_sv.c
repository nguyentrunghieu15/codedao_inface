#include <stdio.h>

typedef struct sinhvien{
    char hoten[30];
    char que[20];
    float toan;
    float li;
    float hoa;
}sinhvien;
int main(){
    int n;
    printf("Nhap so luong hoc sinh:");scanf("%d",&n);
    sinhvien Hs[100];
    for(int i=0;i<n;i++){
        printf("Nhap thong tin hoc sinh thu %d:\n",i+1);
        printf("Nhap ho ten:");fflush(stdin);gets(Hs[i].hoten);
        printf("Nhap que:");fflush(stdin);gets(Hs[i].que);
        printf("diem toan:");scanf("%f",&Hs[i].toan);
        printf("diem li:");scanf("%f",&Hs[i].li);
        printf("diem hoa:");scanf("%f",&Hs[i].hoa);
    }
    printf("Thong tin sinh vien vua nhap la:\n");
    for(int i=0;i<n;i++){
        printf("%-30s %-20s %f %f %f\n",Hs[i].hoten,Hs[i].que,Hs[i].toan,Hs[i].li,Hs[i].hoa);
    }
    printf("Nhap diem chuan:");
    float A;scanf("%f",&A);
    printf("danh sach sinh vien do\n");
    for(int i=0;i<n;i++){
        if(Hs[i].toan+Hs[i].li+Hs[i].hoa>=A&&Hs[i].toan>1&&Hs[i].li>1&&Hs[i].hoa>1){
            printf("%-30s %-20s %f %f %f\n",Hs[i].hoten,Hs[i].que,Hs[i].toan,Hs[i].li,Hs[i].hoa);
        }
    }
    printf("danh sanh sinh vien toan lon hon 9\n");
    for(int i=0;i<n;i++){
        if(Hs[i].toan>=9){
            printf("%-30s %-20s %f %f %f\n",Hs[i].hoten,Hs[i].que,Hs[i].toan,Hs[i].li,Hs[i].hoa);
        }
    }
}