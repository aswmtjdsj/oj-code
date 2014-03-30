#include <iostream>
#include <cstdio>
using namespace std;
int c[2],d[2],r[2],a[4];
bool mark;

bool check()
{
	return (a[0] + a[1] == r[0]) && (a[2] + a[3] == r[1]) && (a[0] + a[2] == c[0]) && (a[1] + a[3] == c[1]) && (a[0] + a[3] == d[0]) && (a[1] + a[2] == d[1]);
}
bool dfs(int step)
{
	if(step == 4)
	{
		if(check())
			return mark = true;
		return false;
	}
	for(int i = 1;i <= 9;i++)
	{
		bool flag = true;
		for(int j = 0;j < step;j++)
			if(a[j] == i)
			{
				flag = false;
				break;
			}
		if(!flag)
			continue;
		a[step] = i;
		if(dfs(step+1))
			return true;
	}
	return false;
}
int main()
{
	for(int i = 0;i < 2;i++)
		scanf("%d",&r[i]);
	for(int i = 0;i < 2;i++)
		scanf("%d",&c[i]);
	for(int i = 0;i < 2;i++)
		scanf("%d",&d[i]);
	mark = false;
	dfs(0);
	if(mark)
	{
		for(int i = 0;i < 4;i++)
			printf("%d%c",a[i],i%2?'\n':' ');
	}
	else
		puts("-1");
}
