#include <iostream>
using namespace std;
int main(){
	char p;
	int a,b,c;
	char d;
	int intd;
	cin>>a>>p>>b>>p>>c>>p>>d;
	if(d>='0'&&d<='9') intd=d-'0';
	else intd=10;
	int ans=0;
	ans=ans+a*1;
	ans=ans+b/100*2+b/10%10*3+b%10*4;
	ans=ans+c/10000*5+c/1000%10*6+c/100%10*7+c/10%10*8+c%10*9;
	if(ans%11==intd) cout<<"Right"<<endl;
	else{
		cout<<a<<p<<b<<p<<c<<p;
		if(ans%11<10) cout<<ans%11<<endl;
		else cout<<'X'<<endl;
	}
	return 0;
} 
