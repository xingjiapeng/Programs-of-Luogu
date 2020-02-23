#include <stdio.h>
const int N = 30;
int n;
int f[N], v[4][N];
bool bk[N], done;
char s1[N], s2[N], s3[N];
inline void prtall(){
	for (int i = 1; i <= n; i++)
		printf("%d ", f[i]);
	printf("\n");
	return;
}
void finds(int x, int y, int jw) {
//	printf("%d %d %d\n", x, y, jw);
//	prtall();
	if (x == 0) { //搜索完毕
		if (jw == 0) { //没有进位
			prtall();
			done = true;
		}
		return;
	}
	for (int i = x - 1; i >= 1; i--) {
		int k1 = f[v[1][i]];
		int k2 = f[v[2][i]];
		int k3 = f[v[3][i]];
		if (k1 < 0 || k2 < 0 || k3 < 0)
			continue;
		if ((k1 + k2) % n != k3 && (k1 + k2 + 1) % n != k3)
			return;
	}
//	for (int i = 0; i < n; i++)
//		printf("%d", bk[i]);
//	printf("\n");
	if (f[v[y][x]] < 0) { //这个位置还没有被赋值
		for (int i = n - 1; i >= 0; i--) {
			if (bk[i]) continue;
			if (y < 3) {
				f[v[y][x]] = i; //赋值
				bk[i] = 1;
				finds(x, y + 1, jw);
				if (done) return;
				f[v[y][x]] = -1;
				bk[i] = 0;
			}
			else {
				int kk = f[v[1][x]] + f[v[2][x]] + jw;
				if (kk % n != i) continue; //不能赋这个值
				f[v[y][x]] = i;
				bk[i] = 1;
				finds(x - 1, 1, kk / n);
				if (done) return;
				f[v[y][x]] = -1;
				bk[i] = 0;
			}
		}
	}
	else {
		if (y < 3) {
			finds(x, y + 1, jw);
			if (done) return;
		}
		else {
			int kk = f[v[1][x]] + f[v[2][x]] + jw;
			if (kk % n != f[v[y][x]]) return;
			finds(x - 1, 1, kk / n);
			if (done) return;
		}
	}
	return;
}
int main() {
	scanf("%d", &n);
	scanf("%s%s%s", s1, s2, s3);
	for (int i = 0; i < n; i++) {
		v[1][i + 1] = s1[i] - 'A' + 1;
		v[2][i + 1] = s2[i] - 'A' + 1;
		v[3][i + 1] = s3[i] - 'A' + 1;
		f[i + 1] = -1;
	}
	finds(n, 1, 0);
	return 0;
}
