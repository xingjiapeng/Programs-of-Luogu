#include <iostream>
#include <string>
#include <map>

using namespace std;

const int range = 4617;

bool flag;
string n, s;
map<char, int> mp;

void set_map()
{
	mp['A'] = mp['B'] = mp['C'] = 2;
	mp['D'] = mp['E'] = mp['F'] = 3;
	mp['G'] = mp['H'] = mp['I'] = 4;
	mp['J'] = mp['K'] = mp['L'] = 5;
	mp['M'] = mp['N'] = mp['O'] = 6;
	mp['P'] = mp['R'] = mp['S'] = 7;
	mp['T'] = mp['U'] = mp['V'] = 8;
	mp['W'] = mp['X'] = mp['Y'] = 9;
	return;
}

int main()
{
	set_map();
	cin >> n;
	for (int i = 1; i <= range; i++)
	{
		cin >> s;
		bool avb = true;
		int ln = n.length();
		int ls = s.length();
		if (ln != ls)
			continue;
		for (int j = 0; j < ln; j++)
			if (n[j] != mp[s[j]] + '0')
			{
				avb = false;
				break;
			}
		if (avb)
		{
			flag = true;
			cout << s << endl;
		}
	}
	if (!flag)
		cout << "NONE\n";
	return 0;
}
