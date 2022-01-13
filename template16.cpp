/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

//###INSERT CODE HERE -
#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;

struct phantu{
    double he_so;
    int so_mu;
};
void nhap_da_thuc(phantu dathub[], int n){
    for(int i=0;i<n;i++){
        cin>>dathub[i].he_so>>dathub[i].so_mu;
    }
}
void Xuat(phantu *dathub, int n){
    bool mem =true;
    for(int i=0;i<n;i++){
        if(dathub[i].he_so!=0){
            mem=false;
            if(dathub[i].he_so!=1&&dathub[i].he_so!=-1)
                cout<<dathub[i].he_so;
            if(dathub[i].he_so==-1)
                cout<<"-";
        if(dathub[i].so_mu>=1){
            cout<<"x";
            if(dathub[i].so_mu!=1){
                cout<<"^"<<dathub[i].so_mu;
            }
        }
        }
        if(i<n-1&&dathub[i+1].he_so>0)
            cout<<'+';
    }
    if(mem)
        cout<<0;
}
double TinhDaThuc(phantu dathub[], int n,double x){
    double slove=0;
    for(int i=0;i<n;i++){
        slove+=dathub[i].he_so*pow(x,dathub[i].so_mu);
    }
    return slove;
}
int main() {
    int n;cin>>n;
    phantu dathub[n];
    nhap_da_thuc(dathub,n);
    cout << "Da thuc vua nhap la: "; Xuat(dathub,n);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed <<TinhDaThuc(dathub,n,x);
    return 0;
}
