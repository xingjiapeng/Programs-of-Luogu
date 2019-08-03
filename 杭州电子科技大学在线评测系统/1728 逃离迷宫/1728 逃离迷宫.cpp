//Create in Dev-C++ 5.11
//http://acm.hdu.edu.cn/showproblem.php?pid=1728
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int n,m;
char map[105][105];
int mem[105][105];
bool flag;
int turn,startx,starty,endx,endy;
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void finds(int x,int y,int s){
	if(x==endx&&y==endy){
		if(mem[x][y]<=turn) flag=1;
		return;
	}
	if(mem[x][y]>turn) return;
	if(mem[x][y]==turn&&x!=endx&&y!=endy)
		return;
	for(int i=0;i<4;i++){
		int nx=x+dir[i][0];
		int ny=y+dir[i][1];
		if(map[nx][ny]=='*') continue;
		if(mem[x][y]>mem[nx][ny]) continue;
		if(s!=-1&&mem[x][y]+1>mem[nx][ny]&&i!=s)
			continue;
		mem[nx][ny]=mem[x][y];
		if(i!=s&&s!=-1) mem[nx][ny]++;
		finds(nx,ny,i);
		if(flag) return;
	}
	return;
}
int main(){
	int S;
	cin>>S;
	while(S--){
		flag=0;
		cin>>n>>m;
		memset(map,'*',sizeof(map));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
				mem[i][j]=INT_MAX;			
			}
		cin>>turn>>starty>>startx>>endy>>endx;
		mem[startx][starty]=0;
		finds(startx,starty,-1);
		if(flag) cout<<"yes\n";
		else     cout<<"no\n";
	}
	return 0;
} 
