#include <bits/stdc++.h>
using namespace std;
int search_chair(int a[],int n)                  // ham tra ve vi tri ghe cho hoc sinh ngoi
{
    int low=-1, high=-2,dynamic_low,dynamic_high;
    for(int i=0;i<n;i++)
       {
        if((i==0&&a[i]==0)||(a[i]==0&&a[i-1]==1))
            dynamic_low=i;
        if((i==n-1&&a[i]==0)||(a[i]==0&&a[i+1]==1))
        {
            dynamic_high=i;
            if(dynamic_high-dynamic_low>high-low)
               {
                   high=dynamic_high;
                   low=dynamic_low;
               }
        }
       }
    return (high+low)/2;
}

int main()
{
    freopen("data.bat","r",stdin);
    int n,k;
    cin>>k>>n;
    int student[n+1];
    int chair[k];
    int time[2*n+2];
    bool student_time[n+1];
    memset(chair,0,sizeof(chair));
    memset(student_time,1,sizeof(student_time));
    for(int i=1;i<=n;i++){
        int in,out;
        cin>>in>>out;
        time[in]=i;
        time[out]=i;
    }
    for(int i=1;i<=2*n;i++){
        if(student_time[time[i]]){
            student[time[i]]=search_chair(chair,k)+1;
            student_time[time[i]]=false;
            chair[student[time[i]]-1]=1;
        }else{
            chair[student[time[i]]-1]=0;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<student[i]<<endl;
}
