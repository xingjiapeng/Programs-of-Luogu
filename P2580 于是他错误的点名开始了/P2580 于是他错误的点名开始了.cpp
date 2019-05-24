#include <iostream>
#include <set>
#include <string>
using namespace std;
int n,m;
string x;
set<string> s1,s2;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        s1.insert(x);
    }
    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>x;
        if(!s1.count(x)) cout<<"WRONG\n";
        else
            if(s2.count(x)>0) cout<<"REPEAT\n";
            else s2.insert(x),cout<<"OK\n";
    }
    return 0;
}
