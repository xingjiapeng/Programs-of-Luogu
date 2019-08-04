#include <iostream>

using namespace std;

const int N = 100001;

int a[N];
int b[N];
int fs[N]; 

int main(){
    int m;
	int n;
    cin >> n;
	cin >> m;
    int x;
	int y;
    for(int i = 1; i <= m; i++){
        cin >> x;
		cin >> y;
        for(int j = n; j >= x; j--)
            fs[j]=max(fs[j],fs[j-x]+x*y);
    }
    cout << fs[n] << endl;
    return 0;    
}

