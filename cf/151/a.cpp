#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, k, l, c, d, p, nl, np;
	scanf("%d %d %d %d %d %d %d %d",&n, &k, &l, &c, &d, &p, &nl, &np);
	int ans = min(k * l / n / nl,min(c * d / n, p /np / n));
	cout << ans << endl;
}
