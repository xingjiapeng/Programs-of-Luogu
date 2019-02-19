#include <iostream>
#include <cstdio>
#define N 1005
using namespace std;
int a[10],total,n; 
int w[7]={0,1,2,3,5,10,20};
bool dp[10][N],s;
int main(){
    for(int i=1;i<=6;i++){
        cin>>a[i];
        n+=(a[i]>0?w[i]*a[i]:0);
    }
    for(int i=0;i<=6;i++) dp[i][0]=1;  
    for(int i=1;i<=6;i++){
        for(int j=1;j<=n;j++){ 
            s=0;
            for(int k=a[i];k>=0;--k)
                if(dp[i-1][j-k*w[i]]>0){s=1; break;}
            dp[i][j]=s;
        }
    }
    for(int i=1;i<=n;i++)
        if(dp[6][i]) total++;
    printf("Total=%d",total);
    return 0;
}
