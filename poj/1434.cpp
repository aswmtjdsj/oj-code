#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 50005
using namespace std;
struct cn
{
    int b,h,w,d;
    cn(){}
    cn(int _b,int _h,int _w,int _d):b(_b),h(_h),w(_w),d(_d){}
}p[maxn];
const double eps = 1e-3;
const double inf = 2 * 1e6;
int comp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else if(x > eps)
        return 1;
    else
        return -1;
}
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        p[i] = cn(a,b,c,d);
    }
    double v;
    scanf("%lf",&v);
    double lo = 0.0,hi = inf,mid,temp;
    while(comp(lo - hi) != 0)
    {
        temp = v;
        bool mark = false;
        mid = (lo + hi) / 2.0;
        for(int i = 0;i < n;i++)
        {
            if(comp(mid - p[i].b) >= 0)
            {
                if(comp(mid - p[i].b - p[i].h) >= 0)
                    temp -= p[i].h * p[i].w * p[i].d;
                else
                    temp -= (mid - p[i].b) * p[i].w * p[i].d;
            }
            if(comp(temp) <= 0)
            {
                mark = true;
                break;
            }
        }
        //cout << mid << endl;
        if(mark)
            hi = mid;
        else
            lo = mid;
    }
    if(comp(mid - inf) >= 0)
        puts("OVERFLOW");
    else
        printf("%.2lf\n",mid);
}
int main()
{
    int k;
    scanf("%d",&k);
    while(k--)solve();
}
