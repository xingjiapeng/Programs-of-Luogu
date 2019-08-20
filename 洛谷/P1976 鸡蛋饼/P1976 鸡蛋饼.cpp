#include <iostream>

using namespace std;

typedef long long ll;

const int MOD = 100000007;
const int N = 2999;

ll n;
ll c[N + 5];

int main(){
	cin >> n;
	c[0] = 1;
	for(int k = 1; k <= n; k++)
		for(int i = 0, j = k - 1; i < k, j >= 0; i++, j--)
			c[k] = (c[k] + c[i] * c[j]) % MOD;
	cout << c[n]; 
	return 0;
}
