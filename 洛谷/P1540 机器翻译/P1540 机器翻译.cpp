#include <iostream>
#include <string>

using namespace std;

int m, n, x, ans, t;
int v[105];

inline bool finds(int a){
    for(int i = 1; i <= m; i++)
        if(v[i] == a)
            return false;
    return true;
}

int main(){
    cin >> m >> n;
    for(int i = 1; i <= n ; i++){
        cin >> x;
        if(x == 0) x = -1;
        if(finds(x)){
            ans++;
            if(t == m) t = 1;
            else t++;
            v[t] = x;
        }
    }
    cout << ans;
    //system("pause");
    return 0;    
}
