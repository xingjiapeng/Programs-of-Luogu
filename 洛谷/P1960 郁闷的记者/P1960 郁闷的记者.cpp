#include <iostream>
#include <queue>
using namespace std;
const int N = 5000 + 5;
int n, m;
bool have_other_ans;
queue<int> q, ans;
bool l[N][N]; bool flag[N];
int s[N];
void topo() {
	for (int i = 1; i <= n; i++)
		if (s[i] == 0) {
			q.push(i);
			flag[i] = true;
		}
	while (!q.empty()) {
		if (q.size() > 1) have_other_ans = 1;
		int k = q.front(); q.pop(); ans.push(k);
		for (int i = 1; i <= n; i++) {
			if (flag[i]) continue;
			if (l[k][i]) s[i]--;
			if (!s[i]) {
				q.push(i);
				flag[i] = true;
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		l[x][y] = 1,
		s[y]++;
	}
	topo();
	while (!ans.empty()) {
		cout << ans.front() << endl;
		ans.pop();
	}
	cout << have_other_ans << endl;
	return 0;
}
