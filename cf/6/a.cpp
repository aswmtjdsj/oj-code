#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[4],b[4];
	for(int i = 0;i <4 ;i++)cin>>a[i];
	for(int i = 0;i <4 ;i++)b[i]=a[i];
	sort(a,a+4);
	bool mark = 0;
	do
	{
		if(a[0] + a[1] > a[2] && a[0] - a[1] < a[2] && a[0] - a[1] >= 0)
			mark = 1;
	}while(next_permutation(a,a + 4));
	if(mark)
	{puts("TRIANGLE");return 0;}
	mark = 0;
	for(int i = 0;i <4 ;i++)a[i]=b[i];
	sort(a,a+4);
	do
	{
		if(a[0] + a[1] == a[2])
			mark = 1;
	}while(next_permutation(a,a + 4));
	if(mark)
		puts("SEGMENT");
	else
		puts("IMPOSSIBLE");
}
