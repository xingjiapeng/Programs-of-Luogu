#include <iostream>
using namespace std;
int n,ans;
int vis[101],f[101],s[101];//横，主，副 
int v[101];
inline void finds(int x){
	if(x>n){
		ans++;
		if(ans>3) return;
		for(int i=1;i<=n;i++)
			cout<<v[i]<<' ';
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		if(f[x-i+n]==1||s[x+i]==1) continue;
		vis[i]=1;
		f[x-i+n]=s[x+i]=1;
		v[x]=i;
		finds(x+1);
		vis[i]=0;
		f[x-i+n]=s[x+i]=0;
	}
	return;
}
int main(){
	cin>>n;
	finds(1);
	cout<<ans;
	return 0;
}
