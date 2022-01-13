#include<bits/stdc++.h>
#include <string.h>
#include <fstream>
using namespace std;

int main(){
    srand(time(0));
    ofstream fp;
    fp.open("data.txt",ios::out|ios::trunc);
    int n=rand()%50;
    fp<<n<<endl;
    for(int i=0;i<n;i++)
    {
        if(rand()%2==0)
            fp<<'-';
        float c=rand()%100/2.0;
        int d;
        d=rand()%200;
        fp<<c<<" "<<d<<endl;
    }
    fp.close();
    return 0;
}