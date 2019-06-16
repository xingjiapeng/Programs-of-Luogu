#include <iostream>
using namespace std;
const int N=10000+5;
int n,m;
int a[N],s;
int now;
inline void up(int k){
    if(k==1) return;
    if(a[k-1]>a[k]){
        swap(a[k-1],a[k]);
        up(k-1);
    }
    return;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[++now];
        up(now);
    }
    while(now>1){
        a[now-1]=(a[now]+a[now-1])/m;
        now--;
        up(now);
    }
    cout<<a[1];
    return 0;
}
