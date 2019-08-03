#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

const int N = 64;
const int dir[8][2] =   {
                        { 1,  2},
                        { 1, -2},
                        {-1,  2},
                        {-1, -2},
                        { 2,  1},
                        { 2, -1},
                        {-2,  1},
                        {-2, -1}
                        };

struct node{
    int x;
    int y;
    int step;
};

bool bk[N + 5][N + 5];
int startx;
int starty;
int endx;
int endy;
int ans;

void finds(){
    bk[startx][starty] = 1;
    queue<node> q;
    node s1;
    node s2;
    s1.step = 0;
    s1.x = startx;
    s1.y = starty;
    q.push(s1);
    while(!q.empty()){
        s1 = q.front();
        q.pop();
        if(s1.x == endx && s1.y == endy){
            ans = s1.step;
            return;
        }
        for(int i = 0; i < 8; i++){
            int nx = s1.x + dir[i][0];
            int ny = s1.y + dir[i][1];
            if(nx < 1 || ny < 1 || nx > 8 || ny > 8)
                continue;
            if(bk[nx][ny])
                continue;
            bk[nx][ny] = 1;
            s2.x = nx;
            s2.y = ny;
            s2.step = s1.step + 1;
            q.push(s2);
        }
    }
    return;
}

int main(){
    char s1;
    char s2;
    while(cin >> s1){
          cin >> starty;
          cin >> s2;
          cin >> endy;
        startx = s1 - 'a' + 1;
        endx = s2 - 'a' + 1;
        ans = -1;
        memset(bk, 0, sizeof(bk));    
        finds();
        printf("To get from %c%d to %c%d takes %d knight moves.\n", s1, starty, s2, endy, ans);
    }
    return 0;
}
