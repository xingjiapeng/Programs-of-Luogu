#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e3;
const int dir[4][2] =   {
                        { 1,  0},
                        { 0,  1},
                        {-1,  0},
                        { 0, -1}, 
                        };

struct node{
    friend bool operator < (node a, node b){
        return a.step > b.step;
    }
    int x;
    int y;
    int step;
};

char maps[N + 5][N + 5];

bool bk[N + 5][N + 5];

int n;
int m;
int startx;
int starty;
int endx;
int endy;
int ans;

inline void finds(){
    bk[startx][starty] = true;
    priority_queue<node> q;
    node s1, s2;
    s1.x = startx;
    s1.y = starty;
    s1.step = 0;
    q.push(s1);
    while(!q.empty()){
        s1 = q.top();
        q.pop();
        if(s1.x == endx && s1.y == endy){
            ans = s1.step;
            return;
        }
        for(int i = 0; i < 4; i++){
            int nx = s1.x + dir[i][0];
            int ny = s1.y + dir[i][1];
            if(nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            if(bk[nx][ny])
                continue;
            bk[nx][ny] = 1;
            s2.x = nx;
            s2.y = ny;
            s2.step = s1.step;
            if(maps[nx][ny] == '.')
                s2.step++;
            q.push(s2);
        }
    }
    return;
}

int main(){
    

    while(cin >> n){
          cin >> m;
        if(!(n || m))
            break;          
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                cin >> maps[i][j];        
          cin >> startx;
          cin >> starty;
          cin >> endx;
          cin >> endy;
        ans = 0;
        memset(bk, false, sizeof(bk));
        finds();
        cout << ans << endl;
    }
    return 0;
}
