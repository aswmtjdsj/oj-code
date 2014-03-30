#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxn 200005
int sum,n,num;
int a[maxn];
int ans[maxn];
int main()
{
	scanf("%d",&n);
	sum = 0;
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]),sum += a[i];
	num = 0;
	for(int i = 0;i < n;i++)
		if(a[i] * (n - 1) == sum - a[i])
			ans[num++] = i;
	printf("%d\n",num);
	for(int i = 0;i < num;i++)
		printf("%d%c",ans[i]+1,(i == num - 1)?'\n':' ');
}
