#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 10000000;
int n,ans;
void dfs(int p,int q,int step,int depth)
{
	if(p == n or q == n)
	{
		ans = step;
		return ;
	}
	int a = p,b = q;
	int temp = 0;
	while(a + b < n)//greedy,log(n) to calc the last steps
	{
		if(a > b)
			b += a;
		else
			a += b;
		temp++;
	}
	if(step + temp + 1 >= depth)//evaluation function
		return ;
	dfs(p+q,q,step+1,depth);
	dfs(p,p+q,step+1,depth);
}
int main()
{
	scanf("%d",&n);
	int depth = 0;
	ans = inf;
	while(ans == inf)
		dfs(1,1,0,depth++);
	printf("%d\n",ans);
}
