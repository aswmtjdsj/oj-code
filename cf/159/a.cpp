#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
using namespace std;
#define maxn 2002

int n, d;
typedef pair <string, string> pi;
set <pi> S;
set <pi> :: iterator it;
string a[maxn], b[maxn];
int t[maxn];
int main()
{
	cin >> n >> d;
	for(int i = 0;i < n;i++)
		cin >> a[i] >> b[i] >> t[i];
	for(int i = 0;i < n;i++)
	{
		for(int j = i + 1;j < n;j++)
		{
			if((a[i] == b[j] && b[i] == a[j]))
			{
				if(t[j] > t[i] && t[j] - t[i] <= d && S.find(make_pair(a[i],b[i])) == S.end() && S.find(make_pair(b[i], a[i])) == S.end())
					S.insert(make_pair(a[i],b[i]));
			}
		}
	}
	cout << S.size() << endl;
	for(it = S.begin();it != S.end();it++)
	{
		pi now = *it;
		cout << now.first << ' ' << now.second << endl;
	}
}
