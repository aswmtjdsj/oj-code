#include <iostream>
#include <cstdio>
#include <cmath>
#define sqr(x) ((x) * (x))
using namespace std;
#define maxn 105
const double eps = 1e-6;
const double pi = acos(-1.0);
int comp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else if(x < -eps)
        return -1;
    else
        return 1;
}
struct point
{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
    point operator -(const point &p)
    {
        return point(x - p.x,y - p.y);
    }
    int operator *(const point &p)
    {
        return x * p.x + y * p.y;
    }
    int operator ^(const point &p)
    {
        return x * p.y - y * p.x;
    }
    int norm2()
    {
        return sqr(x) + sqr(y);
    }
}p[maxn],o;
int multi(point a,point b,point o)
{
    return (a - o) ^ (b - o);
}
int scalar(point a,point b,point o)
{
    return (a - o) * (b - o);
}
int n;
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    o = point(a,b);
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d %d",&a,&b);
        p[i] = point(a,b);
    }
    bool pos = false,neg = false;
    for(int i = 0;i < n;i++)
    {
        int a = i,b = (i + 1) % n;
        int flag = multi(p[a],p[b],o);
        if(flag > 0 && !pos)
            pos = true;
        if(flag < 0 && !neg)
            neg = true;
    }
    if(!(neg && pos))
    {
        printf("%.3lf\n",0.0);
        return 0;
    }
    //cout << pi / 2.0 << "pi" <<  endl;
    double r = 1e10;
    for(int i = 0;i < n;i++)
    {
        int a = i,b = (i + 1) % n;
        double lab = sqrt((double)(p[a] - p[b]).norm2()),lbo = sqrt((double)(o - p[b]).norm2()),lao = sqrt((double)(o - p[a]).norm2());
        int sbao = scalar(p[b],o,p[a]),sabo = scalar(p[a],o,p[b]);
        double bao = acos((double) sbao / (lab * lao)),abo = acos((double)sabo / ( lab * lbo));
        //cout << bao << ' ' << abo << endl;
        if(comp(bao - pi / 2.0) <= 0 && comp(abo - pi / 2.0) <= 0)
            r = min(r,fabs((double)multi(p[a],p[b],o)) / lab);
        else
            r = min(r,min(lbo,lao));
        //cout << r << endl;
    }
    printf("%.3lf\n",r * 2.0);
}