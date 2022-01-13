/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

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
    for(int i=0;i<B.n;i++){
        if(B.he_so[i]!=0){
            mem=false;
            if(i!=0&&B.he_so[i]>0)
                cout<<'+';
            if(B.so_mu[i]==0)
                cout<<B.he_so[i];
            else{
                if(B.he_so[i]!=1&&B.he_so[i]!=-1)
                    cout<<B.he_so[i];
                else if(B.he_so[i]==-1)
                    cout<<'-';
                cout<<'x';
                if(B.so_mu[i]!=1)
                    cout<<'^'<<B.so_mu[i];
            }
        }
    }
    if(mem)
        cout<<0;
}
void Tong2DaThuc(phantu* A, int n, phantu* B, int m){
    phantu *C;
    C=new phantu[m+n];
    int couting=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(A[i].so_mu==B[j].so_mu){
            C[couting].so_mu=A[i].so_mu;
            C[couting].he_so=A[i].he_so+B[j].he_so;
            i++;
            j++;
        }
        else if(A[i].so_mu<B[j].so_mu){
            C[couting].so_mu=B[i].so_mu;
            C[couting].he_so=B[j].he_so;
            j++;
        }else{
            C[couting].so_mu=A[i].so_mu;
            C[couting].he_so=A[i].he_so;
            i++;
        }
        couting++;
    }
    while(i<n){
        C[couting].so_mu=A[i].so_mu;
        C[couting].he_so=A[i].he_so;
        i++;
        couting++;
    }
    while(j<n){
        C[couting].so_mu=B[i].so_mu;
        C[couting].he_so=B[i].he_so;
        i++;
        couting++;
    }
    Xuat(C,couting);
}
int main() {
    int n,m;
    phantu *A;
    phantu *B;
    A=nhap_da_thuc(n);
    B=nhap_da_thuc(m);
    cout << "Da thuc A: "; Xuat(A,n);
    cout << "\nDa thuc B: "; Xuat(B,m);
    cout << "\nA+B = "; Tong2DaThuc(A,n,B,m);
    return 0;
}
