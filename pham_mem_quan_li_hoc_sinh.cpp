#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
int num_node=0;// so luong sinh vien
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
void update_data(node *head);
void fix_data(node *head, int x);
void sort_list(node *head);
bool cmp_name(char full_name1[], char full_name2[]);
bool check_seach(char hint[], char idex[]);
void search(node * head,char hint[]);
int main(){    
    node* head; // con tro đầu danh sách
    head=in_put();
    fflush(stdin);
    while(true){
        system("cls");
        cout<<"1.Exit"<<endl;
        cout<<"2.In Danh Sach"<<endl;
        cout<<"3.Them sinh vien"<<endl;
        cout<<"4.Xoa sinh vien"<<endl;
        cout<<"5.Cap nhat thong tin"<<endl;
        cout<<"6.Sua thong tin"<<endl;
        cout<<"7.Sap xep A->Z"<<endl;
        cout<<"8.Tim kiem theo ten"<<endl;
        int q;
        cin>>q;fflush(stdin);
        switch(q){
            case 1: return 0;
            case 2: {
                system("cls");
                browse_list(head);
                getch();
                break;
            }
            case 3: {
                int n;
                system("cls");
                cout<<"Nhap so sinh vien can them:";cin>>n;fflush(stdin);
                for(int i=1;i<=n;i++){
                    system("cls");
                    cout<<i<<endl;
                    head=add_node(head);
                }
                break;
            }
            case 4:{
                system("cls");
                if(num_node==0){
                    cout<<"Danh sach rong"<<endl;
                    getch();
                    break;
                }
                browse_list(head);
                int i;
                cout<<"STT sinh vien can xoa:";cin>>i;fflush(stdin);
                head=delete_node(head,i);
                break;
            }
            case 5:{
                system("cls");
                update_data(head);
                cout<< "Cap nhat thanh cong";
                getch();
                break;
            }
            case 6:{
                system("cls");
                browse_list(head);
                int i;
                cout<<"STT sinh vien can sua:";cin>>i;fflush(stdin);
                fix_data(head,i);
                break;
            }
            case 7:{
                system("cls");
                sort_list(head);
                cout<<"Sap xep thanh cong";
                getch();
                break;
            }
            case 8:{
                system("cls");
                cout<<"Nhap thong tin:";
                char hint[30];
                gets(hint);
                search(head,hint);
                getch();
                break;
            }
        }
    }
}
node* in_put(){
    ifstream fp;
    fp.open("list_data.txt",ios::in);
    /* file list_data cos dinh dang dong dau tien la so luong sinh vien
        các dong tiếp theo mỗi dòng ứng với thông tin 1 sinh viên
        các trường cách nhau 1 dấu ';' */
    char num[100];
    fp.getline(num,100);
    if(strcmp(num,"")==0)
        return NULL;
    num_node=atoi(num);
    if(num_node==0){
        fp.close();
        return NULL;
    }
    node* head;
    node *cur;
    for(int i=0;i<num_node;i++){
        if(i==0){
            char b[100];
            fp.getline(b,100);
            node *a=new node;
            processing_data(&a->data,b);
            head=a;
            cur=a;
        }else{
            char b[100];
            fp.getline(b,100);
            node *a=new node;
            processing_data(&a->data,b);
            cur->next=a;
            cur=a;
            }
    }
    cur->next=NULL;
    fp.close();
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
            num_node--;
            return NULL;
        }else{
            node* del=head;
            head=head->next;
            num_node--;
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
        num_node--;
        return head;
    }
}
void browse_list(node *head){
    node* cur;
    cout<<"\t\t\t============================================================================="<<endl;
    cout<<"\t\t\t||STT||      HO VA TEN     ||      NGAY SINH     ||TUOI || GPA ||TINH TRANG||"<<endl;
    cout<<"\t\t\t============================================================================="<<endl;
    int i=1;
    for(cur=head;cur!=NULL;cur=cur->next){
        printf("\t\t\t||%-3d||%-20s||%-20s||%5d||%5.2f||%10s||\n",i++,cur->data.name,cur->data.birth,cur->data.age,(cur->data.avg_mark)/10.0,(cur->data.graduate)?"Dang hoc":"Nghi");
    }
    cout<<"\t\t\t============================================================================="<<endl;
}
node* add_node(node *head){
    if(head==NULL){
    node* _new_node= new node;
    add_data(&_new_node->data);
    _new_node->next=NULL;
    head=_new_node;
    num_node++;
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
    cout<<"Nhap ten hoc sinh:";
    fflush(stdin);gets(data->name);
    cout<<"Nhap ngay sinh:";
    fflush(stdin);gets(data->birth);
    cout<<"Nhap tuoi:";
    fflush(stdin);cin>>data->age;
    cout<<"Nhap diem:";
    fflush(stdin);cin>>data->avg_mark;
    cout<<"Nhap tinh trang(1 la dang hoc, 0 la nghi hoc):";
    fflush(stdin);cin>>data->graduate;
}
void update_data(node *head){
    ofstream fp;
    fp.open("list_data.txt",ios::out);
    fp<<num_node<<endl;
    node* cur;
    for(cur=head;cur!=NULL;cur=cur->next){
        fp<<cur->data.name<<';'<<cur->data.birth<<';'<<cur->data.age<<';'<<cur->data.avg_mark<<';'<<cur->data.graduate<<endl;
    }
    fp.close();
}
void fix_data(node *head, int x){
    node *cur=head;
        for(int i=0;i<x-1;i++)
            cur=cur->next;
    int check;
    cout<<"Sua ten: 1.CO   0.KO"<<endl;
    cin>>check;
    if(check){
        char new_name[30];
        cout<<"Ten moi:";
        fflush(stdin);gets(new_name);
        strcpy(cur->data.name,new_name);
    }
        cout<<"Sua ngay sinh: 1.CO   0.KO"<<endl;
    cin>>check;
    if(check){
        char new_name[30];
        cout<<"Ngay sinh moi:";
        fflush(stdin);gets(new_name);
        strcpy(cur->data.birth,new_name);
    }
        cout<<"Sua tuoi: 1.CO   0.KO"<<endl;
    cin>>check;
    if(check){
        int new_name;
        cout<<"Tuoi moi:";
        fflush(stdin);cin>>new_name;
        cur->data.age=new_name;
    }
    cout<<"Sua diem: 1.CO   0.KO"<<endl;
    cin>>check;
    if(check){
        int new_name;
        cout<<"Diem moi:";
        fflush(stdin);cin>>new_name;
        cur->data.avg_mark=new_name;
    }
    cout<<"Sua tinh trang: 1.CO   0.KO"<<endl;
    cin>>check;
    if(check){
        int new_name;
        cout<<"Tinh trang moi:";
        fflush(stdin);cin>>new_name;
        cur->data.graduate=new_name;
    }
}
void sort_list(node *head){
    node *cur ;
    node *prev;
    for(int i=0;i<num_node-1;i++){
        cur=head->next;
        prev=head;
        for(int j=0;j<num_node-1-i;j++){
            if(cmp_name(prev->data.name,cur->data.name)){
                sinh_vien c;
                c=prev->data;
                prev->data=cur->data;
                cur->data=c;
            }
            cur=cur->next;
            prev=prev->next;
        }
    }
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
    int len_max=strlen(name1)>strlen(name2)?strlen(name1):strlen(name2);
    for(i=0;i<len_max;i++){
        if(toascii(name1[i])>toascii(name2[i])){
            return true;
        }
    }
    return false;
}
void search(node * head,char hint[]){
    node* cur;
    strlwr(hint);
    cout<<"\t\t\t============================================================================="<<endl;
    cout<<"\t\t\t||STT||      HO VA TEN     ||      NGAY SINH     ||TUOI || GPA ||TINH TRANG||"<<endl;
    cout<<"\t\t\t============================================================================="<<endl;
    int i=1;
    for(cur=head;cur!=NULL;cur=cur->next){
        if(check_seach(hint,cur->data.name))
            printf("\t\t\t||%-3d||%-20s||%-20s||%5d||%5.2f||%10s||\n",i++,cur->data.name,cur->data.birth,cur->data.age,(cur->data.avg_mark)/10.0,(cur->data.graduate)?"Dang hoc":"Nghi");
    }
    cout<<"\t\t\t============================================================================="<<endl;
}
bool check_seach(char hint[], char idex[]){
    int couting=0;
    char a[30];
    strcpy(a,idex);
    strlwr(a);
    for(int i=0;i<strlen(a);i++){
        if(hint[couting]==a[i])
            couting++;
        if(couting==strlen(hint))
            return true;
    }
    return false;
}