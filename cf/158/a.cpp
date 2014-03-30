#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
#define maxn 52
	int n,k;
	int a[maxn];
	scanf("%d %d",&n,&k);
	int ans = 0;
	for(int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i < n;i++)
		if(a[i] >= a[k-1] && a[i])
			ans++;
	cout << ans << endl;
}
