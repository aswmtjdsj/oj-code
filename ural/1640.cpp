#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 105
const double eps = 1e-9;
double x[maxn],y[maxn],cx,cy,r;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    cx = cy = 0.1;
    r = 0.0;
    for(int i = 0;i < n;i++)
        r = max(r,sqrt((cx - x[i]) * (cx - x[i]) + (cy - y[i]) * (cy - y[i])));
    printf("%.10lf %.10lf %.10lf\n",cx,cy,r);
}