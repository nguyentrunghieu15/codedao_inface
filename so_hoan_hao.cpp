#include <iostream>
#include<math.h>
using namespace std;

bool check_so_hoan_hao(int n){
    int c=n-1;
    if(sqrt(n)==(int)sqrt(n))
        c-=(int)sqrt(n);
    for(int i=2;i<sqrt(n);i++){
            if(n%i==0){
                int a=n/i;
                c-=i;
                c-=a;
            }
    }
    if(c==0)
        return true;
    else   return false;
}
int main(){
    int n;
    cin>>n;
    cout<<check_so_hoan_hao(n);
    return 0;
}