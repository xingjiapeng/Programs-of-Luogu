#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
const int R = 150;

int n; //要刷的题 
int m; //要写的作业 
int k; //及格分数 
int r; //剩余时间 
int a[N + 5]; //要刷的题的时间 
int b[N + 5]; //要写的作业的时间 
int c[N + 5]; //要写的作业的分值 
int dp[R + 5];

int main(){
	cin >> n;
	cin >> m;
	cin >> k;
	cin >> r;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	for(int i = 1; i <= m; i++)
		cin >> c[i];
	for(int i = 1; i <= m; i++)
		for(int j = r; j >= b[i]; j--)
			dp[j] = max(dp[j], dp[j - b[i]] + c[i]);		
	for(int i = 1; i <= r; i++)
		if(dp[i] > k){
			r -= i;
			break;
		}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		r -= a[i];
		if(r < 0){
			cout << i - 1 << endl;
			break;
		}
	}
	return 0;
}
