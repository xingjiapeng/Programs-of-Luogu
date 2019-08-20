#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int N = 1e5;
string s[N + 5];
bool bk[N + 5];
bool ans;
int n;

void finds(){
    queue<string> q;
    q.push("bob");
    while(!q.empty()){
        string x = q.front(); q.pop();
        char xt = x[x.length() - 1]; 
        if(xt == 'm'){
            ans = true;
            break;
        }
        for(int i = 1; i <= n; i++){
            if(bk[i]) continue;
            if(xt != s[i][0]) continue;
            bk[i] = true;
            q.push(s[i]);
        }
    }
    return;
}

int main(){
    while(cin >> s[1]){
        bk[1] = 0, n = 1;
        while(cin >> s[++n]){
            if(s[n] == "0")
                break;
            bk[n] = 0;
        }
        n--;//以上是输入部分 
        
        ans = false;
        finds();
        cout << (ans ? "Yes." : "No.") << endl;
    }
    return 0;
}
