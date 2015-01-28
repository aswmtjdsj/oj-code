#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 102
int cas, n, s, p, t, ans, limit;
int gao(int x)
{
	int y = 0;
	for(int i = 0;i <= 10;i ++)
		for(int j = 0;j <= min(10,x - i);j++)
			for(int k = 0;k <= min(10,x - i - j);k++)
			{
				if(abs(i - j) <= 1 && abs(j-k) <= 1 && abs(i-k) <= 1)
				{
					y = max(y,max(i,max(j,k)));
				}
			}
	return y;
}
int egao(int x)
{
	int y = 0;
	for(int i = 0;i <= min(x,10);i ++)
		for(int j = 0;j <= min(10,x-i);j++)
			for(int k = 0;k <= min(10,x-i-j);k++)
			{
				if(abs(i - j) <= 2 && abs(j-k) <= 2 && abs(i-k) <= 2)
				{
					y = max(y,max(i,max(j,k)));
				}
			}
	return y;
}

int main()
{
	cin >> cas;
	for(int k = 1;k <= cas;k++)
	{
		ans = 0;
		limit = 0;
		cin >> n >> s >> p;
		for(int i = 0;i < n;i++)
		{
			cin >> t;
			if(gao(t) >= p)
				ans++;
			else if(limit < s && egao(t) >= p)
			{
				ans++;
				limit++;
			}
		}
		cout << "Case #" << k << ": " << ans << endl;
	}
}
