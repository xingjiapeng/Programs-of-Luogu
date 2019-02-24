#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int m,n,ans=INT_MAX;
int  maps[1005][1005];
bool book[1005][1005];
int remem[1005][1005][3];
void finds(int x,int y,int gold,int last){
	//last 如果上次是零却变色了
	//last记录的就是这个新的颜色 
	if(x==m&&y==m){
		ans=min(ans,gold);
		return;
	}
	if(gold>=ans) return;
	for(int i=0;i<4;++i){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(nx<1||ny<1||nx>m||ny>m) continue;
		if(book[nx][ny]) continue;
		if(remem[nx][ny][last<0?maps[x][y]:last]<gold) continue;
		remem[nx][ny][last<0?maps[x][y]:last]=gold;
		book[nx][ny]=1;					
		if((last<0?maps[x][y]:last)==maps[nx][ny])
			finds(nx,ny,gold,-1);
		else if(maps[nx][ny]==2){
			if(last<0)
				finds(nx,ny,gold+2,maps[x][y]);	
		}
		else
			finds(nx,ny,gold+1,-1);
		book[nx][ny]=0;
	}
	return;
}
int main(){
	cin>>m>>n;
	for(int i=0;i<=m+1;++i)
		for(int j=0;j<=m+1;++j){
			maps[i][j]=2;
			for(int k=0;k<3;k++)
				remem[i][j][k]=INT_MAX;
		}
	int x,y,c;
	for(int i=1;i<=n;++i){
		cin>>x>>y>>c;
		maps[x][y]=c;
	}
	book[1][1]=1;
	finds(1,1,0,-1);
	cout<<(ans==INT_MAX?-1:ans);
	return 0;
}
