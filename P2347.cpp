#include<bits/stdc++.h>
using namespace std;
bool f[1001]; //f数组存放第k+w[i]种重量有没有被称出来过
int c[7],w[7] = {0,1,2,3,5,10,20}; // 这里的0一定要注意！！数组的下标从0开始
int main(){
    for(int i = 1;i<=6;i++)
        scanf("%d",&c[i]);
    memset(f,0,sizeof(f));
    f[0] = 1; //初始化非常非常重要！！
    for(int i = 1;i<=6;i++)
        for(int j = 1;j<=c[i];j++) // 每一种质量的砝码进行枚举
            for(int k = 1000;k>=0;k--){ //k表示当前质量
                if(f[k]&&k+w[i]<=1000)
                    f[k+w[i]] = 1;  // 如果第k+w[i]个没有称出来过就标记上
            }
        int ans = 0;
        for(int i = 1;i<=1000;i++)//注意这里从1开始
        {
            if(f[i]) ans++;
        }
        printf("Total=%d",ans); //输出的格式要注意
        return 0;
}
