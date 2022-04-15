
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <int> Mem,A;
    int n,k;
    int x,head,tail;
    int maximun=INT_MIN;
    cin>>n>>k;
    Mem.push_back(0);
    A.push_back(0);
    for(int i=0;i<n;i++){
        cin>>x;A.push_back(x);
    }
    for(int i=1;i<=n;i++){
        int c=max(A[i],Mem.back()+A[i]);
        maximun=max(maximun,c);
        Mem.push_back(c);
    }
    if(maximun<k){
        cout<<-1;
        return 0;
    }else{
        for(int i=n;i>=1;i--){
            if(Mem[i]==maximun){
                tail=i;
                head=i;
                while (head>1&&Mem[head-1]==Mem[head]-A[head])
                {
                    head--;                    
                }
                break;
            }
        }
        while(maximun>k){
            if(A[head]<A[tail]){
                if(maximun-A[head]>=k){
                    maximun-=A[head];
                    head++;
                }else break;
            }else{
                if(maximun-A[tail]>=k){
                    maximun-=A[tail];
                    tail--;
                }else break;
            }
        }
        cout<<tail-head+1;
    }
    return 0;
}