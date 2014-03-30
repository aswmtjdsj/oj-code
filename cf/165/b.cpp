#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, k[40], K;

void pre()
{
	k[0] = 1;
	int i = 0;
	while(k[i] < n)
	{
		i++;
		k[i] = k[i-1] * K;
	}
}
bool gao(int x)
{
	int i = 0;
	int temp = 0;
	while(x / k[i])
	{
		temp += x / k[i++];
		if(temp >= n)
			break;
	}
	return temp >= n;
}

int main()
{
	scanf("%d %d",&n,&K);
	pre();
	int l = 0, r = n, mid;
	while(l < r)
	{
		mid = (l + r) >> 1;
		if(gao(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", l);
}
