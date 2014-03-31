*
* Coded by BUPT-[aswmtjdsj] @ BSW in 608
* */
/*
 * common cross - product application
 * select the first point as the original point 
 * use cross product in order and fabs and floor function you can get the final result
 * but !!!! the sample is wrong in the "return"
 * the last 0 is not "0" is "10"(with the previous "1")
 * */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
    double x,y;
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
point o;
inline double cross(point p,point q)
{
    return (p.x - o.x) * (q.y - o.y) - (p.y - o.y) * (q.x - o.x); 
}
void solve(int t)
{
    double s = 0.0;
    point p,q;
    o.input();
    if(t > 1)p.input();
    for(int i = 2;i < t;i++)
    {
        if(i % 2)
        {
            p.input();
            s += cross(q,p);
        }
        else
        {
            q.input();
            s += cross(p,q);
        }
    }
    if(t <= 2)
        printf("0\n");
    else
    {
        s = fabs(s) / 2.0;
        printf("%.0lf\n",(s - floor(s) >= 0.5)?floor(s + 1):floor(s));
    }
}
int main()
{
    int t;
    while(scanf("%d",&t) != EOF && t)
    {
        solve(t);
    }
}
