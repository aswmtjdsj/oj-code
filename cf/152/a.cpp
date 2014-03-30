#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 102

char sq[maxn][maxn];
char xxx[maxn];
int n,m;
int main()
{
	memset(xxx,'0',sizeof(xxx));
	scanf("%d %d",&n, &m);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
		{
			scanf(" %c",&sq[i][j]);
		}
	for(int j = 0;j < m;j++)
		for(int i = 0;i < n;i++)
			if(xxx[j] < sq[i][j])
				xxx[j] = sq[i][j];
	int ans = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			if(sq[i][j] == xxx[j])
			{
				ans++;
				break;
			}
	cout << ans << endl;
}
