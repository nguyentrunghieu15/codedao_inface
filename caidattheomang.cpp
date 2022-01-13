#include <bits/stdc++.h>
using namespace std;
int num_node=0;// so luong sinh vien
typedef struct sinh_vien
{
    int masv;
    char name[30]; // tên   
    char birth[30];// ngày sinh
    int avg_mark;// GPA
}sinh_vien;
typedef struct node{
    sinh_vien data;
    node* next;
}node;
int main(){
    return 0;
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
    num_node++;
    return head;
    }
}
void add_data(sinh_vien* data){
    cout<<"Nhap ma sv"; cin>>data->masv;
    cout<<"Nhap ten hoc sinh:";
    fflush(stdin);gets(data->name);
    cout<<"Nhap ngay sinh:";
    fflush(stdin);gets(data->birth);
    cout<<"Nhap diem:";
    fflush(stdin);cin>>data->avg_mark;
}
node* delete_node(node *head){
        node *cur=head;
        cur=cur->next
        node* del=head;
        for(;cur!=NULL&&cur->next!=NULL;cur=cur->next;)
                del=del->next;
        if(del==head){
            delete(head);
            return NULL;
        }else
        {
            delete(cur);
            cur->next=NULL:
            return head;
        }
}

node *selection_sort(node *head){
    node *max_;
    node *cur;
    node *prviot=NULL;
    for(;prviot!=head->next;){
        max_=head;
        for(cur=head->next;cur->next!=prviot;cur=cur->next){
             if(cmp_name(cur->data.name,max_->data.name)){
                 max_=cur;
            }
        }
        if(max_!=cur&&cur!=NULL){
                sinh_vien c;
                c=max_->data;
                max_->data=cur->data;
                cur->data=c;
            }
        prviot=max_;
        }
    }
    return head;
}
bool cmp_name(char full_name1[], char full_name2[]){
    char name1[20];
    char name2[20];
    int i;
    int couting=0;
    for(i= strlen(full_name1)-1;i>-1;i--){
        if(full_name1[i]==' ')
            break;
        else{
            name1[couting]=full_name1[i];
            couting++;
        }
       }
    name1[couting]='\0';
    strrev(name1);
    couting=0;
    for(i= strlen(full_name2)-1;i>-1;i--){
        if(full_name2[i]==' ')
            break;
        else{
            name2[couting]=full_name2[i];
            couting++;
        }
       }
    name2[couting]='\0';
    strrev(name2);
    if(strcmp(name1,name2)>0)
        return true;
    else return false;
}