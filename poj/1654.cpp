/*
 * Coded by BUPT-[aswmtjdsj] @ BSW in 915
 * */
/*
 * cross product's application
 * MIND the MEMORY LIMIT!!!
 * */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
struct point
{
    ll x,y;
    void init(char a,point o)
    {
        switch(a)
        {
            case '1':
                x = o.x - 1;
                y = o.y - 1;
                break;
            case '2':
                x = o.x;
                y = o.y - 1;
                break;
            case '3':
                x = o.x + 1;
                y = o.y - 1;
                break;
            case '4':
                x = o.x - 1;
                y = o.y;
                break;
            case '6':
                x = o.x + 1;
                y = o.y;
                break;
            case '7':
                x = o.x - 1;
                y = o.y + 1;
                break;
            case '8':
                x = o.x;
                y = o.y + 1;
                break;
            case '9':
                x = o.x + 1;
                y = o.y + 1;
                break;
        }
    }
} p1,p2;
inline double cross(point p,point q)
{
    return p.x * q.y - p.y * q.x;
}
void solve()
{
    char a;
    int i = 1;
    p1.x = 0;
    p1.y = 0;
    double s = 0.0;
    while((a = getchar()) != '5')
    {
        if(a >= '1' && a <= '9')
        {
            if(i % 2)
            {
                p2.init(a,p1);
                s += cross(p2,p1);
            }
            else
            {
                p1.init(a,p2);
                s += cross(p1,p2);
            }
            i++;
        }
    }
    if((ll)fabs(s) % 2)
        printf("%.1lf\n",fabs(s / 2));
    else
        printf("%.0lf\n",fabs(s / 2));

}
int main()
{
    int t;
    while(scanf("%d",&t) != EOF)
    {
        for(int i = 0;i < t;i++)
            solve();
    }
}
