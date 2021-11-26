#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>

typedef struct student_time
{
    int time;
    bool status;    // true laf in flase laf out
    int id;
}student_time;
int search_chair(int a[],int n)                  // ham tra ve vi tri ghe cho hoc sinh ngoi
{
    int low=-1, high=-2,dynamic_low,dynamic_high;
    for(int i=0;i<n;i++)
       {
        if((i==0&&a[i]==0)||(a[i]==0&&a[i-1]==1))
            dynamic_low=i;
        if((i==n-1&&a[i]==0)||(a[i]==0&&a[i+1]==1)
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

// Hàm trộn hai mảng con vào nhau theo đúng thứ tự
void Merge(student_time A[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Số phần tử của mảng thứ nhất
    int n2 = right - mid; // Số phần tử của mảng thứ hai

    // Tạo hai mảng tạm để lưu hai mảng con
    student_time *LeftArr = new student_time[n1];
    student_time *RightArr = new student_time[n2];

    // Sao chép phần tử 2 mảng con vào mảng tạm
    for (int i = 0; i < n1; i++)
        LeftArr[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        RightArr[i] = A[mid + 1 + i];

    // current là vị trí hiện tại trong mảng A
    int i = 0, j = 0, current = left;

    // Trộn hai mảng vào nhau theo đúng thứ tự
    while (i < n1 && j < n2)
        if (LeftArr[i].time <= RightArr[j].time)
            A[current++] = LeftArr[i++];
        else
            A[current++] = RightArr[j++];

    // Nếu mảng thứ nhất còn phần tử thì copy nó vào mảng A
    while (i < n1)
        A[current++] = LeftArr[i++];

    // Nếu mảng thứ hai còn phần tử thì copy nó vào mảng A
    while (j < n2)
        A[current++] = RightArr[j++];

    // Xóa hai mảng tạm đi
 //   delete[] LeftArr, RightArr;
}

// Hàm chia đôi mảng và gọi hàm trộn
void _MergeSort(student_time A[], int left, int right)
{
    // Kiểm tra xem còn chia đôi mảng được không
    if (left < right)
    {
        // Tìm phần tử chính giữa
        // left + (right - left) / 2 tương đương với (left + right) / 2
        // việc này giúp tránh bị tràn số với left, right quá lớn
        int mid = left + (right - left) / 2;
 
        // Sắp xếp mảng thứ nhất
        _MergeSort(A, left, mid);
        // Sắp xếp mảng thứ hai
        _MergeSort(A, mid + 1, right);

        // Trộn hai mảng đã sắp xếp
        Merge(A, left, mid, right);
    }
}

// Hàm sắp xếp chính, được gọi khi dùng merge sort
void MergeSort(student_time A[], int n)
{
    _MergeSort(A, 0, n - 1);
}
int main()
{
    int* cout_chair;
    student_time* student_in_class_time;
    int* student_in_class_sit;
    int n,k;
    scanf("%d%d",&k,&n);
    cout_chair=(int*)calloc(k,sizeof(int)*k);
    student_in_class_time=(student_time*)malloc(sizeof(student_time)*n*2);
    student_in_class_sit=(int*)calloc(n,sizeof(int)*n);    
    // int cout_chair[k];
    // student_time student_in_class_time[n*2];
    // int student_in_class_sit[n];
    for(int i=0;i<n;i++)
      { 
        int j=i*2;
        scanf("%d", &student_in_class_time[j].time);
                    student_in_class_time[j].status=1;
                    student_in_class_time[j].id=i;
        scanf("%d", &student_in_class_time[j+1].time);
                    student_in_class_time[j+1].status=0;
                    student_in_class_time[j+1].id=i;   
      }
    int time_in_latest;
    MergeSort(student_in_class_time,n*2);

    for(int i=0;i<n*2;i++)
     {   if(student_in_class_time[i].status==1)
           {
               time_in_latest=i;
           }
     }
    for(int i=0;i<n*2;i++)
    {
        if(student_in_class_time[i].status==1)
        {
            student_in_class_sit[student_in_class_time[i].id]=search_chair(cout_chair,k);
            cout_chair[student_in_class_sit[student_in_class_time[i].id]]=1;
        }
        if(student_in_class_time[i].status==0)
           {
               cout_chair[student_in_class_sit[student_in_class_time[i].id]]=0;
           }
    }
    for(int i=0;i<n;i++)
       printf("%d ",student_in_class_sit[i]+1);
    delete(cout_chair);
    delete(student_in_class_time);
    delete(student_in_class_sit);
    return 0;
}
