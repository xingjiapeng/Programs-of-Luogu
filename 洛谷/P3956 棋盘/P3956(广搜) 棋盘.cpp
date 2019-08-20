#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
struct node{
	int x,y,colour;
	int gold,nc;
};
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int m,n,ans=INT_MAX;
int  maps[1005][1005];
int book[1005][1005][4];
void finds(){
	queue<node> q;
	node s;
	s.x=s.y=1;
	s.colour=maps[1][1];
	s.gold=0;
	s.nc=-1;
	q.push(s);
	while(!q.empty()){
		s=q.front();q.pop();
		if(s.x==m&&s.y==m){
			ans=min(ans,s.gold);
			continue;
		}
		if(s.gold>=ans)
			continue;
		for(int i=0;i<4;++i){
			int nx=s.x+dir[i][0];
			int ny=s.y+dir[i][1];
			int nnc,ng;
			if(nx<1||ny<1||nx>m||ny>m) continue;
			if(book[nx][ny][i]<=s.gold) continue;
			if((s.nc==-1?s.colour:s.nc)==maps[nx][ny])
				nnc=-1,ng=s.gold;
			else if(maps[nx][ny]==2){
				if(s.nc==-1) nnc=s.colour,ng=s.gold+2;
				else continue;
			}
			else nnc=-1,ng=s.gold+1;
			book[nx][ny][i]=s.gold;
			node g;
			g.x=nx,g.y=ny,g.colour=maps[nx][ny];
			g.gold=ng,g.nc=nnc;
			q.push(g);

		}
	}
	return;
}
int main(){
	cin>>m>>n;
	for(int i=0;i<=m+1;++i)
		for(int j=0;j<=m+1;++j){
			maps[i][j]=2;
			for(int k=0;k<4;++k)
				book[i][j][k]=INT_MAX;
		}
	int x,y,c;
	for(int i=1;i<=n;++i){
		cin>>x>>y>>c;
		maps[x][y]=c;
	}
	for(int i=0;i<4;i++)
		book[1][1][i]=1;
	finds();
	cout<<(ans==INT_MAX?-1:ans);
	return 0;
}
