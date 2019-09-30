#include <iostream>
using namespace std;
int main(){
	int jin=0,ma=0,f,x;
	bool flag=true;
	for(int i=1;i<=12;i++){
		cin>>x;
		jin=jin+300;
		//cout<<jin<<" ";
		f=jin-x;
		//cout<<f<<" ";
		if(f<0){
			cout<<-i<<endl;
			flag=false;
			break;
		}
		jin=jin-(f/100)*100;
		ma=ma+(f/100)*100;
		//cout<<jin<<" "<<ma<<" ";
		jin-=x; 
		//cout<<jin<<endl;
	}
	if(flag) cout<<jin+float(ma)*1.2<<endl;
	return 0;
}
