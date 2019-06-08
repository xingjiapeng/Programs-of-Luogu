#include <iostream>
using namespace std;
long long a[21][21];
int dir[8][2]={{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
int main(){
	int endx,endy,hx,hy;
	cin>>endx>>endy>>hx>>hy;
	a[0][0]=1;
	for(int i=0;i<=endx;i++){
		for(int j=0;j<=endy;j++){
			if(i==0&&j==0) continue;
			if(i==hx&&j==hy) continue;
			bool flag=false;
			for(int k=0;k<8;k++){
				if(i==hx+dir[k][0]&&j==hy+dir[k][1]){
					flag=true;
					break;
				}
			}
			if(flag) continue;
			int nx=i,ny=j-1;
			if(nx>=0&&ny>=0){
				a[i][j]+=a[nx][ny];
			}
			nx=i-1,ny=j;
			if(nx>=0&&ny>=0){
				a[i][j]+=a[nx][ny];
			}
		}
	}
	cout<<a[endx][endy]<<endl;
	return 0;
}
