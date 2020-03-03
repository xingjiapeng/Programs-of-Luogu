#include <stdio.h>
#include <math.h>
const int N = 5000;
struct node {
	int x, y;
}a[N + 10];
int n, pos;
bool vis[N + 10];
double mins, ans, d[N + 10];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
		d[i] = 1e9;
	}
	d[1] = 0;
	for (int i = 1; i <= n; i++) { //Prim
		mins = 1e9;
		for (int j = 1; j <= n; j++) {//和Dijkstra差不多
				if (vis[j]) continue;
				if (d[j] >= mins) continue;
				mins = d[j], pos = j;      //找一个最短的，放在pos中
			}
		ans += mins; vis[pos] = true;  //已经访问过的就不能再次访问
		for (int j = 1; j <= n; j++) {
			int x = pos, y = j; //计算pos 与 j之间的距离
			double sum =
			sqrt(
				(double)(a[x].x - a[y].x) * (a[x].x - a[y].x)
				+
				(double)(a[x].y - a[y].y) * (a[x].y - a[y].y)
				);
			if (sum < d[j]) d[j] = sum;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}