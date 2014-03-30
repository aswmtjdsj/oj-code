#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 3002

bool is[maxn];
int prime[500];
int cnt;

void pre()
{
	cnt = 1;
	memset(is, 0, sizeof(is));
	is[2] = true;
	for(int i = 3;i <= 3000;i += 2)
		is[i] = true;
	for(int i = 3;i <= 3000;i += 2)
	{
		if(is[i])
		{
			for(int j = i << 1;j <= 3000;j += i)
				is[j] = false;
		}
	}
	prime[0] = 2;
	for(int i = 3;i <= 3000;i += 2)
		if(is[i])
			prime[cnt++] = i;
}

int main()
{
	pre();
	//cout << cnt << endl;
	//for(int i = 0;i < cnt;i++)
	//	cout << prime[i] << endl;
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 6;i <= n;i++)
	{
		int temp = 0;
		for(int j = 0;j < cnt && prime[j] <= i;j++)
			if(i % prime[j] == 0)
			{
				temp++;
				if(temp > 2)
					break;
			}
		if(temp == 2)
			ans++;
	}
	cout << ans << endl;
}
