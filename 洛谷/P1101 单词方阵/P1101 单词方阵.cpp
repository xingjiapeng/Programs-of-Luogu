#include <iostream>
#include <cstring>
using namespace std;
int n;
char a[1001][1001];
char b[1001][1001];
int nx,ny;
int dir[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
char yizhong[9]="yizhong";
bool flag;
inline void finds(int x,int y,int f1,int f2,int now){
	if(a[x+f1][y+f2]==yizhong[now-1]){
		if(now-1==6){
			flag=true;
			b[x+f1][y+f2]=yizhong[now-1];
			return;
		}
		finds(x+f1,y+f2,f1,f2,now+1);
		if(flag) b[x+f1][y+f2]=yizhong[now-1];
	}
	return;
}
int main(){
	memset(b,'*',sizeof(b));
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]=='y'){
				for(int k=0;k<8;k++){
					nx=dir[k][0];
					ny=dir[k][1];
					flag=false;
					finds(i,j,nx,ny,2);
					if(flag) b[i][j]=yizhong[0];
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout<<b[i][j];
			}
			cout<<endl;
	}
	return 0;
}
