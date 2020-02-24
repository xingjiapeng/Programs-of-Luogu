#include <iostream>
#define N 10005
using namespace std;
int n,m;
int a[N];
long long dp[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=a[i];j<=m;j++)
            dp[j]+=dp[j-a[i]]; 
    cout<<dp[m];
    return 0;
}