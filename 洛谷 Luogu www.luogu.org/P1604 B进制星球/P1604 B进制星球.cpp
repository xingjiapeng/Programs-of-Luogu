#include <iostream>
#include <cstring>
#define S 2005
using namespace std;
int a[S],b[S],ass[S],bss[S],x;
char va[S];
int main(){
	scanf("%d%s",&x,&va);
	int as=strlen(va);
	for(int i=1;i<=as;i++)
		a[i]=((va[i-1]>='A'&&va[i-1]<='Z')?va[i-1]-55:va[i-1]-'0');
	scanf("%s",&va);
	int bs=strlen(va);
	for(int i=1;i<=bs;i++)
		b[i]=((va[i-1]>='A'&&va[i-1]<='Z')?va[i-1]-55:va[i-1]-'0');
	int jin=0;
	int k=max(as,bs);
	for(int i=1,j=as;j;i++,j--)
		ass[i]=a[j];
	for(int i=1,j=bs;j;i++,j--)
		bss[i]=b[j];
	for(int i=1;i<=k;i++){
		ass[i]=ass[i]+bss[i]+jin;
		jin=ass[i]/x;
		ass[i]%=x;
	}
	if(jin!=0)
		{k++;ass[k]=jin;}
	bool flag=true; 
	for(int i=k;i;i--){
		if(flag&&ass[i]!=0) flag=false;
		if(!flag) cout<<char(ass[i]<10?ass[i]+'0':ass[i]+55);
	} 
	if(flag) cout<<0;
	return 0;
}
