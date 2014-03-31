#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#define PB push_back
using namespace std;
const int inf = ~0u >> 1;
const double eps = 1e-6;
const double pi = acos(-1.0);
int sgn(double x)
{
    return fabs(x) < eps ? 0:x < -eps?-1:1;
}
void gao()
{
    int n;
    double p;
    scanf("%d %lf",&n,&p);
    double ans = 0.0;
    for(int i = 1;i < n;i++)
        ans += 1.0 / (2.0 * p * i * (double)(n - i) / (double)((double)n * ((double)n - 1)));
    printf("%.3lf\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
        gao();
}
