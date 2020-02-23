#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[1001];
int now;
string num[21]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
				"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
string num2[7]={"zero","a","both","another","first","second","third"};
int main(){
	string x;
	int k;
	while(cin>>x){
		k=100;
		if(x=="."){
			break;
		}
		for(int i=0;i<x.length();i++){
			if(x[i]>='A'&&x[i]<='Z') x[i]+='a'-'A';
		}
		for(int i=1;i<=20;i++){
			if(x==num[i]){
				k=i;
				break;
			}
		}
		for(int i=1;i<=6;i++){
			if(x==num2[i]){
				k=i;
				break;
			}
		}
		if(k>20) continue;
		k=k*k%100;
		now++;
		a[now]=k;
	}
	sort(a+1,a+now+1);
	bool flag=false;
	for(int i=1;i<=now;i++){
		if(i==1&&a[i]!=0){
			cout<<a[i];
			flag=true;
			continue;
		}
		if(i!=1&&a[i]<10){
			cout<<'0'<<a[i];
			flag=true;
			continue;
		}
		cout<<a[i];
		flag=true;
	}
	if(!flag) cout<<0;
	return 0;
} 