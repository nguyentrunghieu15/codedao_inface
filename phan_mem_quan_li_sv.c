#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct birthday{
    int ngay;
    int thang;
    int nam;
}birthday;
typedef struct subject{
    float diem1;
    float diem2;
    float diemtb;
}
typedef struct node{
    node* next;
    node* prev;
    char hoten[100];
    char ID[20];
    char GT[5];
    birthday ngaysinh;
    subject mon[4];
}
node *get_data(char data[]){
    node* new_node=(node*)malloc(sizeof(node));
}
node* get_data(node *head, node* tail){
    // các trường cách nhau bằng dấu '|' theo thứ tự id|hoten|gioitinh|ngaysinh|3diem mon 1|3 diemmon2|3diemmon3|3diemmon4|
    node* head;
    FILE* fp=fopen("danhsach.txt","r");
    char data[124];
    do{
        fgets(data,124,fp);
        int couting=0;
        for(int i=0;i<strlen(data);i++){
            (*new_node).ID[couting]=data[i];
        }
    }while(data!=EOF);
}
int main(){
    node* head;

    
    return 0;
}