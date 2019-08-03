#include <iostream>

using namespace std;

int a[2001];
int b[2001];

int main(){
	int n;
	int as;
	int bs;
	cin >> n;
	cin >> as;
	cin >> bs;
	int ac=0;
	int bc=0;
	int az=0;
	int bz=0;
	for(int i = 1; i <= as; i++)
		cin >> a[i];
	for(int i = 1; i <= bs; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++){
		if(az == as)
			az = 1;
		else
			az++;
		if(bz == bs)
			bz = 1;
		else
			bz++;
		if(a[az] == 0 && b[bz] == 1)
			bc++;
		if(a[az] == 1 && b[bz] == 0)
			ac++;
		if(a[az] == 1 && b[bz] == 2)
			bc++;
		if(a[az] == 2 && b[bz] == 1)
			ac++;
		if(a[az] == 2 && b[bz] == 0)
			bc++;
		if(a[az] == 0 && b[bz] == 2)
			ac++;
		if(a[az] == 3 && b[bz] == 0)
			bc++;
		if(a[az] == 0 && b[bz] == 3)
			ac++;
		if(a[az] == 3 && b[bz] == 1)
			bc++;
		if(a[az] == 1 && b[bz] == 3)
			ac++;
		if(a[az] == 2 && b[bz] == 3)
			bc++;
		if(a[az] == 3 && b[bz] == 2)
			ac++;
		if(a[az] == 0 && b[bz] == 4)
			bc++;
		if(a[az] == 4 && b[bz] == 0)
			ac++;
		if(a[az] == 1 && b[bz] == 4)
			bc++;
		if(a[az] == 4 && b[bz] == 1)
			ac++;
		if(a[az] == 4 && b[bz] == 2)
			bc++;
		if(a[az] == 2 && b[bz] == 4)
			ac++;
		if(a[az] == 4 && b[bz] == 3)
			bc++;
		if(a[az] == 3 && b[bz] == 4)
			ac++;
	}
	cout << ac << ' ' << bc << endl;
	return 0;
} 
