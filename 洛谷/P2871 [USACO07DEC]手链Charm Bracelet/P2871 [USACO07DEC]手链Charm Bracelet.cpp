#include <iostream>

using namespace std;

const int M = 12880;

int n; //物品个数 
int m; //背包大小 
int c; //物品重量 
int w; //物品价值 
int dp[M + 5];

int main(){
	cin >> n;
	cin >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> c; //物品的重量 
		cin >> w; //物品的价值 
		for(int  j = m; j >= c; j--)
			dp[j] = max(dp[j], dp[j - c] + w);
	}
	cout << dp[m] << endl;
	return 0;
}
