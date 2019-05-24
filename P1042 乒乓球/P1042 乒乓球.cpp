#include <iostream>
using namespace std;
int h1[6005];
int h2[6005];
int d1[6005];
int d2[6005];
int k1,k2;
int main(){
    char v;
    k1=k2=1;
    while(v=cin.get()){
        if(v=='E') break;
        if(v=='W'){
            h1[k1]++;
            if(h1[k1]-d1[k1]>=2&&h1[k1]>=11) k1++;
            h2[k2]++;
            if(h2[k2]-d2[k2]>=2&&h2[k2]>=21) k2++;
        }
        if(v=='L'){
            d1[k1]++;
            if(d1[k1]-h1[k1]>=2&&d1[k1]>=11) k1++;
            d2[k2]++;
            if(d2[k2]-h2[k2]>=2&&d2[k2]>=21) k2++;
        }
    }
    for(int i=1;i<=k1;++i)
        cout<<h1[i]<<':'<<d1[i]<<endl;
    cout<<endl;
    for(int i=1;i<=k2;++i)
        cout<<h2[i]<<':'<<d2[i]<<endl;
    return 0;
}
