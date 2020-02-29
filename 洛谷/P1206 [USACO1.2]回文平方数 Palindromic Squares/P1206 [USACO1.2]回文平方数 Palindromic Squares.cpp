#include <iostream>
#include <cmath>

using namespace std;

int b;
int sqs[30];
int sqs_cnt;
int cvn[30];
int cvn_cnt;

void cvs(int x)
{
	sqs_cnt = 0;
	int xx = x * x;
	while (xx > 0)
	{
		sqs[++sqs_cnt] = xx % b;
		xx /= b;
	}
	return;
}

void print_sqs()
{
	for (int i = 1; i <= sqs_cnt; i++)
		cout << sqs[i] << ' ';
	cout << endl;
	system("pause");
	return;
}

bool check_pld()
{
	for (int i = 1, j = sqs_cnt; i <= j; i++, j--)
		if (sqs[i] != sqs[j])
			return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> b;
	for (int i = 1; i <= 300; i++)
	{
		cvs(i);
		//cout << i << endl;
		//print_sqs();
		if (check_pld())
		{
			cvn_cnt = 0;
			int xx = i;
			while (xx > 0)
			{
				cvn[++cvn_cnt] = xx % b;
				xx /= b;
			}
			for (int j = cvn_cnt; j >= 1; j--)
			{
				if (cvn[j] > 9)
					cout << char(cvn[j] - 10 + 'A');
				else
					cout << cvn[j];
			}
			cout << ' ';
			
			for (int j = 1; j <= sqs_cnt; j++)
			{
				if (sqs[j] > 9)
					cout << char(sqs[j] - 10 + 'A');
				else
					cout << sqs[j];
			}
			cout << endl;
		}
	}
	return 0;
}
