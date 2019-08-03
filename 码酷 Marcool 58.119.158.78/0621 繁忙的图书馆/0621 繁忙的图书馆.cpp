#include <iostream>

using namespace std;

const int N = 90;

int a[N + 5][N + 5];
int starty;
int startx;
int endy;
int endx;
int n;
int m;

void finds(int y, int x){
	if(a[y][x]) return;
	a[y][x] = 2;
	finds(y, x + 1);
	finds(y, x - 1);
	finds(y + 1, x);
	finds(y - 1, x);
	return;
}

int main(){
	cin >> n;
	cin >> m;
	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j <= m + 1; j++)
			a[i][j] = 3;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	cin >> starty;
	cin >> startx;
	cin >> endy;
	cin >> endx;
	finds(starty, startx);
	if(a[endy][endx] == 2)
		cout << "OK!\n";
	else
		cout << "NO!\n";
	return 0;
}
