#include <iostream>
using namespace std;
long long a,b;
unsigned long long s[100001];
int main(){
	cin>>a>>b;
	s[1]=1;
	s[0]=1;
	for(long long i=2;i<=a;i++){
		for(long long j=min(i,b);j>=1;j--){
			//if(j==0) break;
			s[i]+=s[i-j];	
			s[i]%=100003;
		}
		//cout<<s[i]<<endl;
	}
	cout<<s[a]%100003<<endl;
	return 0;
}
