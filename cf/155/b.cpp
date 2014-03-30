#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pi;
#define maxn 1002
pi p[maxn];
int n;

int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		p[i] = make_pair(b, a);
	}
	sort(p, p + n);
	int t = 1, ans = 0, i = n - 1;
	while(t && i >= 0)
	{
		t--;
		ans += p[i].second;
		t += p[i].first;
		i--;
	}
	printf("%d\n",ans);
}
