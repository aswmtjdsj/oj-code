#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-6;
struct point
{
    double x,y;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
} p[1005];
void print(int i,point p)
{
    printf("CP%d: (%.3lf, %.3lf)\n",i,p.x,p.y);
}
inline double len(point p,point q)
{
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}
double l[1005];
void solve(int n,int m)
{
    double length = 0.0,seg = (double) m + 1.0;
    p[0].x = p[0].y = 0.0;
    for(int i = 1;i <= n;i++)
        p[i].input();
    int i = 1,t = 1;
    for(int i = 0;i < n;i++)
    {
        l[i] = len(p[i],p[i + 1]);
        length += l[i];
    }
    double step = length / seg,temp;
    temp = step;
    point o = p[0];
    while(t <= m)
    {
        double ll = len(o,p[i]);
        if(temp < ll)
        {
            point tt = o;
            o.x = temp / ll * (p[i].x - tt.x) + tt.x;
            o.y = temp / ll * (p[i].y - tt.y) + tt.y;
            print(t,o);
            t++;
            temp = step;
        }
        else if(fabs(temp - ll) < eps)
        {
            o.x = p[i].x;
            o.y = p[i].y;
            print(t,o);
            t++;
            i++;
            temp = step;
        }
        else
        {
            o.x = p[i].x;
            o.y = p[i].y;
            temp -= ll;
            i++;
        }
    }
}
int main()
{
    //freopen("zt.in","r",stdin);
    int n,m,ca = 1;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        printf("Route %d\n",ca++);
        solve(n,m);
    }
}
