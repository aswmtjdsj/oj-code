#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[13];
int k;
int main()
{
	cin >> k;
	for(int i = 0;i < 12;i++) cin >> a[i];
	sort(a,a + 12);
	int ans = 0, now = 0;
	for(int i = 11;i >= 0;i --)
	{
		if(now >= k)
			break;
		ans++;
		now += a[i];
	}
	printf("%d\n",(now >= k)?ans:-1);
}
