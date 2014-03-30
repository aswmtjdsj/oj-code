#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
#define maxn 205
	int x[maxn], y[maxn];
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%d %d",&x[i],&y[i]);
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		int l(0), r(0), u(0), d(0);
		for(int j = 0;j < n;j++)
		{
			if(x[j] < x[i] && y[j] == y[i])
				l++;
			else if(x[j] > x[i] && y[j] == y[i])
				r++;
			else if(x[j] == x[i] && y[j] > y[i])
				u++;
			else if(x[j] == x[i] && y[j] < y[i])
				d++;
		}
		if(l && r && u && d)
			ans++;
	}
	cout << ans << endl;
}
