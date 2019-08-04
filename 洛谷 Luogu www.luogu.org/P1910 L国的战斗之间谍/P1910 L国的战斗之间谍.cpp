#include <iostream>

using namespace std;

const int M = 1e3;
const int X = 1e3;

int n; //现在有的人选 
int m; //探查间谍能力 
int x; //现在所有的钱 
int a;
int b;
int c;
int dp[M + 5][X + 5];

int main(){
	cin >> n;
	cin >> m;
	cin >> x;
	for(int i = 1; i <= n; i++){
		cin >> a;
		cin >> b;
		cin >> c;
		for(int j = m; j >= b; j--)
			for(int k = x; k >= c; k--)
				dp[j][k] = max(dp[j][k], dp[j - b][k - c] + a);
	}
	cout << dp[m][x] << endl;
	return 0;
}
