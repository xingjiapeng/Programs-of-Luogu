#include <iostream>

using namespace std;

typedef long long ll;

const ll N = 1e6;

bool flag;

ll n;         //n个小朋友
ll p;         //对 p 取模
ll ans;
ll a[N + 5];
ll dp[N + 5]; //到a[i]的最大值
ll dp2[N + 5];

int main(){
	cin >> n;
	cin >> p;
	ans = -1e9;
	for(ll i = 1; i <= n; i++)
		cin >> a[i];
	dp[1] = a[1];
	for(ll i = 2; i <= n; i++)
		dp[i] = max(dp[i - 1] + a[i], a[i]);
	for(ll i = 2; i <= n; i++)
		dp[i] = max(dp[i], dp[i - 1]);
	dp2[1] = a[1];
	dp2[2] = dp2[1] + dp[1];
	ans = dp2[1];
	for(ll i = 3; i <= n; i++){
		if(dp[i - 1] + dp2[i - 1] < 0 && dp2[i - 1] > 0)
			flag = true;
		if(flag)
			dp2[i] = (dp2[i - 1] % p + dp[i - 1]) % p;
		else
			dp2[i] = max(dp2[i - 1] + dp[i - 1], dp2[i - 1]);
		ans = max(ans, dp2[i]);
	}
	if(flag)
		cout << dp2[n] % p << endl;
	else
		cout << ans % p << endl;
	return 0;
}
