#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int N = 2500;

int n, c, ts, te;
//T个城镇， C条道路， 起点， 终点 

int mind[N + 5];       //i到其他所有点的距离 
int dist[N + 5][N + 5];//记录i到j的最短距离 

bool vis[N + 5];

void dijkstra(int i){
	memset(mind, 0x3f, sizeof(mind));
	for(int j = 1; j <= n; j++)
		if(dist[i][j] > 0)
			mind[j] = dist[i][j];
	vis[i] = 1, mind[i] = 0;
	for(int j = 1; j < n; j++){
		int minDis = INT_MAX, pos;
		for(int k = 1; k <= n; k++)
			if(!vis[k] && mind[k] < minDis)
				minDis = mind[k], pos = k;
		vis[pos] = 1;
		for(int k = 1; k <= n; k++)
			if(mind[k] > mind[pos] + dist[pos][k] && dist[pos][k] > 0)
				mind[k] = mind[pos] + dist[pos][k];
//		for(int i = 1; i <= n; i++)
//			cout << mind[i] << ' ';
//		cout << endl;
	}
	return;
}
int main(){
	cin >> n >> c >> ts >> te;
	int rs, re, ci;
	for(int i = 1; i <= c; i++){
		cin >> rs >> re >> ci;
		dist[rs][re] = ci;
		dist[re][rs] = ci;
	}
//	for(int i = 1; i <= n; i++){
//		for(int j = 1; j <= n; j++)
//			cout << dist[i][j] << ' ';
//		cout << endl;
//	}
//	cout << endl;
	dijkstra(ts);
	cout << mind[te] << endl;
	return 0;
} 