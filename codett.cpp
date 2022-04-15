#include <iostream>
#include <math.h>
#include<algorithm>
using namespace std;
struct point{
    int x;
    int y;
};
point A[100000];
double Distance(point A, point B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
bool cmpx(point A, point B){
    if(A.x<=B.x)
        return true;
    else return false;
}
bool cmpy(point A, point B){
    if(A.y<=B.y)
        return true;
    else return false;
}
double slove(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i].x>>A[i].y;
    }
    sort(A,A+n,cmpx);
    double min_distance=100000000000;
    for(int i=0;i<n;i++){
        min_distance=min(Distance(A[i],A[i-1]),min_distance);
    }
    sort(A,A+n,cmpy);
    for(int i=0;i<n;i++){
        min_distance=min(Distance(A[i],A[i-1]),min_distance);
    }
    return min_distance;
}

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        double min_=slove();
        printf("%.6lf\n",min_);
    }
    return 0;
}