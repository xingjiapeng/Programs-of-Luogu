#include <iostream>
#include <cstring>
using namespace std;
int a[10001][4]; 
int main(){
    memset(a,-1,sizeof(a));
    int n;
    cin>>n;
    int x1,y1,q,w,x2,y2;
    for(int i=1;i<=n;i++){
        cin>>x1>>y1>>q>>w;
        x2=x1+q;
        y2=y1+w;
        //左下：x1,x2 右下：x1,y2 左上：x2,y1 右上： x2,y2
        a[i][0]=x1;
        a[i][1]=x2;
        a[i][2]=y1;
        a[i][3]=y2;
    }
    cin>>q>>w;
    for(int i=n;i>=1;i--){
    	if(q>=a[i][0]&&q<=a[i][1]&&w>=a[i][2]&&w<=a[i][3]){
    		cout<<i<<endl;
    		return 0;
		}
	}
	cout<<-1<<endl;
    return 0;
}
