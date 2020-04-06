#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1500;
const int M = N * N *2;
struct edge {
    int from;
    int to, nxt;
    int val;
}g[M + 5];
int gz;
int fte[N + 5], in[N + 5];
int dis[5][N + 5];
bool vis[N + 5];
bool flag[M + 5];
int same[N + 5], oppo[N + 5];
int n, m, ans;
int s1, s2;
int t1, t2;
void addEdge(int u, int v, int w) {
    g[++gz] = (edge){u, v, fte[u], w};
    fte[u] = gz;
    return;
}
struct cmp {
    bool operator ()(const int &x, const int &y) const{
        return dis[x] > dis[y];
    }
};
void spfa(int s, int dis[N + 5]) {
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++)
        dis[i] = 1e9;
    dis[s] = 0;
    priority_queue<int, vector<int>, cmp> q;
    q.push(s);
    while (!q.empty()) {
        int k = q.top(); q.pop();
        vis[k] = false;
        for (int i = fte[k]; i; i = g[i].nxt) {
            int kk = g[i].to;
            if (dis[kk] <= dis[k] + g[i].val)
                continue;
            dis[kk] = dis[k] + g[i].val;
            if (vis[kk]) continue;
            vis[kk] = true;
            q.push(kk);
        }
    }
    return;
}
void topo() {
    queue<int> q;
    q.push(s1);
    while (!q.empty()) {
        int k = q.front(); q.pop();
        ans = max(ans, (same[k] > oppo[k] ? same[k] : oppo[k]));
        for (int i = fte[k]; i; i = g[i].nxt) {
            if (!flag[i]) continue;
            int kk = g[i].to, w = g[i].val;
            if (dis[3][kk] + dis[4][k] + w == dis[3][t2])
                same[kk] = max(same[kk], same[k] + w);
            if (dis[4][kk] + dis[3][k] + w == dis[3][t2])
                oppo[kk] = max(oppo[kk], oppo[k] + w);
            if (!(--in[kk])) q.push(kk);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    cin >> s1 >> t1 >> s2 >> t2;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    spfa(s1, dis[1]);
    spfa(t1, dis[2]);
    spfa(s2, dis[3]);
    spfa(t2, dis[4]);
    for (int i = 1; i <= gz; i++) {
        int u = g[i].from, v = g[i].to, w = g[i].val;
        if (dis[1][u] + dis[2][v] + w != dis[1][t1])
            continue;
        flag[i] = true;
        in[v]++;
    }
    topo();
    cout << ans << endl;
    return 0;
}
