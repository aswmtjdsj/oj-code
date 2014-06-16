#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define maxn 105
using namespace std;
const double pi = acos(-1.0);
struct point
{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    point operator - (const point &p)
    {
        return point(x - p.x,y - p.y);
    }
    point operator + (const point &p)
    {
        return point(x + p.x,y + p.y);
    }
    double operator * (const point &p)
    {
        return x * p.x + y * p.y;
    }
    double operator ^ (const point &p)
    {
        return x * p.y - y * p.x;
    }
    double norm()
    {
        return sqrt(x * x + y * y);
    }
}sun,earth,vec[maxn],p[maxn],cutl,cutr;
double multi(point a,point b,point o)
{
    return (a - o) ^ (b - o);
}
double r;
int T1,T2,T;
int n;
const double eps = 1e-6;
int comp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else if(x < -eps)
        return -1;
    else
        return 1;
}
point rotate(point a,point o,double theta)
{
    point vec = a - o;
    point to = point(vec.x * cos(theta) - vec.y * sin(theta),vec.x * sin(theta) + vec.y * cos(theta));
    return o + to;
}
double tarea(point p0,point p1,point p2)
{
    double k = p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y;
    return k / 2;
}
bool cmp(point p,point q)
{
    double t1 = atan2(p.y - sun.y,p.x - sun.x),t2 = atan2(q.y - sun.y,q.x - sun.x);
    return (comp(t1 - t2) > 0);
}
struct line
{
    double a,b,c;
    line(){}
    line(point p,point q)
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
            c = -(p.x + b * p.y);
        }
    }
};
bool arc(line llll,point &P)
{
    double a = llll.a,b = llll.b,c = llll.c;
    double A = b * b + 1,B = 2.0 * b * c + 2.0 * b * earth.x - 2.0 * earth.y,C = c * c + 2.0 * c * earth.x + earth.x * earth.x + earth.y * earth.y - r * r;
    double det = B * B - 4.0 * A * C;
    if(comp(det) < 0)
        return false;
    else if(comp(det) == 0)
    {
        double x,y;
        y = (-B + sqrt(det)) / (2.0 * A);
        x = -(b * y + c);
        point w(x,y);
        P = w;
        return true;
    }
    else
    {
        double y1 = (-B + sqrt(det))/(2.0 * A),y2 = (-B - sqrt(det)) / (2.0 * A);
        double x1 = -(b * y1 + c),x2 = -(b * y2 + c);
        point w1(x1,y1),w2(x2,y2);
        double dis1 = (w1 - sun).norm(),dis2 = (w2 - sun).norm();
        if(comp(dis1 - dis2) > 0)
            P = w2;
        else
            P = w1;
        return true;
    }
}
void calc()
{
    double a,b,c;
    a = (sun.y - earth.y) * (sun.y - earth.y) + (sun.x - earth.x) * (sun.x - earth.x);
    b = -2.0 * earth.y * ((sun.y - earth.y) * (sun.y - earth.y) + (sun.x - earth.x) * (sun.x - earth.x)) - 2.0 * r * r * (sun.y - earth.y);
    c = r * r * r * r + 2.0 * r * r * (sun.y - earth.y) * earth.y - r * r * (sun.x - earth.x) * (sun.x - earth.x) + earth.y * earth.y * ((sun.y - earth.y) * (sun.y - earth.y) + (sun.x - earth.x) * (sun.x - earth.x));
    double det = b * b - 4.0 * a * c;
    double y1 = (-b + sqrt(det))/(2.0 * a),y2 = (-b - sqrt(det)) / (2.0 * a);
    double x1 = (r * r - (sun.y - earth.y) * (y1 - earth.y)) / (sun.x - earth.x) + earth.x;
    double x2 = (r * r - (sun.y - earth.y) * (y2 - earth.y)) / (sun.x - earth.x) + earth.x;
    cutl = point(x1,y1),cutr = point(x2,y2);
    if(!cmp(cutl,cutr))
        swap(cutl,cutr);
}
double len(point a,point b)
{
    point vec1 = point(a - earth),vec2 = point(b - earth);
    double value = (vec1 * vec2) / (vec1.norm() * vec2.norm());
    if(comp(value - 1.0) >= 0)
        value = 1.0;
    double theta = acos(value);
    return r * theta;
}
int main()
{
    //int cas = 0;
    while(scanf("%lf %lf %lf %lf %lf",&sun.x,&sun.y,&earth.x,&earth.y,&r) == 5)
    {
        //cas++;
        //calc arc
        calc();
        scanf("%d %d %d %d",&n,&T1,&T2,&T);
        for(int i = 0;i < n;i++)
        {
            double x,y;
            scanf("%lf %lf",&x,&y);
            p[i] = point(x,y);
        }
        int t1 = T % T1,t2 = T % T2;
        double gong = 2.0 * pi * (double)t1 / (double)T1,zi = 2.0 * pi * (double) t2 / (double) T2;
        point zhong,temp(0,0);
        double area = 0,sumx = 0,sumy = 0,sarea = 0;
        for(int i = 1;i < n - 1;i++)
        {
            temp.x = p[0].x + p[i].x + p[i+1].x;
            temp.y = p[0].y + p[i].y + p[i+1].y;
            area = tarea(p[0],p[i],p[i+1]);
            sarea += area;
            sumx += temp.x * area;
            sumy += temp.y * area;
        }
        zhong = point(sumx / sarea / 3,sumy / sarea / 3);
        for(int i = 0;i < n;i++)
            vec[i] = p[i] - zhong;
        //rotate the gravity point
        zhong = rotate(zhong,earth,gong);
        //gongzhuan
        for(int i = 0;i < n;i++)
            p[i] = vec[i] + zhong;
        //zizhuan
        for(int i = 0;i < n;i++)
            p[i] = rotate(p[i],zhong,zi);
        sort(p,p + n,cmp);
        if(!cmp(cutl,cutr))
            swap(cutl,cutr);
        point L = p[0],R = p[n - 1];
        if(!cmp(L,R))
            swap(L,R);
        point xl,xr;
        line LE = line(sun,L),RI = line(sun,R);
        if(comp(multi(L,cutl,sun)) <= 0)
            xl = cutl;
        else if(comp(multi(L,cutr,sun)) >= 0)
            xl = cutr;
        else
            arc(LE,xl);
        if(comp(multi(R,cutl,sun)) <= 0)
            xr = cutl;
        else if(comp(multi(R,cutr,sun)) >= 0)
            xr = cutr;
        else
            arc(RI,xr);
        double len1 = len(cutl,cutr),len2 = len(xl,xr);
        if(comp((L - sun).norm() - (xl - sun).norm()) > 0 || comp((R - sun).norm() - (xr - sun).norm()) > 0)
            len2 = 0;
        double ans = len1 - len2;
        printf("%.2lf\n",ans);
    }
}
