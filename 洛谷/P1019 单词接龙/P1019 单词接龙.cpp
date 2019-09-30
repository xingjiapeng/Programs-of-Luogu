#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

const int N = 45;

int n;
int ans;
char s;
bool bk[N + 5];
string a[N + 5], k, las;

void finds(int t){
	if(ans < k.length())
		ans = k.length();
	if(t == n) return;
	for(int i = 1; i <= n; i++){
		if(bk[i]) continue;
		int mins = min(k.length(), a[i].length()) - 1;
		for(int j = 1; j <= mins; j++){
			string x = a[i].substr(0, j);
			string y = k.substr(k.length() - j);
			if(x == y){
				string tmp = k;
				k += a[i].substr(j), bk[i] = 1;
				finds(t + 1);
				k = tmp, bk[i] = 0;
				break;
			}
		}
	}
	return;
}

int main(){
	cin >> n;
	n *= 2;
	for(int i = 1; i <= n; i+=2){
		cin >> a[i];
		a[i + 1] = a[i];
	}
	cin >> s;
	for(int i = 1; i <= n; i++)
		if(a[i][0] == s){
			memset(bk, 0, sizeof(bk));
			bk[1] = 1, k = a[i];
			finds(1);
		}
	cout << ans << endl;
	return 0;
}