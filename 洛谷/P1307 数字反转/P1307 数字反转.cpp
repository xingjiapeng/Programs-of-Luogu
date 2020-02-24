#include <iostream>
#include <cstring>
using namespace std;
char a[1000000001];
int main(){
	cin>>a;
	if(a[0]=='-'){
		cout<<'-';
		bool flag=false;
		for(int i=strlen(a)-1;i>=1;i--){
			if(a[i]!='0'&&flag==false){
				flag=true;
			}
			if(a[i]=='0'&&flag==false) continue;
			cout<<a[i];
		}
	}
	else{
		bool flag=false; 
		for(int i=strlen(a)-1;i>=0;i--){
			if(a[i]!='0'&&flag==false){
				flag=true;
			}
			if(a[i]=='0'&&flag==false) continue;
			cout<<a[i];
		}	
	}
	return 0;
} 