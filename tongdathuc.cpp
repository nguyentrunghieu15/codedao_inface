/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include<iostream>
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
DATHUC Tong2DaThuc(DATHUC *A,DATHUC* B){
    DATHUC C;
    int couting=0;
    int i=0,j=0;
    while(i<A->n && j<B->n){
        if(A->so_mu[i]==B->so_mu[j]){
            C.so_mu[couting]=A->so_mu[i];
            C.he_so[couting]=A->he_so[i]+B->he_so[j];
            i++;
            j++;
        }
        else if(A->so_mu[i]<B->so_mu[j]){
            C.so_mu[couting]=B->so_mu[j];
            C.he_so[couting]=B->he_so[j];
            j++;
        }else{
            C.so_mu[couting]=A->so_mu[i];
            C.he_so[couting]=A->he_so[i];
            i++;
        }
        couting++;
    }
    while(i<A->n){
        C.so_mu[couting]=A->so_mu[i];
        C.he_so[couting]=A->he_so[i];
        i++;
        couting++;
    }
    while(j<B->n){
        C.so_mu[couting]=B->so_mu[j];
        C.he_so[couting]=B->he_so[j];
        j++;
        couting++;
    }
    C.n=couting;
    return C;
}
int main() {
    DATHUC *A, *B;
    A = Nhap();
    B = Nhap();
    cout << "Da thuc A: "; Xuat(*A);
    cout << "\nDa thuc B: "; Xuat(*B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}
