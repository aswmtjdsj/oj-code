#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 105
const double eps = 1e-12;
int comp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else if(x < -eps)
        return -1;
    else
        return 1;
}
using namespace std;
struct point
{
    double x,y,z;
    point(double a = 0,double b = 0,double c = 0):x(a),y(b),z(c){}
    point operator - (const point p)
    {
        return point(x - p.x,y - p.y,z - p.z);
    }
    point operator + (const point p)
    {
        return point(x + p.x,y + p.y,z + p.z);
    }
    double norm()
    {
        return sqrt(x * x + y * y + z * z);
    }
    point operator *(double a)
    {
        return point(x * a,y * a,z * a);
    }
}p[maxn],fermat,dir[30];
int n;
int main()
{
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0;i < n;i++)
            scanf("%lf %lf %lf",&p[i].x,&p[i].y,&p[i].z);
        int cnt = 0;
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
                for(int k = -1;k <= 1;k++)
                    dir[cnt++] = point(i,j,k);
        double step = 1000;
        point now,ans;
        double temp = 1e10,calc;
        point sel;
        //  for(int i = 0;i < n;i++)
        //      ans = ans + p[i];
        //  ans = ans * (1.0 / (double)n);
        ans = p[1];
        while(step > eps)
        {
            sel = ans;
            for(int i = 0;i < cnt;i++)
            {
                calc = 0.0;
                now = ans + dir[i] * step;
                for(int idx = 0;idx < n;idx++)
                    calc += (p[idx] - now).norm();
                if(comp(calc - temp) < 0)
                {
                    sel = now;
                    temp = calc;
                }
            }
            ans = sel;
            step *= 0.95;
        }
        printf("%.3f %.3f %.3f\n",ans.x,ans.y,ans.z);
    }
}
