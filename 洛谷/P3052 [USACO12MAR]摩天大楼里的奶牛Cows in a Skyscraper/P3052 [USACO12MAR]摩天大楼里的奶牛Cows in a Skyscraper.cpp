#include <iostream>
#include <cstring>

using namespace std;

const int N = 18;

int n;
int w;
int a[N + 5];
int f[1 << 20];
int used[1 << 20];

int main(){
	cin >> n;
	cin >> w;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	memset(f, 0x3f, sizeof(f));
	memset(used, 0x3f, sizeof(used));
	f[0] = 1;
	used[0] = 0;
	for(int i = 1; i < (1 << n); i++)
		for(int j = 0; j < n; j++)
			if(i & (1 << j)){
				int old = i ^ (1 << j);
				if(used[old] + a[j + 1] <= w){
					if(f[old] == f[i])
						used[i] = min(used[i], used[old] + a[j + 1]);
					if(f[old] < f[i])
						f[i] = f[old], used[i] = used[old] + a[j + 1];
				}
				else{
					if(f[old] + 1 == f[i])
						used[i] = min(used[i], a[j + 1]);
					if(f[old] + 1 < f[i])
						f[i] = f[old] + 1, used[i] = a[j + 1];					
				}
			}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}