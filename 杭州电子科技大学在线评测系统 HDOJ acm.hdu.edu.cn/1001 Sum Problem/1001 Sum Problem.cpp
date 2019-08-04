#include <iostream>
using namespace std;
int main(){
	long long n,ans;
	while(cin>>n){
		ans=0;
    	for(int i=1;i<=n;i++) ans+=i;
    	cout<<ans<<endl<<endl;              
	}
	return 0;    
}
