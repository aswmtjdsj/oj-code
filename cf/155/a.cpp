#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
#define maxn 1002
	int a[maxn];
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> a[i] ;
	int M,m,ans= 0;
	M = m = a[0];
	for(int i = 1;i < n;i++)
	{
		if(a[i] < m)
		{
			ans ++;
			m = a[i];
		}
		if(a[i] > M)
		{
			ans++;
			M = a[i];
		}
	}
	cout << ans << endl;
}
