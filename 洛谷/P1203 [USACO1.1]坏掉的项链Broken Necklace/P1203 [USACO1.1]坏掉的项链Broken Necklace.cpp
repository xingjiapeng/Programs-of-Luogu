//邢家朋
#include <iostream>
#include <cstring>
using namespace std;
const int K=700+5;
int k,ans,first,last;
char a[K];
inline void mover(int ms){
	while(ms--)
		a[++last]=a[first++];
	return;
}
int main(){
	memset(a,'@',sizeof(a));
	cin>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	first=1,last=k;
	while(first<=k){
		int l1=-1,l2=-1,ms;
		int al1=a[first],al2=a[last];
		bool flag=1;
		for(int j=first+1;j<=last;j++){
			if(a[j]=='w'&&flag) ms=j-first,flag=0;
			if(a[j]!=al1&&a[j]!='w'){
				if(al1=='w') al1=a[j];
				else{
					l1=j-first;
					if(flag) ms=l1;
					break;					
				}
			}
		}
		if(l1==-1){
			cout<<k;
			return 0;
		}
		for(int j=last-1;j>=first;j--)
			if(a[j]!=al2&&a[j]!='w'){
				if(al2 =='w') al2=a[j];
				else{
					l2=last-j;
					break;				
				}
			}
		if(l1+l2<=k) ans=max(ans,l1+l2);
		mover(ms);
	}
	cout<<ans<<endl;
	return 0;
} 
