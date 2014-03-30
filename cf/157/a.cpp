#include <iostream>
#include <cstdio>
using namespace std;

#define maxn 35
int sq[maxn][maxn];

int main()
{
	int n,ans = 0;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%d",&sq[i][j]);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
		{
			int col = 0,row = 0;
			for(int k = 0;k < n;k++)
				col += sq[k][j];
			for(int k = 0;k < n;k++)
				row += sq[i][k];
			if(col > row)
				ans++;
		}
	cout << ans << endl;
}
