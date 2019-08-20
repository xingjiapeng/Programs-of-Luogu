#include <iostream>

using namespace std;

const int N = 1e6 + 5;
int n, large;
int cowNum[N], cowList[N];

void getList(){
	for(int i = 1; i <= n; i++)
		for(int j = cowNum[i]; j <= large; j += cowNum[i])
			cowList[j]++;
	return;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> cowNum[i];
		large = max(large, cowNum[i]);
	}
	getList();
	for(int i = 1; i <= n; i++)
		cout << cowList[cowNum[i]] - 1 << endl;
	return 0;
}
