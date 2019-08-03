#include <iostream>

using namespace std;

const int N = 1e4;

int n;
int a[N + 5];
int dp[N + 5];

int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i > 1)
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		else
			dp[i] = a[i];
	}
	cout << dp[n] << endl;
	return 0;
}
