#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 1e-8;
int comp(double x)
{
    return (fabs(x) < eps ? 0 : x < -eps?-1:1);
}
struct point
{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    point operator - (const point p)
    {
        return point(x - p.x,y - p.y);
    }
    double len()
    {
        return sqrt(x * x + y * y);
    }
    double operator ^ (const point p)
    {
        return x * p.y - y * p.x;
    }
}p[10];
double multi(point o,point a,point b)
{
    return (a - o) ^ (b - o);
}
bool online(point p1,point p2,point p)
{
    return comp(multi(p1,p2,p)) == 0 && comp((p.x - p1.x) * (p.x - p2.x)) <= 0 && comp((p.y - p1.y) * (p.y - p2.y)) <= 0;
}
bool ins(point p1,point p2,point p3,point p4,point &tmp)
{
    double a = fabs(multi(p3,p1,p2));
    double b = fabs(multi(p4,p1,p2));
    if(comp(a) == 0 && comp(b) == 0)
        return 0;
    double tx = (p4.x * a + p3.x * b) / (a + b);
    double ty = (p4.y * a + p3.y * b) / (a + b);
    tmp = point(tx,ty);
    if(online(p1,p2,tmp) && online(p3,p4,tmp))
        return 1;
    return 0;
}
int main()
{
    while(1)
    {
        int cnt = 0;
        for(int i = 0;i < 4;i++)
        {
            scanf("%lf %lf",&p[i].x,&p[i].y);
            if(comp(p[i].x + 1) == 0)
                cnt++;
            if(comp(p[i].y + 1) == 0)
                cnt++;
        }
        if(cnt == 8)
            break;
        double len = 1e20;
        for(int i = 0;i < 4;i++)
        {
            double temp = 0;
            for(int j = 0;j < 4;j++)
                temp += (p[i] - p[j]).len();
            if(comp(temp - len) < 0)
                len = temp;
        }
        point now;
        if(ins(p[0],p[1],p[2],p[3],now))
        {
            double temp = 0;
            for(int i = 0;i < 4;i++)
                temp += (now - p[i]).len();
            if(comp(temp - len) < 0)
                len = temp;
        }
        if(ins(p[0],p[2],p[1],p[3],now))
        {
            double temp = 0;
            for(int i = 0;i < 4;i++)
                temp += (now - p[i]).len();
            if(comp(temp - len) < 0)
                len = temp;
        }
        if(ins(p[0],p[3],p[1],p[2],now))
        {
            double temp = 0;
            for(int i = 0;i < 4;i++)
                temp += (now - p[i]).len();
            if(comp(temp - len) < 0)
                len = temp;
        }
        printf("%.4lf\n",len);
    }
}
