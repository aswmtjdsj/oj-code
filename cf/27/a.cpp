#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 3002

int a[maxn];
int n;
int main()
{
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	sort(a,a + n);
	int ans = 0;
	for(int i = 0;i < n;i++) if(i != a[i] - 1){ans = i + 1;break;}
	if(ans == 0) ans = n + 1;
	cout << ans << endl;
}
