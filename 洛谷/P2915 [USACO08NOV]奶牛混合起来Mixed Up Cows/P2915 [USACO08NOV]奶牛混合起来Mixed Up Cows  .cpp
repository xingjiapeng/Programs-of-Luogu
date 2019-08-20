#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 16;

int n;
int k;
int s[N + 5];

ll ans;
ll f[1 << 20][N + 5];

int main(){
	cin >> n;
	cin >> k;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	f[0][0] = 1;
	int state_max = (1 << n) - 1;
	for(int state = 1; state <= state_max; state++)
		for(int i = 1; i <= n; i++){
			if((state & 1 << (i - 1))){
				int state_old = state ^ (1 << (i - 1));
				if(state_old == 0)
					f[state][i] += f[state_old][0];
				for(int j = 1; j <= n; j++)
					if((state_old & 1 << (j - 1))){
						if(abs(s[i] - s[j]) <= k)
							continue;
						f[state][i] += f[state_old][j];
					}
			}		
			if(state == state_max)
				ans += f[state][i];			
		}
	cout << ans << endl;
	return 0;
}