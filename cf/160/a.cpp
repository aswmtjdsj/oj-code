#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
	int n;
#define maxn 105
	int a[maxn], sum[maxn] = {0};
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	sort(a +1 ,a + n+1);
	sum[0] = 0;
	for(int i = 1;i <= n;i++)
		sum[i] = sum[i-1] + a[i];
	int num = 0, ans = 0;
	for(int i = n;i >= 1;i--)
	{
		num += a[i];
		ans++;
		if(num > sum[i-1])
			break;
	}
	cout << ans << endl;
}
