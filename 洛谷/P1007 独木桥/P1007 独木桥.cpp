#include <iostream>

using namespace std;

int l, n, x;
int maxAns, minAns;

int main() {
	cin >> l >> n;
	maxAns = minAns = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		maxAns = max(maxAns, max(l - x + 1, x));
		minAns = max(minAns, min(l - x + 1, x));
	}
	cout << minAns << ' ' << maxAns << endl;
	return 0;
}
