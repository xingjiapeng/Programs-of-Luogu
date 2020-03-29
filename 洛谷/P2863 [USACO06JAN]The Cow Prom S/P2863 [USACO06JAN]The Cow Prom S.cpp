#include <iostream>
#include <stack>
using namespace std;
const int N = 1e4;
const int M = 1e5;
struct edge {
	int to, nxt;
}g[M + 5];
int n, m;
int fte[N + 5], gz;
int dfn[N + 5], low[N + 5];
int ans, now;
int num[N + 5], col[N + 5], col_num;
stack<int> s;

inline void addEdge(int x, int y) {
	g[++gz] = (edge){y, fte[x]};
	fte[x] = gz;
	return;
}

void finds(int x) {
	dfn[x] = low[x] = ++now;
	s.push(x);
	for (int i = fte[x]; i; i = g[i].nxt) {
		int kk = g[i].to;
		if (!dfn[kk]) {
			finds(kk);
			low[x] = min(low[x], low[kk]);
		}
		else if (!col[kk]) low[x] = min(low[x], dfn[kk]);		
	}
	if (low[x] != dfn[x]) return;
	col_num++;
	while (s.top() != x) {
		int k = s.top(); s.pop();
		num[col_num]++;
	}
	int k = s.top(); s.pop();
	num[col_num]++;
	if (num[col_num] >= 2) ans++;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		addEdge(x, y);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) finds(i);
	cout << ans << endl;
	return 0;
}