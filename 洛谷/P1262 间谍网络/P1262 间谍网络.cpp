#include <iostream>
#include <stack>
using namespace std;
const int N = 8000; //边数
const int M = 3000; //点数
//这里常量的定义与n的定义相反
struct edge {
	int to, nxt;
}g[N + 5];
int fte[N + 5], gz;
int dfn[N + 5], low[N + 5];
int col[N + 5], col_num;
int num[N + 5];
int now, ans;
int n, p, r;
int in[M + 5], money[M + 5], cost[M + 5];
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
		s.pop();
		num[col_num]++;
	}
	s.pop();
	num[col_num]++;
	if (num[col_num] >= 2) ans++;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> p;
	for (int i = 1; i <= p; i++) {
		int x, y;
		cin >> x >> y;
		money[x] = y;
	}
	cin >> r;
	for (int i = 1; i <= r; i++) {
		int x, y;
		cin >> x >> y;
		addEdge(x, y);
	}
	
	memset(cost, 0x3f, sizeof(cost));
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) finds(i);
	int ans = 0, id = 0;
	for (int i = 1; i <= col_num; i++)
		if (in[i] == 0) {
			if (cost[i] >= 1e9) {
				id = i;
				break;
			}
			ans += cost[i];
		}
	if (!id) cout << "YES\n" << ans << endl;
	else for (int i = 1; i <= n; i++)
		if (col[i] == id) {
			cout << "NO\n" << i << endl;
			break;
		}
	return 0;
}