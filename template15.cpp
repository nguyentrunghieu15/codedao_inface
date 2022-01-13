/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <math.h>
#define MAXN 100

using namespace std;
struct PhanSo{
    int tu_so;
    int mau_so;
};
void Nhap(PhanSo a[], int &n){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].tu_so>>a[i].mau_so;
    }
}
int ucln(int a, int b){
    while(a!=b){
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
void Xuat(PhanSo a[], int n){
    for(int i=0;i<n;i++){
        if(a[i].mau_so==0)
            cout<<"Khong thoa yeu cau bai toan"<<endl;
        else if(a[i].tu_so==0)
            cout<<0<<endl;
        else{
            if((a[i].tu_so<0&&a[i].mau_so<0)||(a[i].tu_so>0&&a[i].mau_so>0)){
                if(abs(a[i].tu_so)%abs(a[i].mau_so)==0)
                    cout<<abs(a[i].tu_so)/abs(a[i].mau_so)<<endl;
                else
                    cout<<abs(a[i].tu_so)/ucln(abs(a[i].tu_so),abs(a[i].mau_so))<<"/"<<abs(a[i].mau_so)/ucln(abs(a[i].tu_so),abs(a[i].mau_so))<<endl;
            }
            else{
                if(abs(a[i].tu_so)%abs(a[i].mau_so)==0)
                    cout<<'-'<<abs(a[i].tu_so)/abs(a[i].mau_so)<<endl;
                else
                    cout<<"-"<<abs(a[i].tu_so)/ucln(abs(a[i].tu_so),abs(a[i].mau_so))<<"/"<<abs(a[i].mau_so)/ucln(abs(a[i].tu_so),abs(a[i].mau_so))<<endl;
            }
        }
    }
}
int main() {
    freopen("data.txt","r",stdin);
    PhanSo a[MAXN];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}

