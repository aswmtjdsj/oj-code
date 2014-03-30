#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 1005
int x[maxn],y[maxn],r[maxn];
int lx, ly, rx, ry;
int n;
bool check(int a,int b)
{
	bool mark = false;
	for(int i = 0;i < n;i++)
		if((x[i] - a) * (x[i] - a) + (y[i] - b) * (y[i] - b) <= r[i] * r[i])
		{
			mark = true;
			break;
		}
	return mark;
}
int main()
{
	scanf("%d %d %d %d",&lx,&ly,&rx,&ry);
	cin >> n;
	for(int i = 0;i < n;i++)
		scanf("%d %d %d",&x[i],&y[i],&r[i]);
	int ans = 0;
	for(int i = min(lx,rx)+1;i < max(lx,rx);i++)
		if(!check(i,ly))
			ans++;
	for(int i = min(lx,rx)+1;i < max(lx,rx);i++)
		if(!check(i,ry))
			ans++;
	for(int j = min(ly,ry)+1;j < max(ly,ry);j++)
		if(!check(lx,j))
			ans++;
	for(int j = min(ly,ry)+1;j < max(ly,ry);j++)
		if(!check(rx,j))
			ans++;
	if(!check(lx,ly))
		ans++;
	if(!check(lx,ry))
		ans++;
	if(!check(rx,ly))
		ans++;
	if(!check(rx,ry))
		ans++;
	cout << ans << endl;
}
