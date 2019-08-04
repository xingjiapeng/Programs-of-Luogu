#include <iostream>
#include <cstring>//memset头文件 
#include <stack>
#include <string>

using namespace std;

const int L = 105;

stack<char> a, b;
//a， 开始 
//b， 结束  
char varName[L];

int v;//varName 的下标  
int line, jbq;
//程序的行数， 记录一个循环进(j)不(b)去(q) 
int s[L], ls;
int ff, ee;//记录F和E的数目  
int mostGap;//记录F和E数目间最大的差距 

string t;

 
inline bool checkVarName(char x){//判断变量名是否有重复  

	for(int i = 1; i <= v; i++)
		if(x == varName[i])
			return false;
	
	return true;
}

inline void updateTime(char x, char y){
	
	int fe = ff - ee;

	if(jbq) s[fe] = 0;
	else{
		
		if(x != 'n' && y == 'n'){
			ls++;
			s[fe] = max(s[fe], ls);
		}
		
		s[fe] = max(s[fe], ls);

	}
	
	return;
}

inline void cleaner(){//清空栈、数组以及变量 初始化 
    while(!a.empty() || !b.empty()) a.pop(), b.pop();
    
	memset(varName, 'a', sizeof(varName));
	
	memset(s, 0, sizeof(s));
	
	v = jbq = ls = ee = ff = mostGap = 0;
	
	return;
}

inline int analyTime(string time){
	int f = time.find('^');
	if(f < 0) return 0;
	
	int g = time.find(')');
	
	int ans = 0;
	for(int i = f + 1; i < g; i++)
		ans = ans * 10 + (time[i] - '0');
	return ans;
} 

int geTime(){
	return s[0];
}

bool cmp(string x, string y){
	int lx = x.length(), ly = y.length();
	if(lx != ly)
		return lx > ly;
		
	for(int i = 0; i < lx/*或ly*/; i++)
		if(x[i] != y[i])
			return x[i] > y[i];
	
	return true;//这两个字符串一样大， false也可以  
}

int main(){
	
    int T; cin >> T;
    
    while(T--){
    	
    	cleaner();
    	
		cin >> line >> t;
		bool flag = true;
		for(int i = 1; i <= line; i++){
			
			char k;
			char w = 'a';
			string l, p;
			
			cin >> k;
			
			if(k == 'E'){
				
				if(a.empty()){
					flag = false;
					continue;
				}
				//判断是否由语法错误 ：多了E？ 
				
				ee++;
				if(a.top() == 'n' && b.top() != 'n' 
				|| a.top() > b.top())
					jbq--;
				//又一个进不去的循环过去了  
				
				updateTime(a.top(), b.top());
				a.pop(); b.pop(); varName[v--] = 'a';
				}
            			else{//k == 'F'
            	
				cin >> w >> l >> p;
				
				if(!flag) continue;
				ff++, ls = 0;
				if(!checkVarName(w)){
					flag = false;//判断是否有语法错误：变量名是否重复？
					continue;
				}
				
				char lz, pz;
				int ll = l.length(), pp = p.length();
				bool ch = cmp(l, p);
				
				//计算应该推入队列得lz和pz 
				if(l == "n" || p == "n") lz = l[0], pz = p[0];
				else if (ll > 1 || pp > 1){
					if(ch) lz = '2', pz = '1';
					else lz = '1', pz = '2'; 
				}
				else lz = l[0], pz = p[0];
				
				a.push(lz), b.push(pz), varName[++v] = w;
				if(lz == 'n' && pz != 'n' || lz > pz)
					jbq++, ls = 0, s[ff - ee] = 0; //又一个循环进不去 
				
			}
			mostGap = max(mostGap, ff - ee);
			
		}
		
        	if(!a.empty() || !flag){//判断是否有语法错误 ：少了E？ 以及前面是否有错误 
			cout << "ERR\n"; 
        		continue;
		}
        
        	if(geTime() == analyTime(t)) cout << "Yes\n";
        	else cout << "No\n";
        
	}
	
    return 0;
    
}
