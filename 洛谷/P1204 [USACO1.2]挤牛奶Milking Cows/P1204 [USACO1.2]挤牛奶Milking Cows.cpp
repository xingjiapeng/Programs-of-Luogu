#include <algorithm>
#include <iostream>

using namespace std;

const int N = 5000;

int n;
int cnt;
int ans1, ans2;

struct farmer
{
	int l, r;
	bool operator <(const farmer &F) const
	{
		return (this->l) < F.l;
	}
}f[N + 5];

void print_f()
{
	for (int i = 1; i <= n; i++)
		cout << f[i].l << ' ' << f[i].r << endl;
	cout << endl;
	return;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> f[i].l >> f[i].r;
	sort(f + 1, f + 1 + n);
	//print_f();
	int fst = f[1].l;
	for (int i = 1; i <= n; i++)
	{
		if (f[i].r <= fst)
			continue;
		//get ans1
		if (f[i].l <= fst)
			cnt += f[i].r - fst;
		else
			ans1 = max(ans1, cnt),
			cnt = f[i].r - f[i].l;
		//
		//get ans2
		if (f[i].l > fst)
			ans2 = max(ans2, f[i].l - fst);
		//
		fst = f[i].r;
	}
	ans1 = max(ans1, cnt);
	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}
