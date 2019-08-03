#include <iostream>
#include <algorithm>

using namespace std;

struct stu{
    int x, y;//第一位同学 
    int p, q;//第二位同学 
    int type;
}s[2005];

struct line{
    int num, count;    
};

int m,n,k,l,d;
//m行n列，k横l纵，d对同学 
line ms[1005], ns[1005];

inline bool cmpline(line a, line b){
    return a.count != b.count ? a.count > b.count : a.num < b.num;    
}

inline bool cmpline2(line a, line b){
    return a.num < b.num;    
}

int main(){
    cin >> m >> n >> k >> l >> d;
    
    for(int i = 1; i <= d; i++){
        cin >> s[i].x >> s[i].y >> s[i].p >> s[i].q;
        if(s[i].x > s[i].p || s[i].y > s[i].q)//整理  
            swap(s[i].x, s[i].p), swap(s[i].y, s[i].q);
        if(s[i].x != s[i].p)
            s[i].type = 1, ns[s[i].x].count++, ns[s[i].x].num = s[i].x;//需要k 
        else
            s[i].type = 2, ms[s[i].y].count++, ms[s[i].y].num = s[i].y;//需要l 
    }
    
    sort(ms + 1, ms + m + 1, cmpline);
    sort(ns + 1, ns + n + 1, cmpline);
    sort(ms + 1, ms + l + 1, cmpline2);
    sort(ns + 1, ns + k + 1, cmpline2);
    
    for(int i = 1; i < k; i++)
        cout << ns[i].num << ' ';
    cout << ns[k].num << endl;    
    for(int i = 1; i < l; i++)
        cout << ms[i].num << ' ';
    cout << ms[l].num << endl;
    
    return 0;    
}
