#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll N=10005;
struct node{
	ll s,p;
};
inline bool cmp(node x,node y){
	if(x.p!=y.p) return x.p>y.p;
	else         return x.s<y.s;
}
ll n;
node a[N];
int main(){
	cin>>n;
	for(ll now=n;now>=1;--now){
		ll tmp=now;
		for(ll i=2;i*i<=now;i++){
			ll pp=0;
			while(!(tmp%i)){
				tmp/=i;
				pp++;
			}
			a[i].s=i,a[i].p+=pp;
		}
		if(tmp!=1)
			a[tmp].s=tmp,a[tmp].p++;
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++){
		if(!a[i].p) break;
		cout<<a[i].s<<' '<<a[i].p<<endl;
	}
	return 0;
}
