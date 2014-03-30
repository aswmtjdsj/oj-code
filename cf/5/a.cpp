#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 205
using namespace std;
const short inf = 10000;
short map[maxn][maxn];
struct circle
{
	int x,y,r;
	circle(){}
	circle(int a,int b,int c):x(a),y(b),r(c){}
}c[maxn];
circle operator - (const circle &p,const circle &q)
{
	return circle(p.x - q.x,p.y - q.y,p.r);
}
void solve()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		int x,y,r;
		scanf("%d %d %d",&x,&y,&r);
		c[i] = circle(x,y,r);
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i == j)
				map[i][j] = 0;
			circle temp = c[i] - c[j];
			if(temp.x * temp.x + temp.y * temp.y <= (c[i].r + c[j].r) * (c[i].r + c[j].r))
				map[i][j] = 1;
			else
				map[i][j] = inf;
		}
	}
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
			{
				if(map[i][k] != inf && map[k][j] != inf)
				{
					if(map[i][j] == inf || map[i][j] > map[i][k] + map[k][j])
						map[i][j] = map[i][k] + map[k][j];
				}
			}
	short ans1 = map[2][1] + map[1][3],ans2 = map[1][2] + map[2][3],ans3 = map[1][3] + map[3][2];
	short ans = min(ans1,min(ans2,ans3)) + 1;
	//printf("%d\n",(ans >= inf) ? -1 : n - ans);
	cout << ((ans >= inf) ? -1 : n - ans) << endl;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i = 0;i < t;i++)
		solve();
}
