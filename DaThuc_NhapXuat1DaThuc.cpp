/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;

struct DATHUC{
    double he_so[100];
    int so_mu[100];
    int n;
};
DATHUC* Nhap(){
    DATHUC* p=new DATHUC;
    cin>>p->n;
    for(int i=0;i<p->n;i++){
        cin>>p->he_so[i]>>p->so_mu[i];
    }
    return p;
}

void Xuat(DATHUC B){
    bool mem =true;
    int couting=0;
    for(int i=0;i<B.n;i++){
        if(B.he_so[i]!=0){
            mem=false;
            if(couting!=0&&B.he_so[i]>0)// dau
                cout<<'+';
            if(B.he_so[i]<0)
                cout<<'-';
            if(abs(B.he_so[i])!=1){ //he so
                    cout<<abs(B.he_so[i]);
            }
            else{
                if(B.so_mu[i]==0)
                    cout<<1;
            }
            if(B.so_mu[i]>0)//so mu
            {
                cout<<'x';
                if(B.so_mu[i]>1)
                    cout<<'^'<<B.so_mu[i];
            }
            couting=1;
        }
    }
    if(mem)
        cout<<0;
}
double TinhDaThuc(DATHUC B,double x){
    double slove=0;
    for(int i=0;i<B.n;i++){
        slove+=B.he_so[i]*pow(x,B.so_mu[i]);
    }
    return slove;
}
int main() {
    DATHUC *B; B = Nhap();
    cout << "Da thuc vua nhap la: "; Xuat(*B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(*B, x);
    return 0;
}
