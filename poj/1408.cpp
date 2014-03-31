/*
     Coded by BUPT-[aswmtjdsj] @ Penalty in 915
     */
/*
 * analysis geometry
 * ax + by + c = 0
 * enumeration....
 * vector product
 * */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a[5][35];
int n;
const double eps = 1e-6;
int comp(double a)
{
    if(fabs(a) < eps)
        return 0;
    else if(a > eps)
        return 1;
    else
        return -1;
}

struct position
{
    double x,y;
    position(){}
    position(double a,double b):x(a),y(b){}
    position operator -(const position &temp)
    {
        return position(x - temp.x,y - temp.y);
    }
}pos[35][35];
struct seg
{
    position p,q;
    double a,b,c;
    seg(){}
    seg(position m,position n):p(m),q(n)
    {
        if(comp(p.x - q.x) == 0)
        {
            a = 1.0;
            b = 0.0;
            c = -p.x;
        }
        else if(comp(p.y - q.y) == 0)
        {
            a = 0.0;
            b = 1.0;
            c = -p.y;
        }
        else
        {
            a = 1.0;
            b = -(p.x - q.x) / (p.y - q.y);
            c = -(b * p.y + p.x);
        }
    }
};
bool calc(seg x,seg y,position &out)
{
    if(comp(x.b) == 0 && comp(y.a) == 0)
    {
        out.x = x.p.x;
        out.y = y.p.y;
        return true;
    }
    else
    {
        out.y = -(y.c * x.a - x.c * y.a) / (y.b * x.a - x.b * y.a);
        out.x = -(y.b * out.y + y.c)/y.a;
        return true;
    }
    return false;
}
double cha(position a,position b,position c)
{
    return (c - b).y * (b - a).x - (c - b).x * (b - a).y;
}
void solve()
{
    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= n;j++)
            scanf("%lf",&a[i][j]);
    for(int i = 0;i <= n + 1;i++)
    {
        for(int j = 0;j <= n + 1;j++)
        {
            if(i == 0)
            {
                if(j == 0)
                    pos[i][j] = position(0,0);
                else if(j == n + 1)
                    pos[i][j] = position(1,0);
                else
                    pos[i][j] = position(a[1][j],0);
            }
            else if(i == n + 1)
            {
                if(j == 0)
                    pos[i][j] = position(0,1);
                else if(j == n + 1)
                    pos[i][j] = position(1,1);
                else
                    pos[i][j] = position(a[2][j],1);
            }
            else
            {
                if(j == 0)
                    pos[i][j] = position(0,a[3][i]);
                else if(j == n + 1)
                    pos[i][j] = position(1,a[4][i]);
                else
                {
                    position d(a[1][j],0),u(a[2][j],1),l(0,a[3][i]),r(1,a[4][i]);
                    calc(seg(d,u),seg(l,r),pos[i][j]);
                }
            }
        }
    }
    double ans = 0;
    for(int i = 0;i < n + 1;i++)
    {
        for(int j = 0;j < n + 1;j++)
        {
            double temp = 0;
            temp += cha(pos[i][j],pos[i][j + 1],pos[i + 1][j + 1]);
            temp += cha(pos[i][j + 1],pos[i + 1][j + 1],pos[i + 1][j]);
            temp += cha(pos[i + 1][j + 1],pos[i + 1][j],pos[i][j]);
            temp += cha(pos[i + 1][j],pos[i][j],pos[i][j + 1]);
            temp /= 4.0;
            if(ans < temp)
                ans = temp;
        }
    }
    printf("%.6lf\n",ans);
}
int main()
{
    while(scanf("%d",&n) == 1 && n)
        solve();
}
