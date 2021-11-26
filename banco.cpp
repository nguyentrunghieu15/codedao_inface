#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	int list[n];
	int max=0;
	for(int i=0;i<n;i++){
		cin>>list[i];
		if(list[i]>max)	
			max=list[i];
	}
	int *dynamic_list= new int [max+1];
	int *high;
	int couting=0;
	high=(int*)malloc(sizeof(int));
	for(int i=0;i<n;i++){
		if(dynamic_list[list[i]]!=1){
				high[couting]=list[i];
				high=(int*)realloc(high,sizeof(int)*)
			}
	{
}
