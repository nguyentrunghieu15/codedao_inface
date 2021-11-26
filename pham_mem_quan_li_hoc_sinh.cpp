#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
using namespace std;
int num_node;// so luong sinh vien
typedef struct sinh_vien
{
    char name[30]; // tên
    char birth[30];// ngày sinh
    int age;// tuoi
    int avg_mark;// GPA
    bool graduate; // tình trạng học hay nghỉ
}sinh_vien;
typedef struct node{
    sinh_vien data;
    node* next;
}node;
node* in_put(); // nhan du lieu
void processing_data(sinh_vien *a, char b[]); // ham xu li du lieu
node* delete_node(node *head,int x); // ham xoa sinh vien
void browse_list(node *head);  // ham in danh sách sinh vien
node* add_node(node *head); // thêm sinh vien
void add_data(sinh_vien* data); // nhap thong tin sinh vien
int main(){
    FILE *fp;
    fp=freopen("list_data.txt","r",stdin);
    /* file list_data cos dinh dang dong dau tien la so luong sinh vien
        các dong tiếp theo mỗi dòng ứng với thông tin 1 sinh viên
        các trường cách nhau 1 dấu ';' */
    node* head; // con tro đầu danh sách
    head=in_put();
    fclose(fp);
    fflush(stdin);
    browse_list(head);
    head=add_node(head);
    browse_list(head);
    return 0;
}
node* in_put(){
    cin>>num_node;
    char c[100];
    gets(c);
    if(num_node==0)
        return NULL;
    node* head;
    node *cur;
    for(int i=0;i<num_node;i++){
        if(i==0){
            char b[100];
            gets(b);
            node *a=new node;
            processing_data(&a->data,b);
            head=a;
            cur=a;
        }else{
            char b[100];
            gets(b);
            node *a=new node;
            processing_data(&a->data,b);
            cur->next=a;
            cur=a;
            }
    }
        cur->next=NULL;
        return head;
}
void processing_data(sinh_vien *a, char b[]){
    char data[5][30];
    int j=0;
    int couting=0;
    for(int i=0;i<strlen(b);i++){
        if(b[i]==';'){
            data[j][couting]='\0';
            j++;
            couting=0;
        }else{
            data[j][couting]=b[i];
            couting++;
        }
    }
    strcpy(a->name,data[0]);
    strcpy(a->birth,data[1]);
    a->age=atoi(data[2]);
    a->avg_mark=atoi(data[3]);
    a->graduate=atoi(data[4]);
}
node* delete_node(node *head,int x){
    if(x==1){
        if(head->next==NULL){
            delete(head);
            return NULL;
        }else{
            node* del=head;
            head=head->next;
            delete(del);
            return head;
        }
    }else{
        node *cur=head;
        for(int i=0;i<x-2;i++)
            cur=cur->next;
        node *del=cur->next;
        cur->next=del->next;
        delete(del);
        return head;
    }
}
void browse_list(node *head){
    node* cur;
    int i=1;
    for(cur=head;cur!=NULL;cur=cur->next){
        printf("%-3d%-20s%-20s%5d%5.2f%10s\n",i++,cur->data.name,cur->data.birth,cur->data.age,(cur->data.avg_mark)/10.0,(cur->data.graduate)?"Dang hoc":"Nghi");
    }
}
node* add_node(node *head){
    if(head==NULL){
    node* _new_node= new node;
    add_data(&_new_node->data);
    _new_node->next=NULL;
    head=_new_node;
    return head;
    }else{
    node *cur;
    for(cur=head;cur->next!=NULL;cur=cur->next){
        continue;
    }
    node* _new_node= new node;
    add_data(&_new_node->data);
    _new_node->next=NULL;
    cur->next=_new_node;
    return head;
    }
}
void add_data(sinh_vien* data){
    cout<<"Nhap ten hoc sinh:";
    gets(data->name);
    cout<<"Nhap ngay sinh:";
    gets(data->birth);
    cout<<"Nhap tuoi:";
    cin>>data->age;
    cout<<"Nhap diem:";
    cin>>data->avg_mark;
    cout<<"Nhap tinh trang(1 la dang hoc, 0 la nghi hoc):";
    cin>>data->graduate;
}