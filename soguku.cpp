// Giai soguku 9x9
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <iostream>
int **columns;
int **row;
int **quare;
int **broad;
int search_quare(int i,int j)
{
    if(i<=3&&j<=3)
        return 1;
    else if(i<=3 && j>=4 &&j<=6)
        return 2;
    else if(i<=3 &&j>=7)
        return 3;
    else if(i>=4 &&i<=6 &&j<=3)
        return 4;
    else if(i>=4 &&i<=6 &&j>=4 &&j<=6)
        return 5;
    else if(i>=4 &&i<=6 &&j>=7)
        return 6;
    else if(i>=7 &&j<=3)
        return 7;
    else if(i>=7 && j>=4 &&j<=6)
        return 8;
    else if(i>=7 &&j>=7)
        return 9;
    return 0;
}
void in_put_data()
{
    freopen("data.txt","r",stdin);
    // printf("Nhap ma tran du lieu dau vao:");  // :Lan luot theo thu tu hang-cot-gia tri
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            scanf("%d",&broad[i][j]);
            if(broad[i][j]!=0){
                row[i][broad[i][j]]=1;
                columns[j][broad[i][j]]=1;
                quare[search_quare(i,j)][broad[i][j]]=1;
            }
        }
    }
    // int n=9;
    // // scanf("%d", &n);
    // for(int k=0;k<n;k++)
    // {
    //     int i,j;
    //     scanf("%d%d",&i,&j);
    //     scanf("%d",&broad[i][j]);
    //     row[i][broad[i][j]]=1;
    //     columns[j][broad[i][j]]=1;
    //     quare[search_quare(i,j)][broad[i][j]]=1;
    // }
}
int check(int i,int j,int k)
{
    if(row[i][k]==0&&columns[j][k]==0&&quare[search_quare(i,j)][k]==0)
        return 1;
    else return 0;
}
void out_put(int n)
{
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                printf("%3d",broad[i][j]);
            printf("\n");
        }
    printf("\n");
}
void Try(int i,int j)
{
            if(broad[i][j]==0)
            {
                    for(int k=1;k<=9;k++)
                 {
                     if(check(i,j,k)==1)
                    {
                        broad[i][j]=k;
                        row[i][k]=1;
                        columns[j][k]=1;
                        quare[search_quare(i,j)][k]=1;
                        if(i==9&&j==9)
                                {
                                    out_put(9);
                                    // exit(0);
                                }
                        else
                        {
                            if(i<9&&j==9)
                                Try(i+1,1);
                            else if(j<9)  
                                Try(i,j+1);
                        }
                        broad[i][j]=0;
                        row[i][k]=0;
                        columns[j][k]=0;
                        quare[search_quare(i,j)][k]=0;
                    }
                 }
            }
            else 
                  {
                     if(i==9&&j==9)
                            {
                                    out_put(9);
                                    // exit(0);
                            }
                        else
                        {
                            if(i<9&&j==9)
                                Try(i+1,1);
                            else if(j<9)  
                                Try(i,j+1);
                        }
                 }     
        }
void format()
{
    columns=(int**)malloc(sizeof(int*)*10);
    for(int k=0;k<10;k++)
        columns[k]=(int*)calloc(10,sizeof(int)*10);
    row=(int**)malloc(sizeof(int*)*10);
    for(int k=0;k<10;k++)
        row[k]=(int*)calloc(10,sizeof(int)*10);
    broad=(int**)malloc(sizeof(int*)*10);
    for(int k=0;k<10;k++)
        broad[k]=(int*)calloc(10,sizeof(int)*10);
    quare=(int**)malloc(sizeof(int*)*10);
    for(int k=0;k<10;k++)
        quare[k]=(int*)calloc(10,sizeof(int)*10);
}
int main()
{
    format();
    in_put_data();
    Try(1,1);
    return 0;
}