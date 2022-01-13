#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAXN 1000
typedef struct date{
    int day;
    int month;
    int year;
}date;
typedef struct data{
    char code[11];
    date date_active;
    date date_end;
    int cost;
}data;
int n;
date Tinh_thoi_han(data A);
// void Nhap(data &a);
// void Nhap(data *A);
void Xuat(data A);
void Xuat(data *A);
void low_price(data *A);
void Thong_ke(data *A);
void swap(data &A,data &B);
void sort(data *A);
int main(){
    FILE *fp;
    fp= fopen("data.txt","r");
    // printf("Nhap so luong goi data:");
    fscanf(fp,"%d",&n);
    data *A;
    A=(data*)malloc(sizeof(data)*n);
    for(int i=0;i<n;i++){
    // printf("Goi thu %d\n",i+1);
    // printf("Nhap ma goi:");
    fscanf(fp,"%s",A[i].code);
    // printf("Nhap ngay kich hoat:");
    fscanf(fp,"%d%d%d",&A[i].date_active.day,&A[i].date_active.month,&A[i].date_active.year);
    // printf("Nhap ngay ket thuc:");
    fscanf(fp,"%d%d%d",&A[i].date_end.day,&A[i].date_end.month,&A[i].date_end.year);
    // printf("Nhap gia:");
    fscanf(fp,"%d",&A[i].cost);
    }
    // Nhap(A);
    fclose(fp);
    Xuat(A);
    low_price(A);
    Thong_ke(A);
    sort(A);
    getch();
    return 0;
}
// void Nhap(data &a){
//     printf("Nhap ma goi:");
//     fflush(stdin);fgets(a.code,11,fp);
//     printf("Nhap ngay kich hoat:");
//     fscanf(fp,"%d%d%d",&a.date_active.day,&a.date_active.month,&a.date_active.year);
//     printf("Nhap ngay ket thuc:");
//     fscanf(fp,"%d%d%d",&a.date_end.day,&a.date_end.month,&a.date_end.year);
//     printf("Nhap gia:");
//     fscanf(fp,"%d",&a.cost);
// }
// void Nhap(data *A){
//     for(int i=0;i<n;i++){
//         printf("Goi thu %d\n",i+1);
//         Nhap(A[i]);
//     }
// }
void Xuat(data A){
        printf("||%-12s|| %3d/%3d/%5d||%3d/%3d/%5d||%9d||\n",A.code,A.date_active.day,A.date_active.month,A.date_active.year,A.date_end.day,A.date_end.month,A.date_end.year,A.cost);
}
void Xuat(data *A){
    printf("Tat ca cac goi data:\n");
    printf("=========================================================\n");
    printf("||     MA     ||NGAY KICH HOAT||NGAY KET THUC||   GIA   ||\n");
    printf("=========================================================\n");
    for(int i=0;i<n;i++){
        Xuat(A[i]);
    }
    printf("=========================================================\n");
}
void low_price(data *A){
    printf("Goi data gia re:\n");
    int min_price=INT_MAX;
    for(int i=0;i<n;i++){
        if(A[i].cost<min_price)
            min_price=A[i].cost;
    }
    printf("=========================================================\n");
    printf("||     MA     ||NGAY KICH HOAT||NGAY KET THUC||   GIA   ||\n");
    printf("=========================================================\n");
    for(int i=0;i<n;i++){
        if(A[i].cost==min_price)
            Xuat(A[i]);
    }
    printf("=========================================================\n");
}
date Tinh_thoi_han(data A){
    date c;
    c.day=A.date_end.day-A.date_active.day;
    if(c.day<0){
        c.day+=30;
        A.date_active.month+1;
    }
    c.month=A.date_end.month-A.date_active.month;
    if(c.month<0){
        c.month+=12;
        A.date_active.year+1;
    }
    c.year=A.date_end.year-A.date_active.year;
    return c;
}
void Thong_ke(data *A){
    int max_thoihan=0;
    int min_thoihan=INT_MAX;
    int min_data;
    int max_data;
    int cout[3]={0,0,0};
    date *B;
    B=(date*)malloc(sizeof(date));
    for(int i=0;i<n;i++){
        B[i]=Tinh_thoi_han(A[i]);
    }
    for(int i=0;i<n;i++){
        int c=B[i].day+B[i].month*30+B[i].year*365;
        if(c>max_thoihan){
            max_thoihan=c;
            max_data=i;
        }
        if(c<min_thoihan){
            min_thoihan=c;
            min_data=i;
        }
        if(c<=30)
            cout[0]++;
        else if(c>=90)
            cout[2]++;
        else
            cout[1]++;
    }
    printf("Goi cuoc thoi han lau nhat:%s con %d ngay\n",A[max_data].code,B[max_data].day+B[max_data].month*30+B[max_data].year*365);
    printf("Goi cuoc sap het han:%s con %d ngay\n",A[min_data].code,B[min_data].day+B[min_data].month*30+B[min_data].year*365);
    printf("Theo thong ke co:\n\t\t\t- %.2f%% goi cuoc duoi 30 ngay\n\t\t\t- %.2f%% goi cuoc tren 30 ngay duoi 90 ngay\n\t\t\t- %.2f%% goi cuoc tren 90 ngay",100.0*cout[0]/n,100.0*cout[1]/n,100.0*cout[2]/n);
}
void swap(data &A, data &B){
    data c=B;
    B=A;
    A=c;
}
void sort(data*A){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && A[j-1].cost<A[j].cost){
            swap(A[j-1],A[j]);
            j--;
        }
    }
    printf("\nSau khi sap xep\n");
    Xuat(A);
}