#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
class CanBo{
	public:
		int ma;
		string hoten;
		string phong;
		string chucvu;
		double hsl;
	public:
		CanBo(){}
		CanBo(int _ma, string _hoten, string _phong, string _chucvu, double _hsl)
		{
			ma=_ma;
			hoten=_hoten;
			phong=_phong;
			chucvu=_chucvu;
			hsl=0;
		}
		void xuat1canbo()
		{
			cout<<"||"<<setw(3)<<ma<<"||"<<setw(25)<<hoten<<"||"<<setw(10)<<phong<<"||"<<setw(20)<<chucvu<<"||"<<setw(5)<<hsl;
		}
		double tinhluong()
		{
			return hsl*1350000;
		}
		double gethsl()
		{
			return hsl;
		}
		string getchucvu()
		{
			return chucvu;
		}
		string getphong()
		{
			return phong;
		}		
		string gethoten()
		{
			return hoten;
		}
 
};
class QuanLy{
	list<CanBo> ds;
	public:
		void nhapds(){	
			int t;
			int i=0;
			cout<<"Moi nhap danh sach:\n";	
			do{
				cout<<"Moi nhap can bo thu "<<i<<endl;
				CanBo canbo;
				fflush(stdin);
				cout<<"Moi nhap ma cua can bo: ";
				cin>>canbo.ma;
				t = canbo.ma;
				if (t<=0) break;
				cout<<"Moi nhap ho ten cua can bo: ";
				fflush(stdin);
				getline(cin,canbo.hoten);
				cout<<"Moi nhap phong ban cua can bo: ";
				fflush(stdin);
				getline(cin,canbo.phong);
				cout<<"Moi nhap chuc vu cua can bo: ";
				fflush(stdin);
				getline(cin,canbo.chucvu);
				cout<<"Moi nhap he so luong cua can bo: ";
				cin>>canbo.hsl;
				ds.push_back(canbo);
				i++;
			} while(t>0);
		}
		void xuatds()
		{
			cout<<"======================================================================================="<<endl;
			cout<<"||"<<setw(3)<<"Ma"<<"||"<<setw(25)<<"ho ten"<<"||"<<setw(10)<<"phong"<<"||"<<setw(20)<<"chuc vu"<<"||"<<setw(5)<<"hsl"<<"||"<<setw(10)<<"Luong"<<"||"<<endl;
			cout<<"======================================================================================="<<endl;
			CanBo A;
			for(auto A:ds)
			{
				A.xuat1canbo();
				cout<<"||"<<setw(10)<<A.tinhluong()<<"||"<<endl;				
			}
			cout<<"======================================================================================="<<endl;
		} 
		void them1canbo()
		{
			cout<<"Moi nhap thong tin can bo can chen: \n";
			CanBo A;
			fflush(stdin);
			cout<<"Moi nhap ma cua can bo: ";
			cin>>A.ma;
			cout<<"Moi nhap ho ten cua can bo: ";
			fflush(stdin);
			getline(cin,A.hoten);
			cout<<"Moi nhap phong ban cua can bo: ";
			fflush(stdin);
			getline(cin,A.phong);
			cout<<"Moi nhap chuc vu cua can bo: ";
			fflush(stdin);
			getline(cin,A.chucvu);
			cout<<"Moi nhap he so luong cua can bo: ";
			cin>>A.hsl;			 
			int x; 
			cout<<"Moi nhap vi tri can them: ";
			cin>>x; //neu x lon hon so phan tu cua list thi tu dong chen xuong cuoi cung
			int dem=0;
			cout<<"\n-----------Danh sach can bo sau khi them 1 can bo:-------------\n";
			list<CanBo>::iterator it;
			for(it=ds.begin();it!=ds.end();it++)	
			{
				dem++;
				if(dem==x)// tim gia tri cua phan tu co vi tri thu x gan vao it 
					break;
			}		
			ds.insert(it,A);	 // chen len trc it
		}
		void intheoluong()
		{
			int dem=0;
			CanBo A;
			cout<<"\n-----------Danh sach can bo co he so luong >=4.4:-------------\n";
			for(auto A:ds)
			{
				if(A.gethsl()>=4.4)
				{
					A.xuat1canbo();
					cout<<"Luong: "<<A.tinhluong()<<endl;
					dem++;	
				}
					
			}
			if(dem==0)
				cout<<"\nKhong co can bo nao co he so luong >=4.4";
		}
		void intheochucvu()
		{
			int dem=0;
			string cv;
			cout<<"--------------------\nMoi nhap chuc vu can tim: ";
			fflush(stdin);
			getline(cin,cv);
			CanBo A;
			cout<<"\n-----------Danh sach can bo co chuc vu nhu tim kiem:-------------\n";
			for(auto A:ds)
			{
				if(A.getchucvu()==cv)
				{
					A.xuat1canbo();
					cout<<"Luong: "<<A.tinhluong()<<endl;	
					dem++;
				}	
			}	
			if(dem==0)
				cout<<"\nKhong co can bo nao co chuc vu nhu tim kiem\n";		
		} 
		void hslvachucvu()
		{
			int dem=0;
			string pb;
			cout<<"--------------------\nMoi nhap phong ban can tim: ";
			fflush(stdin);
			getline(cin,pb);
			double x;
			cout<<"Moi nhap he so luong can tim: ";
			cin>>x;
			CanBo A;
			cout<<"\n-----------Danh sach can bo co he so luong va phong ban nhu tim kiem:-------------\n";
			for(auto A:ds)
			{
				if(A.getphong()==pb && A.gethsl()==x)
				{
					A.xuat1canbo();
					cout<<"Luong: "<<A.tinhluong()<<endl;	
					dem++;
				}	
			}
			if(dem==0)
				cout<<"\nKhong co can bo nao co he so luong va phong ban nhu tim kiem";			
		}
void tach_ten(string source, string &hodem, string &ten){
			for(int i=0;i<source.size();i++){
				if(source[i]!=' ')
					continue;
				else{
                    hodem=source.substr(0,i);
					ten=source.substr(i+1);
                    break;
                }
			}
}
bool check_cmp(string A, string B){
				string hodem_a;
				string ten_a;
				string hodem_b;
				string ten_b;
				tach_ten(A,hodem_a,ten_a);
				tach_ten(B,hodem_b,ten_b);
				if(ten_a==ten_b){
					if(hodem_a>hodem_b)
						return true;
					else
					 	return false;
				}
				else{
					if(ten_a>ten_b)
						return true;
					else	return false;
				}
		}
void sapxep(){
            list<CanBo>::iterator i = ds.begin();
            i++;
			for (;i!=ds.end(); i++){
				list<CanBo>::iterator j=i;
				while(j!=ds.begin()){
                    list<CanBo>::iterator prev=j;
                    prev--;
					string A=prev->hoten;
					string B=j->hoten;
					if(check_cmp(A,B)){
					CanBo c;
					c=*(j);
					*(j)=*(prev);
					*(prev)=c;
					// swap(j,prev);
					j--;
					}
					else break;
				}
			}
		}
};


int main(){
	QuanLy manager;
	manager.nhapds();
	cout<<"\n-----------Danh sach can bo:-------------\n";
	manager.xuatds();
	// manager.them1canbo();
	// manager.xuatds();	
	// manager.intheoluong();
	// manager.intheochucvu();
	// manager.hslvachucvu();
	// cout<<"\n-----------Danh sach can bo sau khi sap xep theo ten:-------------\n";
	manager.sapxep();
	manager.xuatds();	

}

