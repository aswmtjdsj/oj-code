#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int n;
#define maxn 102
char str[maxn];
char ans[maxn * 2];
int main()
{
	cin >>n ;
	cin >> str;
	int cnt = 0;
	int tnc = 0;
	int l = strlen(str);
	for(int i = 0;i < l;i++)
	{
		tnc++;
		ans[cnt++] = str[i];
		if(tnc == 2)
		{
			if(l - i == 2)
			{
				ans[cnt++] = str[i+1];
				break;
			}
			else if(l - i == 1)
				break;
			else
			{
				tnc = 0;
				ans[cnt++] = '-';
			}
		}
	}
	ans[cnt] = 0;
	cout << ans << endl;
}
