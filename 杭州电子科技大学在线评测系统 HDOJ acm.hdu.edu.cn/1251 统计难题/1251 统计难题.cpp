#include <cstring>
#include <iostream>
using namespace std;
const int N=1000005;
int ch[N][30];
char s[12];
int val[N];
int size,ans;
int index(char c){
    return c-'a';
}
inline void input(char s[]){
    int u=0,n=strlen(s);//每次从根节点开始  
    for(int i=0;i<n;i++){
        int c=index(s[i]);
        if(!ch[u][c]){//如果不存在，那么新增节点 
            memset(ch[size],0,sizeof(ch[size]));
            ch[u][c]=size++;//新节点的编号  
        }
        u=ch[u][c];//沿着当前串向下走 
        val[u]++; //用过一次，增加一次  
    }
}
inline int find(char s[]){
    int u=0,n=strlen(s),c;
    for(int i=0;i<n;++i){
        c=index(s[i]);
        u=ch[u][c];
        if(!u) return 0;
    }
    return val[u];
}
int main(){
    size=1;
    memset(ch[0],0,sizeof(ch[0]));
    memset(val,0,sizeof(val));
    while(gets(s)&&s[0]>='a'&&s[0]<='z') input(s);
    while(gets(s)){
        ans=0;
        cout<<find(s)<<endl;
    }
    return 0;
}
