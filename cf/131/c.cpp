#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 50
long long C[maxn][maxn];
void init()
{
	for(int i = 0;i <= 30;i++)
		for(int j = 0;j <= 30;j++)
		{
			if(i == 0 || j > i)
				C[i][j] = 0;
			else if(j == 0 || j == i)
				C[i][j] = 1;
			else
				C[i][j] = C[i-1][j] + C[i-1][j-1];
		}
}
int main()
{
	init();
	int n,m,t;
	while(scanf("%d %d %d",&n,&m,&t) == 3)
	{
		long long ans = 0;
		for(int i = 4;i <= n;i++)
			for(int j = 1;j <= m;j++)
			{
				if(i + j > t || i + j < t)
					continue;
				ans += C[n][i] * C[m][j];
			}
		cout << ans << endl;
	}
}
