#include <iostream>

using namespace std;
#define ll long long
ll D(int n,ll A[]){
    if(A[n]!=0){
        return A[n];
    }
    switch(n){
        case 0: return 0;
        case 1: return 1;
        case 2: return 2;
        case 3: return 4;
        default:{A[n]=D(n-1,A)+D(n-2,A)+D(n-3,A);
                    return A[n];
                  }
    }
}

int main(){
    int n;cin>>n;
    ll* A= new ll[n+1];
    cout<<D(n,A);
    return 0;
}
