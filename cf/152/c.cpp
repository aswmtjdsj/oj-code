#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const long long mod = 1000000007;

#define maxn 102
int n, m;
char str[maxn][maxn];
int main()
{
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> str[i];
	long long ans = 1;
	bool alpha[30];
	for(int i = 0;i < m;i++)
	{
		memset(alpha, 0,sizeof(alpha));
		for(int j = 0;j < n;j++)
			alpha[str[j][i] - 'A'] = 1;
		int temp = 0;
		for(int j = 0;j < 26;j++)
			if(alpha[j])
				temp++;
		ans = (ans * temp) % mod;
	}
	cout << ans << endl;
}
