#include <iostream>
#include <stdlib.h>
#include <string.h>
int n,a,b,k;
long s;
long **cathe;
char *solve;
char *minsolve;
bool mem = false;
using namespace std;
int abs(int c, int d){
    if(c>d)
        return c-d;
    else
        return d-c;
}
bool check(int x, int y){
    if(x>n||y>n)
        return 0;
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)   
            if(cathe[i][j]-(abs(a+i,x)+abs(b+j,y))<0)
                return 0;
    return 1;
}
void update_cathe(int x, int y){
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)   
            cathe[i][j]-=(abs(a+i,x)+abs(b+j,y));
}
void return_cathe(int x, int y){
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)   
            cathe[i][j]+=(abs(a+i,x)+abs(b+j,y));
}
void Try(int k, int x, int y){
    for(int i=0;i<2;i++){  // 0 la len , 1 la na
        if(i==0){
            if(check(x,y+1)){
                solve[k]='N';
                update_cathe(x,y+1);
                if(x==n && y+1==n){
                    solve[k+1]='\0';
                    if(strcmp(solve,minsolve)<0)
                        strcpy(minsolve,solve);
                    mem=true;
                }
                else Try(k+1,x,y+1);
                return_cathe(x,y+1);
           }
        }
        else{
            if(check(x+1,y)){
                solve[k]='E';
                update_cathe(x+1,y);
                if(x+1==n && y==n){
                    solve[k+1]='\0';
                    if(strcmp(solve,minsolve)<0)
                        strcpy(minsolve,solve);
                    mem=true;
                }
                else Try(k+1,x+1,y);
                return_cathe(x+1,y);
           }
        }
    }
}
int main(){
    cin>>n>>s>>a>>b>>k;
    solve=(char*)malloc(sizeof(char)*(2*n-1));
    minsolve=(char*)malloc(sizeof(char)*(2*n-1));
    cathe=(long**)malloc(sizeof(long*)*k);
    for(int i=0; i<k;i++){
        cathe[i]=(long*)malloc(sizeof(long)*k);
    }
    for(int i=0;i<k;i++)   
        for(int j=0;j<k;j++)
            cathe[i][j]=s;
    for(int i=0;i<2*n-1;i++)
        minsolve[i]='N';
    Try(0,1,1);
    if(mem==false)
        cout<<"imposible"<<endl;
    else
        cout<<minsolve<<endl;
    delete(solve);
    delete(minsolve);
    for(int i=0;i<k;i++)
        delete(cathe[i]);
    delete(cathe);
    return 0;
}