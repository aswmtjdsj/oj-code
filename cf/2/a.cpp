#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1005
struct A
{
	char name[35];
	int sc;
}a[maxn];
char opt[maxn][35];
int in[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int cnt = 0;
	for(int i = 0;i < n;i++)
	{
		scanf(" %s %d",opt[i],&in[i]);
		bool flag = false;
		for(int j = 0;j < cnt;j++)
		{
			if(strcmp(a[j].name,opt[i]) == 0)
			{
				a[j].sc += in[i];
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			strcpy(a[cnt].name,opt[i]);
			a[cnt].sc = in[i];
			cnt++;
		}
	}
	int mark = 0;
	for(int i = 0;i < cnt;i++)
	{
		if(mark < a[i].sc)
			mark = a[i].sc;
	}
	int ans = n;
	for(int i = 0;i < cnt;i++)
	{
		int first = n;
		if(a[i].sc == mark)
		{
			int temp = 0;
			for(int j = 0;j < n;j++)
			{
				if(strcmp(opt[j],a[i].name) == 0)
				{
					temp += in[j];
					if(temp >= mark)
					{
						if(first > j)
						{
							first = j;
							break;
						}
					}
				}
			}
		}
		if(ans > first)
			ans = first;
	}
	puts(opt[ans]);
}
