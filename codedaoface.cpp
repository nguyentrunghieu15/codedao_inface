#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
typedef struct student
{
    int time_in;
    int time_out;
    int num_chair;
}student;
int search_chair(int*a,int n)                  // ham tra ve vi tri ghe cho hoc sinh ngoi
{
    int low=-1, high=-2,dynamic_low,dynamic_high;
    for(int i=0;i<n;i++)
       {
        if((i==0&&a[i]==0)||(a[i-1]!=0&&a[i]==0))
            dynamic_low=i;
        if((i==n-1&&a[i]==0)||(a[i]==0&&a[i+1]!=0))
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
int search_time_out(student*a,int n,int time_check)// tim hoc sinh co thoi gian ra la time_check
{
    for(int i=0;i<n;i++)                            // neu co tra ve so thu tu cua hoc sinh do , neu khong tim duoc tra ve -1
        if(a[i].time_out==time_check)
           return i;
    return -1;
}
int search_time_in(student*a,int n,int time_check)  // tim hoc sinh co thoi gian vao la time_check
{
    for(int i=0;i<n;i++)                            // neu co tra ve so thu tu cua hoc sinh do , neu khong tim duoc tra ve -1
        if(a[i].time_in==time_check)          
           return i;
    return -1;
}
int main()
{
    ifstream in_put("C:\\Users\\Hieu_private\\Documents\\codedao\\ip.INP"); // dia chi file vao
    if (in_put.fail())
{
	std::cout << "Failed to open this file!" << std::endl;
    return 0;
}
    int* cout_chair;
    student* student_in_class;
    int cout[2];
    for (int i = 0; i < 2; i++)
    {
        in_put >> cout[i];
    }
    cout_chair=(int*)calloc(cout[0],sizeof(int)*cout[0]);
    student_in_class=(student*)malloc(sizeof(student)*cout[1]);
    for(int i=0;i<cout[1];i++)
    {
        in_put >> student_in_class[i].time_in; 
        in_put >> student_in_class[i].time_out;
        student_in_class->num_chair=0;
    }
    in_put.close();
    int n=student_in_class[cout[1]-1].time_in;
    for(int i=1;i<=n;i++)
    {
        int student_in= search_time_in(student_in_class,cout[1],i);
        if(student_in!=-1)
           {
               int chair = search_chair(cout_chair,cout[0]);
                cout_chair[chair]=1;
                student_in_class[student_in].num_chair=chair+1;
           }
        int student_out=search_time_out(student_in_class,cout[1],i);
        if(student_out!=-1)
        {
            cout_chair[student_in_class[student_out].num_chair-1]=0;
        }
        
    }
    ofstream out_put("C:\\Users\\Hieu_private\\Documents\\codedao\\out.OUT",ios::out | ios::trunc);// dia chi ra
    if (out_put.fail())
{
	std::cout << "Failed to open this file!" << std::endl;
    return 0;
}
    for(int i=0;i<cout[1];i++)
    {
        out_put <<student_in_class[i].num_chair<<' '; 
    }
    out_put.close();
    return 0;
}