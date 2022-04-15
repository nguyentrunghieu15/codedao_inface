
#include<bits/stdc++.h>
#define MAX_VALUE 200000
using namespace std;
struct edge{
    int a;
    int b;
};
vector <int > A[MAX_VALUE];
int weight[MAX_VALUE];
edge canh[MAX_VALUE];
bool visited[MAX_VALUE];
int n,m,q;
void input(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>weight[i];
    for(int i=1;i<=m;i++){
        cin>>canh[i].a>>canh[i].b;
        A[canh[i].a].push_back(canh[i].b);
        A[canh[i].b].push_back(canh[i].a);
    }
}
void DFS(int idex, int& sum_weight){
    visited[idex]=false;
    sum_weight+=weight[idex];
    for(int i=0;i<A[idex].size();i++){
        if(visited[A[idex][i]]){
            DFS(A[idex][i],sum_weight);
        }
    }
}
int main(){
    freopen("data.txt","r",stdin);
    input();
    for(int i=0;i<q;i++){
        memset(visited,1,sizeof(visited));
        char quese;cin>>quese;
        int j;
        if(quese=='D'){
            cin>>j;
            for(int i=0;i<A[canh[j].a].size();i++){
                if(A[canh[j].a][i]==canh[j].b){
                    A[canh[j].a].erase(A[canh[j].a].begin()+i);
                    break;
                }
            }
            for(int i=0;i<A[canh[j].b].size();i++){
                if(A[canh[j].b][i]==canh[j].a){
                    A[canh[j].b].erase(A[canh[j].b].begin()+i);
                    break;
                }
            }
            }else{
                cin>>j;
                cin>>weight[j];
            }
            int max_weight=INT_MIN;
            int sum_weight=0;
            for(int i=1;i<=n;i++){
                if(visited[i]){
                    DFS(i,sum_weight);
                    if(sum_weight>max_weight){
                        max_weight=sum_weight;
                    }
                    sum_weight=0;
                }
            }
            cout<<max_weight<<endl;
        }
    return 0;
}