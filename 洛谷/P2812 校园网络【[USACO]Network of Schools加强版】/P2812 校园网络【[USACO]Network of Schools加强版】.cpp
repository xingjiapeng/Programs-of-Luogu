#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int N = 1e4;
const int M = 5e6;
struct edge {
	int from;
	int to, nxt;
}g[M + 5];
int fte[N + 5], gz;
int dfn[N + 5], low[N + 5];
int col[N + 5], col_num, now;
int num[N + 5];
bool ins[N + 5];
int n, id, od;
int insd[N + 5], outd[N + 5];
stack<int> s;
void addEgde(int x, int y) {
	g[++gz] = (edge){x, y, fte[x]};
	fte[x] = gz;
	return;
}
void tarjan(int x) {
	low[x] = dfn[x] = ++now;
	ins[x] = now;
	s.push(x);
	for (int i = fte[x]; i; i = g[i].nxt) {
		int kk = g[i].to;
		if (!dfn[kk]) {
			tarjan(kk);
			low[x] = min(low[x], low[kk]);
		}
		else if (!col[kk]) low[x] = min(low[x], dfn[kk]);
	}
	if (low[x] != dfn[x]) return;
	col_num++;
	while (s.top() != x) {
		int kk = s.top(); s.pop();
		col[kk] = col_num;
		ins[kk] = false;
	}
	int kk = s.top(); s.pop();
	col[kk] = col_num;
	ins[kk] = false;
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	int s;
	for (int i = 1; i <= n; i++)
		while (cin >> s) {
			if (!s) break;
			addEgde(i, s);
		}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 1; i <= n; i++)
		for (int j = fte[i]; j; j = g[j].nxt) {
			int kk = g[j].to;
			if (col[i] == col[kk]) continue;
			insd[col[kk]]++, outd[col[i]]++;
		}
	for (int i = 1; i <= col_num; i++) {
		if (!insd[i]) id++;
		if (!outd[i]) od++;
	}
	if (col_num == 1) cout << 1 << endl << 0 << endl;
	else cout << id << endl << max(id, od) << endl;
	return 0;
}