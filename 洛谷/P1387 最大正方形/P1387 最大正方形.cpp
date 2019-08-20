#include <iostream>
using namespace std;
const int N=105;
int n,m,k;
int x,s[N][N];
int ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>x;
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;	
		}
	k=min(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int l=1;l<=k-(k==m?j:i)+1;l++){
				int x1=i,y1=j,x2=i+l-1,y2=j+l-1;
				if(x2>100||y2>100) continue;
				int v=s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
				if(v==l*l) ans=max(ans,l);
			}
	cout<<ans;
	return 0;
}
