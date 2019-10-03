#include <iostream>
#include <climits>

using namespace std;

const int N = 200;

int n;
int dist[N + 5];
int w[N + 5][N + 5];

bool used[N + 5];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		used[i] = false;
		for (int j = 1; j <= n; j++)
			if (i != j)
				w[i][j] = 9999999;
	}
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			scanf("%d", &w[i][j]);
	for (int i = 1; i <= n; i++)
		dist[i] = w[1][i];
	dist[1] = 0;
	used[1] = true;
	while (true) {
		int mind = INT_MAX, v;
		for (int i = 2; i <= n; i++)
			if (!used[i] && dist[i] < mind) {
				mind = dist[i];
				v = i;
			}
		if(mind == INT_MAX)
			break;
		used[v] = true;
		for (int i = 2; i <= n; i++)
			dist[i] = min(dist[i], dist[v] + w[v][i]);
	}
	printf("%d", dist[n]);
	return 0;
}
