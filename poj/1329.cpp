#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 1005
#define sqr(x) ((x) * (x))
int n;
const double eps = 1e-5;
int sgn(double x)
{
    return fabs(x) < eps ? 0 : x < -eps ? -1: 1;
}
struct point
{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    point operator - (point p){return point(x - p.x,y - p.y);}
    point operator + (point p){return point(x + p.x,y + p.y);}
    double norm(){return sqrt(sqr(x) + sqr(y));}
    double operator * (point p){return x * p.x + y * p.y;}
    point operator * (double a){return point(x * a,y * a);}
    double operator ^ (point p){return x * p.y - y * p.x;}
}p[maxn];
bool line(point a,point b,point c){return sgn((a - b) ^ (a - c)) == 0;}
struct circle
{
    point o;
    double r;
    circle(){}
    circle(point _o,double _r):o(_o),r(_r){}
    circle(point a,point b)
    {
        o = (a + b) * 0.5;
        r = (a - b).norm() * 0.5;
    }
    circle(point a,point b,point c)
    {
        if(sgn((a - b) * (c - b)) == 0)
        {
            o = point((a + c) * 0.5);
            r = (a - c).norm() * 0.5;
        }
        else if(sgn((c - a) * (b - a)) == 0)
        {
            o = point((c + b) * 0.5);
            r = (c - b).norm() * 0.5;
        }
        else if(sgn((a - c) * (b - c)) == 0)
        {
            o = point((a + b) * 0.5);
            r = (a - b).norm() * 0.5;
        }
        else if(sgn((b.x - a.x) * (b.x - c.x)))
        {
            o.y = (((sqr(b.y) - sqr(c.y)) * (b.x - a.x) - (sqr(b.y) - sqr(a.y)) * (b.x - c.x)) + (b.x - c.x) * (b.x - a.x) * (c.x - a.x)) / (2.0 * ((b - a) ^ (b - c)));
            o.x = ((a.y + b.y) * 0.5 - o.y) * (b.y - a.y) / (b.x - a.x) + (a.x + b.x) * 0.5;
            r = (b - o).norm();
        }
        else
        {
            o.x = (((sqr(b.x) - sqr(a.x)) * (b.y - c.y) - (sqr(b.x) - sqr(c.x)) * (b.y - a.y)) + (a.y - c.y) * (b.y - a.y) * (b.y - c.y)) / (2.0 * ((b - a) ^ (b - c)));
            o.y = ((a.x + b.x) * 0.5 - o.x) * (b.x - a.x) / (b.y - a.y) + (a.y + b.y) * 0.5;
            r = (b - o).norm();
        }
    }
    bool in(point x)
    {
        return sgn((x - o).norm() - r) <= 0;
    }
};
int main()
{
    while(scanf("%lf %lf %lf %lf %lf %lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y) == 6)
    {
        circle ans(p[0],p[1],p[2]);
        double h = ans.o.x,k = ans.o.y,r = ans.r,c = 2.0 * h,d = 2.0 * k,e = sqr(h) + sqr(k) - sqr(r);
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",sgn(h)<=0?'+':'-',fabs(h),sgn(k)<=0?'+':'-',fabs(k),r);
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n",sgn(c)<=0?'+':'-',fabs(c),sgn(d)<=0?'+':'-',fabs(d),sgn(e)>=0?'+':'-',fabs(e));
        puts("");
    }
}
