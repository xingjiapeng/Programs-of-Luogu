#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
int l,n,c,t,vr,v1,v2;
double a[200],b[200];
int main(){
    while(cin>>l){
        cin>>n>>c>>t>>vr>>v1>>v2;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            cin>>a[i];
        a[n+1]=l;
        for(int i=1;i<=190;i++)
            b[i]=INT_MAX;
        b[0]=0;
        double f=0,f2=0,x,y;
        for(int i=1;i<=n+1;i++){
            for(int j=i-1;j>=0;j--){
                if(j==0){
                    f=a[i]-a[0];
                    if(f<=c){
                        b[i]=min(b[i],b[0]+1.0*f/v1);
                    }
                    else{
                        f2=b[0]+1.0*c/v1;
                        f-=c;
                        f2+=1.0*f/v2;
                        b[i]=min(b[i],f2);
                    }
                }
                else{
                    x=t,y=0;
                    f=(a[i]-a[j]);
                    y=y+1.0*f/v2;
                    if(f<=c){
                        x=x+1.0*f/v1;
                    }
                    else{
                        x=x+1.0*c/v1;
                        f-=c;
                        x+=1.0*f/v2;
                    }
                    b[i]=min(b[i],b[j]+y);
                    b[i]=min(b[i],b[j]+x);
                }
            }
        }
        if(b[n+1]>=double(1.0*l/vr))
            cout<<"Good job,rabbit!\n";
        else
            cout<<"What a pity rabbit!\n";
    }
    return 0;
}
