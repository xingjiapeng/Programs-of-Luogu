#include <iostream>

using namespace std;

typedef long long ll;

ll n;
ll ans;

int main(){
	cin >> n;
	//按约数种类统计 
	for(ll i = 1; i <= n; i++)
		ans += n / i;
	cout << ans << endl;
	return 0;
}