#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define sqr(x) ((x) * (x))
#define MAXN 300
using namespace std;
double R;
const double pi = acos(-1.0);
const double eps = 1e-8;
struct point
{
    double x,y;
    void inc()
    {
        scanf("%lf%lf",&x,&y);
    }
    inline double friend dis(const point &a,const point &b)
    {
        return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
    }
}p[MAXN + 5];
struct arc
{
    double alpha;
    bool flag;
    bool friend operator <(const arc &p,const arc &q)
    {
        return p.alpha < q.alpha;
    }
}a[MAXN * MAXN + 5];
void solve(int n)
{
    for(int i = 0;i < n;i++)
        p[i].inc();
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        int cnt = 0;
        for(int j = 0;j < n;j++)
        {
            if(i == j)
                continue;
            double d = dis(p[i],p[j]);
            if(d > 2.0 * R + eps)
                continue;
            //printf("d %d %d:%lf\n",i,j,d);
            double theta = acos(d / (2.0 * R));
            double alpha = atan2(p[j].y - p[i].y,p[j].x - p[i].x);
            if(alpha < 0.0 + eps)
                alpha += pi * 2.0;
            a[cnt].alpha = alpha + theta + 2.0 * pi;
            a[cnt].flag = 0;
            //printf("a%d:%lf",cnt,a[cnt].alpha);
            cnt ++;
            a[cnt].alpha = alpha - theta + 2.0 * pi;
            a[cnt].flag = 1;
            //printf("a%d:%lf\n",cnt,a[cnt].alpha);
            cnt ++;
        }
        if(sum >= cnt / 2)
            continue;
        sort(a,a + cnt);
        //  for(int j(0);j < cnt;j++)
        //      printf("a%d:%lf %d\n",j,a[j].alpha,a[j].flag);
        int temp = 0;
        for(int j(0);j < cnt;j++)
        {
            if(a[j].flag)
                temp++;
            else
                temp--;
            if(temp > sum)
                sum = temp;
        }
    }
    printf("%d\n",sum + 1);
}
int main()
{
    int n;
    R = 1.0;
    //freopen("1679.in","r",stdin);
    while(scanf("%d",&n) == 1 && n)
    {
        solve(n);
    }
}
