#include <iostream>
#include <cstring>
using namespace std;
int main(){
	char a[6];
	char b[6];
	cin>>a>>b;
	long long as=1,bs=1;
	for(int i=0;i<strlen(a);i++){
		as*=a[i]-'A'+1;
	}
	for(int i=0;i<strlen(b);i++){
		bs*=b[i]-'A'+1;
	}
	if(as%47==bs%47) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
}
