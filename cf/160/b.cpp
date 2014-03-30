#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 205

char a[maxn];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",a);
	sort(a,a+n);
	sort(a+n,a+2*n);
	int temp = 0;
	for(int i = 0;i < n;i++)
		if(a[i] < a[i+n])
			temp++;
	if(temp == n)
		puts("YES");
	else
	{
		temp = 0;
		for(int i = 0;i < n;i++)
			if(a[i] > a[i+n])
				temp++;
		if(temp == n)
			puts("YES");
		else
			puts("NO");
	}
}
