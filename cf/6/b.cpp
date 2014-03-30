#include <cstdio>
using namespace std;
#define maxn 102

char map[maxn][maxn];

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int r,c;
char s;
int main()
{
	scanf("%d %d %c",&r,&c,&s);
	for(int i = 0;i < r;i++)
		for(int j = 0;j < c;j++)
			scanf(" %c",&map[i][j]);
	int ans = 0;
	bool has[30] = {0};
	for(int i = 0;i < r;i++)
		for(int j = 0;j < c;j++)
		{
			if(map[i][j] != s && map[i][j] != '.' && has[map[i][j] - 'A'] == 0)
			{
				int x, y;
				for(int k = 0;k < 4;k++)
				{
					x = i + dx[k];
					y = j + dy[k];
					if(0 <= x && x < r && 0 <= y && y < c && map[x][y] == s)
					{
						ans++;
						has[map[i][j] - 'A'] = 1;
						break;
					}
				}
			}
		}
	printf("%d\n",ans);
}
