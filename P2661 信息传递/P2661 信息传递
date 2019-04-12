//XingJiapeng
//并查集：信息传递  NOIP2015 
//20190412205625 90 Pinots (洛谷)
//20190412210353 Accept    (洛谷) 
/*
有n个同学（编号为1到n）正在玩一个信息传递的游戏。
在游戏里每人都有一个固定的信息传递对象，
其中，编号为i的同学的信息传递对象是编号为Ti的同学。
游戏开始时，每人都只知道自己的生日。
之后每一轮中，
所有人会同时将自己当前所知的
生日信息告诉各自的信息传递对象
（注意：
可能有人可以从若干人那里获取信息， 
但是每人只会把信息告诉一个人，
即自己的信息传递对象）。
当有人从别人口中得知自 己的生日时，游戏结束。
请问该游戏一共可以进行几轮？
*/
#include <iostream>
#include <climits> 
using namespace std;
//f保存祖先节点，d保存到其祖先节点的路径长  
int f[200002],d[200002]; 
int n,minn,last;
int father(int x){
	//查找时沿途更新祖先节点和路径长 
	if(f[x]!=x){
		int last=f[x];//记录父节点（会在递归中更新）。 
		f[x]=father(f[x]);//更新祖先节点
		d[x]+=d[last]; //更新路径长 （原来连在父节点上） 
	}
	return f[x];
}
void check(int a,int b){//又检查又合并  
	int x=father(a),y=father(b);//查找祖先节点 
	if(x!=y) {f[x]=y;d[a]=d[b]+1;} //不相连，连接两点，更新父节点和路径长。 
	else minn=min(minn,d[a]+d[b]+1); //相连，则更新最小环长度。 
	return; 
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) f[i]=i; //祖先节点初始化为自己，路径长为0 
	minn=INT_MAX;
	int t;
	for(int i=1;i<=n;i++){
		cin>>t;
		check(i,t);//检查当前两点是否相连  
	}//这里i和t的顺序不能换。 
	cout<<minn;
	return 0;
} 
