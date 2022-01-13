#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int mem[3000][3000];
int palrodin(char a[], int i, int j){
    if(i>j)
        return 0;
    else if(i==j){
        return 1;
        }
    else{
        if(mem[i][j]!=0)
            return mem[i][j];
        else{
            if(a[i]==a[j]){
                mem[i][j]=palrodin(a,i+1,j-1)+2;
                return mem[i][j];
            }else{
                mem[i][j]=max(palrodin(a,i+1,j),palrodin(a,i,j-1));
                return mem[i][j];
            }
        }
    }
}
void trace(char a[], int i, int j){
    if(i>j){
        return;
    }
    else if(i==j){
        cout<<a[i];
    }else{
        if(a[i]==a[j]){
            cout<<a[i];
            trace(a,i+1,j-1);
            cout<<a[i];
        }
        else{
            if(mem[i+1][j]>mem[i][j-1])
                trace(a,i+1,j);
            else
                trace(a,i,j-1);
        }
    }
}
int main(){
    int n;
    cin>>n;
    char a[n+1];
    fflush(stdin);fgets(a,n+1,stdin);
    cout<<palrodin(a,0,n-1)<<endl;
    trace(a,0,n-1);
    getch();
    return main();
}