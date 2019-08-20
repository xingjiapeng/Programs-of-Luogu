#include <iostream>
#include <string>

using namespace std;

string y;
string s;
char c;
int count, l;

void fill(int w){
	if(w < 0 || w >= l)
		return;
	if(s[w] == 'E')
		return;
	if(c == 'w' && s[w] != 'w')
		c = s[w];
	if(s[w] != 'w' && s[w] != c)
		return;
	count++;
	s[w] = 'E';
	fill(w - 1);
	fill(w + 1);
	return; 
}
int main(){
	int maxcount = 0;
	cin >> l;
	cin >> y;
	for(int i = 0; i < l; i++){
		s = y;
		count = 0;
		c = s[0];
		fill(0);
		c = s[l - 1];
		fill(l - 1);
		if(count > maxcount)
			maxcount = count;
		y = y.substr(1) + y[0];
	}
	cout << maxcount << endl;
	return 0;
}
