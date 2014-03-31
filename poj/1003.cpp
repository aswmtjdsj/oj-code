#include <iostream>
#include <cstdio>
#include <cmath>
const double eps = 1e-6;
using namespace std;
double sum(int x)
{
    double ans = 0.0;
    for(int i = 1;i <= x;i++)
        ans += 1.0 / (double)(i + 1);
    return ans;
}
void solve(double x)
{
    int lo = 1,hi = 500;
    while(lo < hi)
    {
        int mid = (lo + hi ) / 2;
        // cout << mid << "," << sum(mid) << endl;
        if(fabs(sum(mid) - x) < eps)
            break;
        else if(sum(mid) < x)
            lo = mid;
        else if(sum(mid - 1) > x)
            hi = mid;
        else if(sum(mid - 1) < x && sum(mid) > x)
            break;
    }
    printf("%d card(s)\n",(lo + hi) / 2);
}
int main()
{
    double x;
    while(cin >> x)
    {
        if(fabs(x) < eps)
        {
            return 0;
        }
        else
        {
            solve(x);
        }
    }
}
