#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
int check(int *a, int n, int b)
{
    for(int i=0;i<n;i++)
     {
         if(a[i]==b)
            return 0;
     }
     return 1;
}
int main()
{
    int n;
    int k;
    cout<<"nhap so hoc sinh:";
    cin>>n;
    srand(time(0));
    k=rand()%n+n;
    int *time;
    time=(int*)malloc(sizeof(int)*n*2);
    for(int i=0;i<n;i++)
        {
            int j=i*2;
            // do{
                time[j]=rand();
            // }
            // while(check(time,j+1,time[j])==0);
            // do{
                time[j+1]=rand()%1000+time[j];
            // }
            // while(check(time,j+2,time[j+1])==0);
         }
    ofstream out_put("C:\\Users\\Hieu_private\\Documents\\codedao\\out.OUT",ios::trunc);
    if (out_put.fail())
{
	std::cout << "Failed to open this file!" << std::endl;
	return -1;
}
     out_put<< k <<' '<< n <<'\n';
    for(int i=0;i<2*n;i++)
     {
         if(i%2==0)
            out_put << time[i]<<' ';
        if(i%2==1)
            out_put << time[i]<<'\n';
     }
     out_put.close();
    return 0;
}