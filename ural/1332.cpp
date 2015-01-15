#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn 102
#define see(x) cerr << __LINE__ << " : " << #x << " " << x << endl
using namespace std;
struct point
{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    double norm()
    {
        return sqrt(x * x + y * y);
    }
    point operator - (const point &p)
    {
        return point(x - p.x,y - p.y);
    }
    point operator + (const point &p)
    {
        return point(x + p.x,y + p.y);
    }
}p[maxn],o;
const double eps = 1e-6;
int comp(double x)
{
    return fabs(x) < eps?0:x < -eps?-1:1;
}
double R,r;
int n;
void gao()
{
    int ans = 1;
    double tr = R - r;
    for(int i = 0;i < n;i++)
        for(int j = i + 1;j < n;j++)
        {
            double dis = (p[i] - p[j]).norm();
            if(comp(dis - 2.0 * tr) > 0)
                continue;
            point mid = point((p[i].x + p[j].x)/2.0,(p[i].y + p[j].y)/2.0);
            point c1,c2,to = point(mid - p[i]),vec = point(-to.y,to.x);
            double rate = sqrt(tr * tr - to.norm() * to.norm()) / vec.norm();
            /*see(vec.norm());
             *          see(rate);
             *                      puts("mid");
             *                                  see(mid.x);
             *                                              see(mid.y);*/
            vec.x *= rate;
            vec.y *= rate;
            c1 = mid + vec;
            c2 = mid - vec;
            //cout << c1.x << ' ' << c1.y << " c1" << endl;
            //cout << c2.x << ' ' << c2.y << " c2" << endl;
            int temp = 0;
            //puts("c1");
            for(int k = 0;k < n;k++)
            {
                double dis = (p[k] - c1).norm();
                //see(dis);
                if(comp(dis - tr) <= 0)
                    temp++;
            }
            if(ans < temp)
                ans = temp;
            temp = 0;
            //puts("c2");
            for(int k = 0;k < n;k++)
            {
                double dis = (p[k] - c2).norm();
                //see(dis);
                if(comp(dis - tr) <= 0)
                    temp++;
            }
            if(ans < temp)
                ans = temp;
        }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0;i < n;i++)
        {
            double a,b;
            scanf("%lf %lf",&a,&b);
            p[i] = point(a,b);
        }
        scanf("%lf %lf",&R,&r);
        if(comp(R - r) < 0)
            puts("0");
        else if(n == 1 || comp(R - r) == 0)
            puts("1");
        else
            gao();
    }
}