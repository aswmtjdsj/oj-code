#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 105
double r[maxn];
int n;
const double pi = acos(-1.0);
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		scanf("%lf",&r[i]);
	double ans = 0;
	sort(r, r + n);
	bool m = 1;
	for(int i = n - 1;i >= 0;i--)
	{
		if(m)
			ans += r[i] * r[i] * pi;
		else
			ans -= r[i] * r[i] * pi;
		m = !m;
	}
	printf("%lf\n",ans);
}
