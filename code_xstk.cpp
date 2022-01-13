#include <bits/stdc++.h>

using namespace std;
int n,m;
float X[10];
float Y[10];
float P[10][10];
void in_put(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>X[i];
    }
    for(int i=0;i<m;i++){
        cin>>Y[i];
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++)
            cin>>P[i][j];
    }
}
float ky_vong(){
    float E=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            E+=(0.4*X[i]+0.6*Y[j])*P[i][j];
    }
    return E;
}
float phuwongsai(){
    float V=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            V+=(0.4*X[i]+0.6*Y[j])*(0.4*X[i]+0.6*Y[j])*P[i][j];
    }
    return V-ky_vong()*ky_vong();
}
int main(){
    freopen("data.txt","r",stdin);
    in_put();
    cout<<ky_vong()<<" "<<phuwongsai();
    return 0;
}