#include <iostream>
using namespace std;
int n,m,t;
int startx,starty,endx,endy;
int a[101][101];
int ans;
int dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
inline void finds(int x,int y){
	if(a[x][y]==1) return;	
	a[x][y]=1;
	if(x==endx&&y==endy){
		ans++;
		a[x][y]=0;
		return;
	}
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		finds(nx,ny);
	}
	a[x][y]=0;
	return;
}
int main(){
	cin>>n>>m>>t;
	cin>>startx>>starty>>endx>>endy;
	int x,y;
	for(int i=1;i<=t;i++){
		cin>>x>>y;
		a[x][y]=1;
	}
	for(int i=1;i<=m;i++) a[0][i]=1;
	for(int i=1;i<=n;i++){
		a[i][0]=1;
		a[i][m+1]=1;
	}
	for(int i=1;i<=m;i++) a[n+1][i]=1;
	finds(startx,starty);
	cout<<ans<<endl;
	return 0;
}