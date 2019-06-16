//Create by zzti_吴高
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<cstring>
using namespace std;
int a[8][8];
int vis[8][8][4];
bool vis1[8][8];
int d[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int n, m;
 bool dfs(int x, int y,int x1,int y1)
{
	 int xx, yy;
	 if (x == x1 && y1 == y) return true;
	 for (int i = 0; i < 4; i++)
	 {
		 xx = x + d[i][0];
		 yy = y + d[i][1];
		 if (xx >= 0 && yy >= 0 && xx < n && yy < m && !vis1[xx][yy] && a[xx][yy]!=1 )
		 {
			 vis1[xx][yy] =1;
			 if (dfs(xx, yy, x1, y1))return true;
		 }
	 }
	 return false;
}
 struct   q
 {
	 int x;
	 int y;
	 int nn, mm;
	 int step;
 };
 int sum;
 void bfs(int x, int y, int xx, int yy, int x1, int y1)
 {
	 queue<q> q1; sum = -1;
	 q  tou, wei;
	 tou.step = 0;
	 tou.x = xx;
	 tou.y = yy;
	 tou.nn = x;
	 tou.mm = y;
	q1.push(tou);
	 int aa, bb, cc, dd, ss;
	 while (!q1.empty())
	 {
		 wei = q1.front();
		 q1.pop();
		 aa = wei.x;
		 bb = wei.y;
		 ss = wei.step;
		 if (aa == x1 && bb == y1)
		 {
			 sum =wei.step;
			 break;
		 }
		 for (int i = 0; i < 4; i++)
		 {
			 cc = aa - d[i][0];
			 dd = bb - d[i][1];
			 memset(vis1, 0, sizeof(vis1));
			 vis1[aa][bb] = 1;
			 if (!vis[aa][bb][i] && cc >= 0 && a[aa + d[i][0]][bb + d[i][1]]!=1 && dd >= 0 && cc<n&& dd<m && a[wei.nn][wei.mm] != 1 && dfs(wei.nn, wei.mm, cc, dd))
			 {
				 vis[aa][bb][i] = 1;
				 tou.x = aa + d[i][0];
				 tou.y = bb + d[i][1];
				    tou.step = ss + 1;
				  tou.nn = aa;
				 tou.mm = bb;
				 q1.push(tou);
			 }
		 }
		 
	 }

 }

int main()
{
	int t;
	scanf("%d", &t);
	int x, y, xx, y3, x1, y1;
	y3 = 0;
	while (t--)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//scanf("%d", a[i] + j);
				cin >> a[i][j];
				if (a[i][j] == 2)
				{
					xx = i;
					y3 = j;
				}
				else if (a[i][j]==3)
				{
					x1 = i; y1 = j;
				}
				else if (a[i][j]== 4)
				{
					x = i; y = j;
				}
			
			}
		}
		//cout << x << y << xx << y3 << x1 << y1 << endl;
		bfs(x, y, xx, y3, x1, y1);
		printf("%d\n", sum);
		//cout << sum << endl;
	}
  //while (1){}
	return 0;
}
