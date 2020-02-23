#include <iostream>
#include <string>
using namespace std;
int p1,p2,p3;
string s;
int l,k;
bool checker(int ks){
	if(s[ks-1]>=s[ks+1]) return 0;
	if(ks<=0) return 0;
	if(ks>=l) return 0;
	if(s[ks-1]=='-'||s[ks+1]=='-') return 0;
	if(s[ks-1]>='a'&&s[ks-1]<='z'){
		if(s[ks+1]>='a'&&s[ks+1]<='z')
			return 1;
		else
			return 0;
	}
	if(s[ks-1]>='0'&&s[ks-1]<='9'){
		if(s[ks+1]>='0'&&s[ks+1]<='9')
			return 1;
		else
			return 0;
	}
	return 1;
}
int main(){
	cin>>p1>>p2>>p3;
	cin>>s;
	l=s.length()-1,k=-1;
	while(k<l){
		k++;
		if(s[k]=='-'&&checker(k)&&k>0&&k<l){
			if(s[k+1]-1==s[k-1]) continue;
			if(p3==1)
				for(int i=s[k-1]+1;i<s[k+1];++i)
					for(int j=1;j<=p2;++j){
						if(p1==1) cout<<char(i);
						if(p1==2) cout<<char(i+(s[k-1]>='a'&&s[k-1]<='z'?'A'-'a':0));
						if(p1==3) cout<<'*';						
					}
			else
				for(int i=s[k+1]-1;i>s[k-1];--i)
					for(int j=1;j<=p2;++j){
						if(p1==1) cout<<char(i);
						if(p1==2) cout<<char(i+(s[k-1]>='a'&&s[k-1]<='z'?'A'-'a':0));
						if(p1==3) cout<<'*';						
					}
		}
		else cout<<s[k];
	}
	return 0;
}
