#include <iostream>
#include <cmath>
using namespace std;
long long n, m;
const long long inf = 1000000000;
int main()
{
	cin >> n >> m;
	long long ans = 0;
	long long x, y, dx, dy;
	cin >> x >> y;
	int k;
	cin >> k;
	for(int i = 0;i < k;i++)
	{
		cin >> dx >> dy;
		long long detx = 0, dety = 0, det = 0;
		if(dx > 0)
			detx = (n - x) / dx;
		else if(dx < 0)
			detx = (x - 1) / (-dx);
		else
			detx = inf;//should be inf, not n
		if(dy > 0)
			dety = (m - y) / dy;
		else if(dy < 0)
			dety = (y - 1) / (-dy);
		else
			dety = inf;
		//cout << detx << ' ' << dety << endl;
		det = min(detx, dety);
		ans += det;
		x += det * dx;
		y += det * dy;
	}
	cout << ans << endl;
}
