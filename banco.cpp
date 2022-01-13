#include <iostream>
#include <fstream>
#include <time.h>
#include <conio.h>
using namespace std;
void slove(int const n){
	int stone[n];
	for(int i=0;i<n;i++){
		cin>>stone[i];
	}
	long long max_square=0;
	for(int i=0;i<n;i++){
		long long square=0;
		int min_high=stone[i];
		for(int j=i;j<n;j++){
			if(stone[j]<min_high)
				min_high=stone[j];
			if(min_high*(n-j)+square<=max_square)
				break;
			if((j-i+1)*min_high>max_square)
				square=(j-i+1)*min_high;
		}
		if(square>max_square)
			max_square=square;
	}
	cout<<max_square<<endl;
	// getch();
}
int main(){
	// freopen("data.txt","w",stdout);
	// for(int i=0;i<100;i++){
	// 	int n=rand();
	// 	cout<<n<<" ";
	// 	for(int j=0;j<n;j++){
	// 		int c=rand();
	// 		if(j!=n-1){
	// 			cout<<c<<' ';
	// 		}
	// 		else cout<<c<<"\n";
	// 	}
	// }
	// cout<<0;
	freopen("data.txt","r",stdin);
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;
		slove(n);
	}
	return 0;
}
