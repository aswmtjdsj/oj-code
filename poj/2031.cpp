/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
//prim
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn (100 + 5)
using namespace std;
const double eps = 1e-6;
const double inf = 1e30;
int comp(double a)
{
    if(fabs(a) < eps)
        return 0;
    else if(a > eps)
        return 1;
    else
        return -1;
}
struct point
{
    double x,y,z,r;
    point(){}
    point(double a,double b,double c,double d):x(a),y(b),z(c),r(d){}
    point operator -(const point &q)
    {
        return point(x - q.x,y - q.y,z - q.z,r);
    }
    double norm()
    {
        return sqrt(x * x + y * y + z * z);
    }
}p[maxn];
int n;
double ans,dis[maxn][maxn],len[maxn];
bool in[maxn];
void prim()
{
    memset(in,false,sizeof in);
    len[0] = 0.0;
    for(int i = 1;i < n;i++)
        len[i] = inf;
    for(int k = 0;k < n;k++)
    {
        int mark = 0;
        double MIN = inf;
        for(int i = 0;i < n;i++)
        {
            if(!in[i] && len[i] < MIN)
            {
                mark = i;
                MIN = len[i];
            }
        }
        in[mark] = true;
        ans += len[mark];
        for(int i = 0;i < n;i++)
            if(!in[i] && dis[i][mark] < len[i])
                len[i] = dis[i][mark];
    }
}
int main()
{
    while(scanf("%d",&n) == 1 && n)
    {
        ans = 0;
        for(int i = 0;i < n;i++)
        {
            double a,b,c,d;
            scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
            p[i] = point(a,b,c,d);
            //cout << p[i].x << p[i].y << p[i].z << p[i].r << endl;
        }
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                double temp = (p[i] - p[j]).norm() - p[i].r - p[j].r;
                dis[i][j] = (comp(temp) <= 0)?0.0:temp;
                //cout << dis[i][j];
                //cout << ((j == n - 1)?'\n':' ');
            }
        }
        prim();
        printf("%.3lf\n",ans);
    }
}
