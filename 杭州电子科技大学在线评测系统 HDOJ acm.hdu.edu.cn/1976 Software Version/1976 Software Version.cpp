#include <iostream>
using namespace std;
int a1,a2,a3;
int b1,b2,b3;
int main(){
    int N;
    cin>>N;
    while(N--){
        cin>>a1>>a2>>a3;
        cin>>b1>>b2>>b3;
        if(a1!=b1){
            if(a1>b1) cout<<"First\n";
            if(b1>a1) cout<<"Second\n";
            continue;
        }
        if(a2!=b2){
            if(a2>b2) cout<<"First\n";
            if(b2>a2) cout<<"Second\n";
            continue;
        }
        if(a3!=b3){
            if(a3>b3) cout<<"First\n";
            if(b3>a3) cout<<"Second\n";
            continue;
        }
        cout<<"Same\n";    
    }
    return 0;
}
