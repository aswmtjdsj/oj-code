#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int p, d, t, f, c;

bool gao(int x)
{
	int s = t * p;
	while(s < c && x >= 0)
	{
	}
	return x >= 0;
}

int main()
{
	scanf("%d %d %d %d %d", &p, &d, &t, &f, &c);
	int l = 0, r = c, mid;
	while(l < r)
	{
		mid = (l + r) >> 1;
		if(gao(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n",l);
}
