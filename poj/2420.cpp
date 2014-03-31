#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 105
const double eps = 1e-10;
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
    double x,y;
    point(double a = 0,double b = 0):x(a),y(b){}
    point operator - (const point p)
    {
        return point(x - p.x,y - p.y);
    }
    point operator + (const point p)
    {
        return point(x + p.x,y + p.y);
    }
    double norm()
    {
        return sqrt(x * x + y * y);
    }
    point operator *(double a)
    {
        return point(x * a,y * a);
    }
}p[maxn],fermat,dir[30];
int n;
int main()
{
    scanf("%d",&n);
    {
        for(int i = 0;i < n;i++)
            scanf("%lf %lf",&p[i].x,&p[i].y);
        int cnt = 0;
        for(int i=-1;i<=1;i++)
            for(int j=-1;j<=1;j++)
                dir[cnt++] = point(i,j);
        double step = 20000;
        point now,ans;
        double temp = 1e10,calc;
        point sel;
        for(int i = 0;i < n;i++)
            ans = ans + p[i];
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
            step *= 0.985;
        }
        printf("%.0lf\n",temp);
    }
}
