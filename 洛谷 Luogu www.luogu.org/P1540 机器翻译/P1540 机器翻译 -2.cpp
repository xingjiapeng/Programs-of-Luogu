#include <iostream>
#include <string>

using namespace std;

struct voca{
    int name;
    int t;    
};

int m, n, x, ans;
voca v[1005];

int main(){
    cin >> m >> n;
    for(int i = 1; i <= n ; i++){
        cin >> x;
        if(x == 0) x = -1;
        bool flag = false;
        voca k; k.name = -1, k.t = -1;
        for(int j = 1; j <= m; j++){
            v[j].t++;
            k.name = v[j].t > k.t ? j : k.name, k.t = max(v[j].t, k.t);
            if(v[j].name == x)
                 flag = true;
        }
        if(!flag){
            ans++;
            v[k.name].name = x, v[k.name].t = 0;
        }
    }
    cout << ans;
    return 0;    
}
