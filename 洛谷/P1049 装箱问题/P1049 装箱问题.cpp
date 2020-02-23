#include <iostream>
#include <algorithm>
using namespace std;
int n,all,k,a[31];
int low=20002;
bool cmp(int x,int y){
     return x>y;    
}
inline void finds(int s){
       if(k<0) return;
       if(k<low){
                 low=k;
       }
       for(int i=s+1;i<=n;i++){
               k-=a[i];
               finds(i);
               k+=a[i];     
       }
       return;
}
int main(){
    cin>>all>>n;
    for(int i=1;i<=n;i++)
            cin>>a[i];
    k=all;
    sort(a+1,a+n+1,cmp);
    finds(0);
    cout<<low<<endl;
    return 0;
}
