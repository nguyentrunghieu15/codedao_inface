#include <iostream>
#include<algorithm>
using namespace std;
int N, K, B;

void input(int a[]){
    for(int i=1;i<=B;i++){
        cin>>a[i];
    }
}
void min_led(int arr[]){
    int min_l=N;
    for(int i=1;i<=B;i++){
        for(int j=0;j<i;j++){
            if(arr[i]-arr[j]-1>=K){
                min_l=min(i-j-1,min_l);
            }
            else break;
        }
    }
    cout<<min_l;
}
int main(){
    freopen("data.txt","r",stdin);
    cin>>N>>K>>B;
    int arr[B+3];
    arr[0]=0;
    arr[B+1]=N+1;
    input(arr);
    sort(arr+1,arr+B+1);
    min_led(arr);
    return 0;
}