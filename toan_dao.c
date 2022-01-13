#include <stdio.h>
#include <math.h>

double S1(double x, int n){//ham thu nhat
    double S=0;
    for(int i=0;i<n;i++){
        S+=sqrt(S+x);
    }
    return S;
}
double S2(double x, int n){//ham 2
    double c=x;
    double S=1;
    for(int i=1;i<=n;i++){
        S+=c/i;
        c*=x;
    }
    return S;
}
double S3(double x, int n){//ham 3
    double c=x;
    double S=1;
    int giaithua=1;
    for(int i=1;i<=n;i++){
        S+=c/giaithua;
        c*=x;
        giaithua*=(1+i);
    }
    return S;
}
double S4(double x, int n){//ham 4
    double c=x;
    double S=1;
    int giaithua=1;
    for(int i=1;i<=n;i++){
        S+=(i%2==0?1:-1)*c/giaithua;
        c*=x;
        giaithua*=(1+i);
    }
    return S;
}
int main(){
    double x;
    int n;
    printf("Nhap x:");scanf("%lf",&x);
    printf("Nhap n:");scanf("%d",&n);
    printf("Ket Qua ham 1:%lf\n",S1(x,n));
    printf("Ket Qua ham 1:%lf\n",S2(x,n));
    printf("Ket Qua ham 1:%lf\n",S3(x,n));
    printf("Ket Qua ham 1:%lf\n",S4(x,n));
}