#include <bits/stdc++.h>

using namespace std;
int recursiveSearch(int &n, int m, int arr[], int idex){
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==m){
            idex=i;
            flag=true;
            break;
        }
    }
    if(flag){
        for(int i=idex;i<n-1;i++){
        arr[i]=arr[i+1];
        n--;
        return idex;
    }else return -1;
}
int main(){

    return 0;
}