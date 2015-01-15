#include <iostream>
#include <cstdio>
#include <cmath>
#define sqr(x) ((x) * (x))
const double eps = 1e-6;

using namespace std;

struct circle
{
    double x, y, r;
    circle(){}
    circle(double a, double b, double c):x(a), y(b), r(c){}
    void read(){scanf("%lf %lf %lf",&x,&y,&r);}
}c[12];
int n;

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)c[i].read();
    int xl(1000), yl(1000);
    double ans = 0;
    for(int i = 0;i < xl;i++)
        for(int j = 0;j < yl;j++)
        {
            bool mark = false;
            double x = (double)i/(double)xl, y = (double)j/(double)yl;
            for(int k = 0;k < n;k++)
            {
                if( sqr(x - c[k].x) + sqr(y - c[k].y) - sqr(c[k].r) <= 0)
                {
                    mark = true;
                    break;
                }

            }
            if(mark)
                ans += 1.0 / (double)xl / (double)yl;
        }
    printf("%lf\n",ans * 100);
}
