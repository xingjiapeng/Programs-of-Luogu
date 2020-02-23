#include <iostream>
using namespace std;
int a[1001][1001];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,t;
long long counter;
int startx,starty,endx,endy;
inline void finds(int x,int y){
	if(x==endx&&y==endy){
		counter++;
		return;
	}
	//cout<<x<<' '<<y<<endl;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(nx>n||ny>m||nx<1||ny<1) continue;
		if(a[nx][ny]==1) continue;
		a[nx][ny]=1;
		finds(nx,ny);
		a[nx][ny]=0;
	}
	return;
}
int main(){
	cin>>n>>m>>t;
	cin>>startx>>starty>>endx>>endy;
	a[startx][starty]=1;
	int x,y;
	for(int i=1;i<=t;i++){
		cin>>x>>y;
		a[x][y]=1;
	}
	x=startx;
	y=starty;
	finds(x,y);
	cout<<counter<<endl;
	return 0;
}