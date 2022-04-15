#include <bits/stdc++.h>

using namespace std;
bool checkDuplicate(int* arr , int size){
    int *p=arr;
    if(size==0)
        return true;
    else{
        for(int i=1;i<size;i++){
            if(*arr==*(p+i))
                return false;
        }
        return checkDuplicate(arr+1,size-1);
    }

}
int main(){
    int* arr;
    int n=5;
    arr =new int[5];
    arr[0]=1;arr[1]=2;arr[2]=3;arr[3]=4;arr[4]=2;
    if(checkDuplicate(arr,0)){
        cout<<"co";
    }else cout<<"khong";
    return 0;
}