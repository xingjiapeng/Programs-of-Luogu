#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
const int N=100+5;
int n,t;
double vr,vt1,vt2,a[N],dp[N],c,l; 
int main(){
    while(cin>>l>>n>>c>>t>>vr>>vt1>>vt2){
        for(int i=1;i<=n;i++)
            cin>>a[i];
        a[++n]=l+1;
        dp[0]=0;
        a[0]=0;
        for(int i=1;i<=n;++i){
            dp[i]=INT_MAX;
            for(int j=0;j<i;++j){
                double length=a[i]-a[j];
                double s=(length<=c?length/vt1:c/vt1+(length-c)/vt2);
                if(j>0) s+=t; 
                s+=dp[j]; 
                dp[i]=min(dp[i],s);
            }
        }
        cout<<(dp[n]<l/vr?"What a pity rabbit!":"Good job,rabbit!")<<endl;
    }
    return 0;    
}
