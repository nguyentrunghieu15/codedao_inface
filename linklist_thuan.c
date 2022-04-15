#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<stdlib.h>

typedef struct node{
    /*data*/
    format data;
    node* next;
    node* prev;
}node;
node* head=NULL;
node* tail=NULL;
node* createdNode(){
    node* new_node= (node*)malloc(sizeof(node));
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

void push_back(format data){
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
void push_front(format data){
    node* new_node=createdNode();
    new_node->data=data;
    if(head!=NULL){
        head->prev=new_node;
        new_node->next=head;
        head=new_node;
    }
    else{
        head=new_node;
        tail=new_node;
    }
}
node* findNode(/*data*/format x){
    node* cur=head;
    while(cur!=NULL){
       if(cur->data==x/*data*/){
           return cur;
       }
       cur=cur->next;
    }
    return NULL;
}
void swap(node* A, node* B){
    if(A!=NULL&&B!=NULL){
        int c;
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
        while(idexj!=NULL&&idexj->data>idexi->data){
            swap(idexi,idexj);
            idexj=idexj->prev;
            idexi=idexi->prev;
        }
        left=left->next;
    }
}


typedef struct format{
    int a;
    int b;
};
int main(){
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        format c;scanf("%d",&c.a,&c.b);
        push_back(c);
    }
    deleteNode(findNode(1));
    return 0;
}
