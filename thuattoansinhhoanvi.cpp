#include <iostream>
#include <string.h>
using namespace std;
void swap_string(char *a, char *b);
void sort_string(int n, int point, char **a);
void out_put(int n, char **a);
void in_put(int n,char **a);
void permutation_next(int n, char **a);
void Try(int k,int n,char **a);
char **s;
int *d;
int main()
{
    int n;
    char **a;
    cout<<"Nhap so phan tu cua mang:";
    cin>>n;
    a=(char**)malloc(sizeof(char*)*n);
    s=(char**)malloc(sizeof(char*)*n);
    for(int i=0;i<n;i++)
        a[i]=(char*)malloc(sizeof(char)*100);
    for(int i=0;i<n;i++)
        s[i]=(char*)malloc(sizeof(char)*100);
    d=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        d[i]=0;
    in_put(n,a);
    // permutation_next(n,a);
    Try(0,n,a);
    for(int i=0;i>n;i++)
        delete(a[i]);
    delete(a);
    return 0;
}
void swap_string(char *a, char *b)
{
    char c[100];
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}
void sort_string(int n, int point, char **a)
{
    for(int i=point+1;i<n;i++)
    {
        int j=i;
        while(j>point && strcmp(a[j-1],a[j])>0)
        {
            swap_string(a[j-1],a[j]);
            j--;
        }
    }
}
void out_put(int n, char **a)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void in_put(int n, char **a)
{
    for(int i=0;i<n;i++)
        cin >>a[i];
}
void permutation_next(int n, char **a)              /* Thuat toan sinh hoan vi ke tiep*/
{
    out_put(n,a);
    while(true)
    {
        int j=n-1;
        while(strcmp(a[j-1],a[j])>=0)
            j--;
        if(j==0)
            break;
        int i=j-1;
        for(j=n-1;j>i;j--)
        {
            if(strcmp(a[j],a[i])>0)
               {
                    swap_string(a[j],a[i]);
                    break;
               }
        }
        sort_string(n,i+1,a);
        out_put(n,a);
    }
}
void Try(int k,int n,char **a)   /* Quay lui tim hoan vi*/
{
    for(int i=0;i<n;i++)
    {
        if(d[i]==0)
        {
            strcpy(s[k],a[i]);
            d[i]=1;
            if(k==n-1)
                 out_put(n,s);
            else
                 Try(k+1,n,a);
            d[i]=0;
        }
    }
}