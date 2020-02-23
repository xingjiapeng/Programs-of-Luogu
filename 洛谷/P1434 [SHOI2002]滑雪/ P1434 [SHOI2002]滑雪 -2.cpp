#include <iostream>
#define N 105
using namespace std;
int ans;
int n,m;
int maps[N][N],mems[N][N];
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
inline int finds(int x,int y){
    if(mems[x][y]>0) return mems[x][y];
    int t=1,tmp;
    for(int i=0;i<4;++i){
    	int nx=x+dir[i][0];
    	int ny=y+dir[i][1];
    	if(nx<0||ny<0||nx>n||ny>m)
			continue;
		if(maps[x][y]>=maps[nx][ny])
			continue;
		tmp=finds(nx,ny)+1;
		if(tmp>t) t=tmp;
	}
	mems[x][y]=t;
	return t;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>maps[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            int k=finds(i,j);
			mems[i][j]=k;
			if(k>ans) ans=k;
		}
    cout<<ans;
    return 0;
}