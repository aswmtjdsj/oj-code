#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 5001
int num[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	int ans = 0;
	for(int i = 1;i <= n;i++)
	{
		int a;
		scanf("%d",&a);
		num[a]++;
		if(num[a] > 1 or a > n)
			ans++;
	}
	printf("%d\n",ans);
}
