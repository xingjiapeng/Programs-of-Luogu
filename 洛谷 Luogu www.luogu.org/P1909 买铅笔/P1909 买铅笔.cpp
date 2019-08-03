#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

int main(){
	ll n;
  ll a;
  ll b;
  ll min;
  min = INT_MAX;
  ll f;
	cin >> n;
	for(int i = 1; i <= 3; i++){
		cin >> a;
    cin >> b;
		if(n % a == 0) f = (n / a) * b;
		else f = (n / a + 1) * b;
		//cout<<f<<" "<<f/b<<endl;
		if(f < min) min = f;
	}
	cout << min << endl;
	return 0;
}
