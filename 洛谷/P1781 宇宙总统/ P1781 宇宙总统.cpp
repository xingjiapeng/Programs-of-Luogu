#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
inline bool cmp(string a,string b){
	if(a.length()!=b.length())
		return a.length()>b.length();
	else
		return a>b;
}
int main(){
	int n;
	cin>>n;
	string a[n+1],b[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(b[i]==a[1]){
			cout<<i<<endl<<a[1]<<endl;
			break;
		}
	}
	return 0;
} 