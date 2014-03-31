#include <cstdio>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 10005
const double eps = 1e-12;
int cmp(double x){return fabs(x) < eps? 0 : x > eps? 1 : -1;}
double a[maxn], b[maxn], c[maxn];
int n;
double gao(double x)
{
    double temp = - 10000000.0;
    for(int i = 0;i < n; i++)
        temp = max(temp, a[i] * x*x+b[i]*x+c[i]);
    return temp;
}
int main()
{
    int t;
    scanf("%d", &t);
    for(int k = 0; k < t; k ++)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
        double l = 0, r = 1000, m, mm;
        while(cmp(l-r)<0)
        {
            m=(l+r)/2;
            mm=(m+r)/2;
            if(cmp(gao(m)-gao(mm))<0)
                r=mm;
            else
                l=m;
        }
        printf("%.4lf\n", gao(l));
    }
}
