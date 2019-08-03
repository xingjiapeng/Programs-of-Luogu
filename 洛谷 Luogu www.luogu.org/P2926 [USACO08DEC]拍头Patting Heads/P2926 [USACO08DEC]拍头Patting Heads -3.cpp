#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e6 + 5;
int n, large;
int cowNum[N], cowList[N], c[N];

void getList(){
    for(int i = 1; i <= large; i++){
    	if(!c[i]) continue;
        for(int j = i; j <= large; j += i)
            cowList[j]+=c[i];    	
	}
    return;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &cowNum[i]);
        c[cowNum[i]]++;
        large = max(large, cowNum[i]);
    }
    getList();
    for(int i = 1; i <= n; i++)
        printf("%d\n", cowList[cowNum[i]] - 1);
    return 0;
}
