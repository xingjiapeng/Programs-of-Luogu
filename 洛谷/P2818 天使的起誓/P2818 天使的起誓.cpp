#include <iostream>

using namespace std;

int n;
int m;
int ans;

char mm;

int main(){
	cin >> n;
	while(cin >> mm){
		if(mm < '0' || mm > '9')
			break;
		m = mm - '0';
		ans = (ans * 10 + m) % n;
	}
	if(ans == 0)
		cout << n << endl;
	else
		cout << ans << endl;
	return 0;
}
