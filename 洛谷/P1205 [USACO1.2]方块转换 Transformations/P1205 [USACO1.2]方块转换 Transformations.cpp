#include <iostream>

using namespace std;

const int N = 10;

int n;
char a[N + 5][N + 5];
char b[N + 5][N + 5];
char b1[N + 5][N + 5];
char c[N + 5][N + 5];

bool check_same()
{
	bool is_same = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (b[i][j] != c[i][j])
			{
				is_same = false;
				break;
			}
	return is_same;
}

void change(int type, int sec)
{
	if (type == 1)
	{
		//转 90°：图案按顺时针转 90°。
		for (int i = 1; i <= n; i++)
			for (int j1 = 1, j2 = n; j1 <= n, j2 >= 1; j1++, j2--)
				b[i][j1] = a[j2][i];
	}
	if (type == 2)
	{
		//转 180°：图案按顺时针转 180°。
		for (int i1 = 1, i2 = n; i1 <= n, i2 >= 1; i1++, i2--)
			for (int j1 = 1, j2 = n; j1 <= n, j2 >= 1; j1++, j2--)
				b[i1][j1] = a[i2][j2];
	}
	if (type == 3)
	{
		//转 270°：图案按顺时针转 270°。
		for (int i1 = 1, i2 = n; i1 <= n, i2 >= 1; i1++, i2--)
			for (int j = 1; j <= n; j++)
				b[i1][j] = a[j][i2];
	}
	if (type == 4)
	{
		//反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。
		for (int i = 1; i <= n; i++)
			for (int j1 = 1, j2 = n; j1 <= n, j2 >= 1; j1++, j2--)
				b[i][j1] = a[i][j2];
	}
	if (type == 5)
	{
		//组合：图案在水平方向翻转，然后再按照 1～3 之间的一种再次转换。
		
		//反射：图案在水平方向翻转（以中央铅垂线为中心形成原图案的镜像）。
		for (int i = 1; i <= n; i++)
			for (int j1 = 1, j2 = n; j1 <= n, j2 >= 1; j1++, j2--)
				b1[i][j1] = a[i][j2];

		if (sec == 1)
		{
			//转 90°：图案按顺时针转 90°。
			for (int i = 1; i <= n; i++)
				for (int j1 = 1, j2 = n; j1 <= n, j2 >= 1; j1++, j2--)
					b[i][j1] = b1[j2][i];
		}
		if (sec == 2)
		{
			//转 180°：图案按顺时针转 180°。
			for (int i1 = 1, i2 = n; i1 <= n, i2 >= 1; i1++, i2--)
				for (int j1 = 1, j2 = n; j1 <= n, j2 >= 1; j1++, j2--)
					b[i1][j1] = b1[i2][j2];
		}
		if (sec == 3)
		{
			//转 270°：图案按顺时针转 270°。
			for (int i1 = 1, i2 = n; i1 <= n, i2 >= 1; i1++, i2--)
				for (int j = 1; j <= n; j++)
					b[i1][j] = b1[j][i2];
		}
	}
	if (type == 6)
	{
		//不改变：原图案不改变。
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				b[i][j] = a[i][j];
	}
	return;
}

void print_b()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << b[i][j];
		cout << endl;
	}
	cout << endl;
	return;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	for (int i = 1; i <= 6; i++)
	{
		change(i, 1);
		//print_b();
		if (check_same())
		{
			cout << i << endl;
			return 0;
		}
		if (i == 5)
			for (int j = 2; j <= 3; j++)
			{
				change(i, j);
				if (check_same())
				{
					cout << i << endl;
					return 0;
				}	
			}
	}
	//无效转换：无法用以上方法得到新图案。
	cout << 7 << endl;
	return 0;
}
