#include <iostream>
#include <climits>
using namespace std;
int maps[10][10]; 
int a[10][10];
int memroad[10][10][10][10];
int n,m;
int sx,sy,ex,ey,rwx,rwy;

int mins(int as,int b,int c,int d){//四数中求最小  
    int s=as;
    if(b<s) s=b;
    if(c<s) s=c;
    if(d<s) s=d;
    return s;    
}
void th(int x,int y){ //看人能走到哪  
    if(a[x][y]!=0) return;
    a[x][y]=4;
    th(x+1,y);
    th(x-1,y);
    th(x,y+1);
    th(x,y-1);
    return;
}
void finds(int x,int y,int steps,int xs,int ys){
    int ab[10][10];
    if(a[x][y]!=0) return;
    if(memroad[x][y][xs][ys]<=steps) return;
    memroad[x][y][xs][ys]=steps;//记下现在的步数  
    if(x==ex&&y==ey) return;
    a[x][y]=2;
    th(xs,ys);
    a[x][y]=0;                  //看人能走到哪  
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ab[i][j]=a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            a[i][j]=maps[i][j];
        }
    //如果人可以到对面，那么就走  
    if(ab[x+1][y]==4) finds(x-1,y,steps+1,x,y);
    if(ab[x-1][y]==4) finds(x+1,y,steps+1,x,y);
    if(ab[x][y+1]==4) finds(x,y-1,steps+1,x,y);
    if(ab[x][y-1]==4) finds(x,y+1,steps+1,x,y);
    return;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                maps[i][j]=a[i][j]=1;
                for(int k=0;k<9;k++)
                    for(int l=0;l<9;l++)
                        memroad[i][j][k][l]=INT_MAX;     //前两个下表： 箱位 
                                                         //后两个下标： 人位          
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                cin>>maps[i][j];
                if(maps[i][j]==2){//看起点终点人的位置 
                    sx=i;sy=j;
                    maps[i][j]=0;
                } 
                if(maps[i][j]==3){
                    ex=i;ey=j;
                    maps[i][j]=0;
                }
                if(maps[i][j]==4){
                    rwx=i;rwy=j;
                    maps[i][j]=0;
                } 
                a[i][j]=maps[i][j];
            }
        finds(sx,sy,0,rwx,rwy);
        int s=mins(memroad[ex][ey][ex-1][ey],
                   memroad[ex][ey][ex+1][ey],
                   memroad[ex][ey][ex][ey-1],
                   memroad[ex][ey][ex][ey+1]);
        if(s==INT_MAX)
            cout<<-1<<endl;
        else
            cout<<s<<endl;
    }
    return 0;    
}
