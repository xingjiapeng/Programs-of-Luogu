#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e3;

int n;
int a[N + 5];
int dp[N + 5];
int ans;

int main(){
    while(cin >> n){
        ans = -1;
        if(!n) break;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i] = a[i];
            for(int j = 1; j < i; j++)
                if(a[i] > a[j])
                    dp[i] = max(dp[i], dp[j] + a[i]);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
