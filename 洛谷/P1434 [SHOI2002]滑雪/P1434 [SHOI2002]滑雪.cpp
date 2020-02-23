#include <iostream>
#include <cstring>
#define N 105
using namespace std;
int ans;
int n,m;
int maps[N][N];
bool flag1[N][N];
bool flag2[N][N];
const int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int mems[N][N];
inline int reader(){
	int a=0; char c; bool b=true;
	while(c=getchar(),c<'0'||c>'9')
  		if(c=='-') b=!b;
	a=a*10+c-'0';
	while(c=getchar(),c>='0'&&c<='9')
		a=a*10+c-'0';
	return a*(b?1:-1);
}
void finds(int x,int y,int steps){
    if(mems[x][y]>=steps) return;
    mems[x][y]=steps,flag1[x][y]=1;
    bool f=0;
    for(int i=0;i<4;++i){
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(flag2[nx][ny]) continue;
        if(maps[nx][ny]>=maps[x][y]) continue;
        if(nx<1||ny<1||nx>n||ny>m) continue;
        flag2[nx][ny]=f=1;
        finds(nx,ny,steps+1);
        flag2[nx][ny]=0;
    }
    if(!f&&steps>ans)
        ans=steps;
    return;
}
int main(){
    n=reader(),m=reader();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            maps[i][j]=reader();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            if(flag1[i][j]) continue;
            memset(flag2,0,sizeof(flag2));
            flag2[i][j]=1;
            finds(i,j,1);
        }
    cout<<ans;
    return 0;
}