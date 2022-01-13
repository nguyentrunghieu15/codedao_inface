/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <cmath>
#define MAXN 100

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << "\t";
}
bool check( int n){
    if(n<=1)
        return false;
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return false;
    return true;
}
void ChenSauSoNguyenToDauTien(int a[],int &n ,int X)
{
    if(n>=MAXN)
        return;
    else{
        for(int i=0;i<n;i++){
            if(check(a[i])){
                if(a[i+1]==X)
                    return;
                else{
                    for(int j=n;j>i+1;j--)
                        a[j]=a[j-1];
                        a[i+1]=X;
                        n++;
                        return;
                }
            }
        }
    }
}
int main() {
    int a[MAXN], n, X;
    std::cin >> X;
    NhapMang(a, n);
    ChenSauSoNguyenToDauTien(a, n, X);
    XuatMang(a, n);
    return 0;
}
