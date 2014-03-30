#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		map <int,long long> M;
		for(int i = 0;i < n;i++)
		{
			int a;
			scanf("%d",&a);
			M[(long long)a]++;
		}
		long long ans = 0;
		for(int i = -10;i < 0;i++)
			ans += M[i] * M[-i];
		ans += (M[0]-1) * M[0] / 2;
		cout << ans << endl;
	}
}
