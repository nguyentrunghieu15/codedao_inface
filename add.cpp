#include <iostream>

using namespace std;
void add(int* prt, int n, int k){
    *(prt+n)=k;
}
int main(){
    int arr[100]={1,2,3,4,5};
    int n=5;
    int k=7;
    add(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}