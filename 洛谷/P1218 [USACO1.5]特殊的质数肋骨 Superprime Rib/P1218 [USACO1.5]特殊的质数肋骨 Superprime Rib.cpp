/*************************************************************************
	> File Name: P1218 [USACO1.5]特殊的质数肋骨 Superprime Rib.cpp
	> Author: Xing Jiapeng
	> Mail: xingjiapeng10@163.com
	> Created Time: 2019年12月16日 星期一 18时57分14秒
 ************************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int n;

inline bool is_prime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return false;
	return true;
}

void finds(int now, int x)
{
	if (x > n)
	{
		cout << now << endl;
		return;
	}
	for (int i = 1; i <= 9; i += 2)
	{
		int tmp = now * 10 + i;
		if (!is_prime(tmp))
			continue;
		finds(tmp, x + 1);
	}
	return;
}

int main()
{
	cin >> n;
	finds(2, 2); finds(3, 2);
	finds(5, 2); finds(7, 2);
	return 0;
}
