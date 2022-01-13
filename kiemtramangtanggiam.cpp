/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


#include <iostream>
#include <string.h>
#define MAXN 100
using namespace std;
void Input(int &n){
    cin>>n;
}
void NhapMang(int a[], int&n){
    for(int i=0;i<n;i++){
        int c;cin>>c;
        a[i]=c;
    }
}
int check_(int a, int b){
    if(a==b)
        return 0;
    else if(a<b)
        return 1;
    else return 2;
}
int KiemTra(int a[], int n){
    bool mem[3];
    memset(mem,1,sizeof(mem));
    int check[3];//0 bang 1 dong bien 2 nghich bien
    int couting=0;
    for(int i=0;i<n-1;i++){
        int c=check_(a[i],a[i+1]);
        if(mem[c]){
            check[couting]=c;
            couting++;
            mem[c]=false;
        }
    }
    if(couting==3)
        return -1;
    else if(couting==2){
        switch(check[0]+check[1]){
            case 3: return-1;break;
            case 1: return 0;break;
            case 2: return 1;break;
        }
    }else if(couting==1){
         switch(check[0]){
            case 0: return 2;break;
            case 1: return 0;break;
            case 2: return 1;break;
        }
    }
    return 9;
}
int main() {
    int a[MAXN], n, kt;
    Input(n);
    NhapMang(a, n);
    kt = KiemTra(a, n);
    if (kt == 0)
        std::cout << "Tang dan";
    else if (kt == 1)
        std::cout << "Giam dan";
    else if (kt == 2)
        std::cout << "Bang nhau";
    else
        std::cout << "Mang khong tang khong giam";
    return 0;
}
