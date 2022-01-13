#include <bits/stdc++.h>
#define _max 1000
using namespace std;

typedef struct NV{
    int maNV;
    char hoten[100];
    char ngay[20];
}NV;
void Tao_DS(NV DS[], int &n){
    cout<<"Nhap so nv";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhan vien thu "<<i+1<<endl;
        cout<<"\t Ma nhan vien:";
        cin>>DS[i].maNV;
        cout<<"\t Ho ten:";
        cin>>DS[i].hoten;
        cout<<"\t Ngay vao cong ty(dd/mm/yyyy):";
        cin>>DS[i].ngay;
    }
}
void insert_head(NV DS[],int &n){
    for(int i=n-1;i>=0;i--){
        DS[i+1]=DS[i];
    }
    cout<<"Nhan vien can them "<<endl;
    cout<<"\t Ma nhan vien:";cin>>DS[0].maNV;
    cout<<"\t Ho ten:";cin>>DS[0].hoten;
    cout<<"\t Ngay vao cong ty (dd/mm/yyyy):\n";cin>>DS[0].ngay;
    n++;
}
void swap(NV &a, NV &b)
{
    NV t = a;
    a = b;
    b = t;
}
 
 
int partition (NV arr[], int low, int high)
{
    NV pivot = arr[high];
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left].maNV < pivot.maNV) left++;
        while(right >= left && arr[right].maNV > pivot.maNV) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
void quickSort(NV arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void delete_nv(NV arr[], int n , int x){
    for(int i=x;i<n;i++){
        if(i==n-1)
            break;
        else{
            arr[i]=arr[i+1];
        }
    }
}
bool check(char a[]){
    int n=strlen(a);
    char defaul[]="020101010";
    char b[20]="0";
    for(int i=n-1;i>=0;i--){
        char c[5];
        int couting=0;
        for(;a[i]!='/'&&i>=0;i--){
            c[couting]=a[i];
            couting++;
        }
        c[couting]='\0';
        strrev(c);
        strcat(b,c);
    }
    if(strcmp(b,defaul)<0)
        return true;
    else return false;
}
void inds(NV arr[], int n){
    for(int i=0;i<n;i++){
        printf("\n||%5d||%-30s||%-20s",arr[i].maNV,arr[i].hoten,arr[i].ngay);
    }
    cout<<endl;
}
void search_and_delete(NV arr[], int &n){
    for(int i=0;i<n;i++){
        if(check(arr[i].ngay)){
            delete_nv(arr,n,i);
            n--;
            i--;
        }
    }
}
int main(){
    int n;// so luong nhan vien
    NV DS[_max];
    Tao_DS(DS,n);
    inds(DS,n);
    insert_head(DS,n);
    inds(DS,n);
    quickSort(DS,0,n-1);
    inds(DS,n);
    search_and_delete(DS,n);
    inds(DS,n);
    return 0;
}
 