#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
typedef struct maytinh{
    char hangsanxuat[11];
    char ID[21];
    char chip[3];
    int Ram;
    float Gia;
}maytinh;
typedef struct node{
    maytinh data;
    node* next;
    node* prev;
}node;
node* head=NULL;
node* tail=NULL;
node* createdNode();
void push_back(maytinh data);
void deleteNode(node *del);
void swap(node* A, node* B);
// node* findNode(/*data*/format x);
void sort_insertsort(node* left, node* right);
maytinh getData();
void add_list();
void creatID();
void xuat();
int main(){
    do{
        int c;
        printf("MENU:\n");
        printf("1.Nhap may tinh\n");
        printf("2.Khoi tao ma\n");
        printf("3.Sort\n");
        printf("4.In\n");
        printf("5.Exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:add_list();break;
        case 2:creatID();break;
        case 3:sort_insertsort(head,tail);break;
        case 4:xuat();break;
        case 5:return 0;
        default:
            break;
        }
        system("cls");
    }while (true);
}
node* createdNode(){
    node* new_node= (node*)malloc(sizeof(node));
    strcpy(new_node->data.ID,"");
    new_node->next=NULL;
    new_node->prev=NULL;
    return new_node;
}
void deleteNode(node *del){
    if(del==NULL)
        return;
    else if(del==head){
        head=head->next;
        head->prev=NULL;
        delete(del);
    }else if(del==tail){
        tail=del->prev;
        tail->next=NULL;
        delete(del);
    }else{
        node* prevdel=del->prev;
        node* nextdel= del->next;
        prevdel->next=nextdel;
        nextdel->prev=prevdel;
        delete(del);
    }
}

void push_back(maytinh data){
    node* new_node=createdNode();
    new_node->data=data;
    if(head!=NULL){
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    else{
        head=new_node;
        tail=new_node;
    }
}
// node* findNode(/*data*/format x){
//     node* cur=head;
//     while(cur!=NULL){
//        if(cur->data==x/*data*/){
//            return cur;
//        }
//        cur=cur->next;
//     }
//     return NULL;
// }
void swap(node* A, node* B){
    if(A!=NULL&&B!=NULL){
        maytinh c;
        c=A->data;
        A->data=B->data;
        B->data=c;
    }
}
void sort_insertsort(node* left, node* right){
    if(left==NULL||right==NULL)
        return;
    left=left->next;
    while(left!=NULL){
        node* idexi=left;
        node* idexj=idexi->prev;
        while(idexj!=NULL&&idexj->data.Gia>idexi->data.Gia){
            swap(idexi,idexj);
            idexj=idexj->prev;
            idexi=idexi->prev;
        }
        left=left->next;
    }
}
maytinh getData(){
    maytinh a;
    printf("Nhap hang san xuat: ");fflush(stdin);scanf("%[^\n]%*c",a.hangsanxuat);
    printf("Nhap chip san xuat: ");fflush(stdin);scanf("%[^\n]%*c",a.chip);
    printf("Nhap Ram: ");scanf("%d",&a.Ram);
    printf("Nhap gia: ");scanf("%f",&a.Gia);
    while (strlen(a.hangsanxuat)>10)
    {
       printf("Nhap lai hang san xuat: ");fflush(stdin);scanf("%[^\n]%*c",a.hangsanxuat);
    }
    while (strcmp(a.chip,"i3")!=0&&strcmp(a.chip,"i5")!=0&&strcmp(a.chip,"i7")!=0)
    {
        printf("Nhap lai chip san xuat: ");fflush(stdin);scanf("%[^\n]%*c",a.chip);
    }
    while (a.Ram%4!=0)
    {
        printf("Nhap Ram: ");scanf("%d",&a.Ram);
    }
    while (a.Gia<=0)
    {
        printf("Nhap gia: ");scanf("%f",a.Gia);
    }
    return a;
}
void add_list(){
    do{
        push_back(getData());
    }while (getch()=='y');
}
void creatID(){
    node* cur=head;
    while (cur!=NULL)
    {
        strcpy(cur->data.ID,cur->data.hangsanxuat);
        strcat(cur->data.ID,cur->data.chip);
        char ram[8];
        itoa(cur->data.Ram,ram,10);
        strcat(cur->data.ID,ram);
        cur=cur->next;
    }  
}
void xuat(){
    int STT=1;
    printf("STT-MA-CHiP_RAM_GIA\n");
    node* cur=head;
    while (cur!=NULL)
    {
        printf("%-4d- %-20s - %-3s  -  %d - %f\n",STT,cur->data.ID,cur->data.chip,cur->data.Ram,cur->data.Gia);
        STT++;
        cur=cur->next;
    }
    getch();
}