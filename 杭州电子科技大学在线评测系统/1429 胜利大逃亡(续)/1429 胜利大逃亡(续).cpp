#include <iostream>
#include <queue> 
#include <cstring>
#define min(x,y) x<y?x:y
using namespace std;
struct node{
    int x,y;
    int k,t;    
};
const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m,t;
char maps[25][25];
int bk[25][25][1030];
int ans;
void finds(int x,int y,int ex,int ey){
    queue<node> q;
    node s;
    s.x=x;s.y=y;s.k=s.t=0;
    q.push(s);
    while(!q.empty()){
        s=q.front();q.pop();
        for(int i=0;i<4;i++){
            int nx=s.x+dir[i][0];
            int ny=s.y+dir[i][1];
            int nk=s.k;
            //continue 部分 
            if(nx==ex&&ny==ey) {
                if(s.t+1<t)
                    ans=s.t+1;
                return;
            }
            if(s.t+1>=t)
                continue;
            if(maps[nx][ny]=='*')
                continue;
            if(bk[nx][ny][nk]<=s.t+1)    
                continue;
            if(maps[nx][ny]>='A'&&maps[nx][ny]<='J'){
                int f=1;
                f=(f<<(maps[nx][ny]-'A'));
                f=(f&nk);
                if((f>>(maps[nx][ny]-'A'))==0)
                   continue;
            }
            //拿钥匙部分  
            if(maps[nx][ny]>='a'&&maps[nx][ny]<='j'){
                int f=1;
                f=(f<<(maps[nx][ny]-'a'));
                nk=(f|nk);
            }
            //入队部分  
            node g;
            g.x=nx;g.y=ny;g.t=s.t+1;g.k=nk;
            bk[nx][ny][nk]=s.t+1;
            q.push(g);
        }
    }
    return;
}
int main(){
    int sx,sy,ex,ey;
    while(cin>>n>>m>>t){
        memset(maps,'*',sizeof(maps));
        ans=9999999;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>maps[i][j];
                if(maps[i][j]=='@'){//找入口  
                    sx=i;
                    sy=j;    
                }
                if(maps[i][j]=='^'){//找出口  
                    ex=i;
                    ey=j;
                }
            }
        memset(bk,0x3f,sizeof(bk));
        finds(sx,sy,ex,ey); 
        cout<<(ans==9999999?-1:ans)<<endl;
    }
    return 0;    
}
