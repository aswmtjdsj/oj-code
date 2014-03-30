#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 35
int ans[maxn],m[maxn],M[maxn],sum,SUM,sumt,d,temp;
int main()
{
	scanf("%d %d",&d,&sumt);
	for(int i = 0;i < d;i++)
	{
		scanf("%d %d",&m[i],&M[i]);
		sum += m[i];
		SUM += M[i];
	}
	if(sum > sumt or SUM < sumt)
		puts("NO");
	else
	{
		puts("YES");
		for(int i = 0;i < d;i++)
		{
			temp += m[i];
			ans[i] = m[i];
			M[i] -= m[i];
		}
		for(int i = 0;i < d;i++)
		{
			if(temp < sumt)
			{
				int t = min(sumt - temp,M[i]);
				M[i] -= t;
				temp += t;
				ans[i] += t;
			}
			else
				break;
		}
		for(int i = 0;i < d;i++)
			printf("%d%c",ans[i],i==d-1?'\n':' ');
	}
}
