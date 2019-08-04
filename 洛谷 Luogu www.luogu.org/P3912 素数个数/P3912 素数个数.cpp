#include <iostream>

using namespace std;

const int N = 1e8 + 5;
int end, ans;
bool isNotPrime[N], flag;

void getPrime(){
	isNotPrime[1] = 1;
	for(int i = 2; i * i <= end; i++){
		if(isNotPrime[i]) continue;
		for(int j = i * i; j <= end; j += i)
			if(!isNotPrime[j])
				isNotPrime[j] = 1, ans--;
	}
	return;
}

int main(){
	cin >>  end;
	ans = end - 1;
	getPrime();
	cout << ans;
	return 0;
}
