#include <iostream>
#include <queue>
using namespace std;
const int N = 100;
struct edge {
	int to, nxt, v;
}g[N + 5];
int ou[N + 5], fte[N + 5], gz;
int n, p;
int u[N + 5], c[N + 5];
bool vis[N + 5];
void addEdge(int x, int y, int w) {
	g[++gz] = (edge){y, fte[x], w};
	fte[x] = gz;
	return;
}
void topo() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (c[i] != 0) {
			q.push(i);
			vis[i] = true;
		}
		else
			c[i] -= u[i];
	}
	while (!q.empty()) {
		int k = q.front(); q.pop();
		for (int i = fte[k]; i != 0; i = g[i].nxt) {
			if (c[k] <= 0) continue;
			c[g[i].to] += (g[i].v * c[k]);
			if (vis[g[i].to]) continue;
			q.push(g[i].to); vis[g[i].to] = true;
		}
	}
	return;
}
int main() {
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> c[i] >> u[i];
	for (int i = 1; i <= p; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		addEdge(x, y, w);
		ou[x] = 1;
	}
	topo();
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (ou[i]) continue;
		if (c[i] <= 0) continue;
		cout << i << ' ' << c[i] << endl;
		flag = true;
	}
	if (!flag)
		cout << "NULL\n";
	return 0;
}