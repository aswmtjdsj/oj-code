/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
/*
 * kruskal 
 * if 1 and 2 are connected then break
 * the current length of the edge is the ans...proved easily...
 * */
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define maxn (200 + 5)
using namespace std;
struct point
{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
    double norm()
    {
        return sqrt((double)(x * x + y * y));
    }
    point operator -(const point &q)
    {
        return point(x - q.x,y - q.y);
    }
}p[maxn];
double ans;
int n,tot;
struct edge
{
    double w;
    int u,v;
    edge(){}
    edge(int a,int b,double e):u(a),v(b),w(e){}
}e[maxn * maxn];
bool operator < (const edge &a,const edge &b)
{
    return a.w < b.w;
}
int pr[maxn],r[maxn];
int f(int x)
{
    if(pr[x] == x)
        return x;
    return pr[x] = f(pr[x]);
}
void kruskal()
{
    for(int i = 1;i <= n;i++)
    {
        pr[i] = i;
        r[i] = 1;
    }
    for(int i = 0;i < tot;i++)
    {
        ans = e[i].w;
        int u = f(e[i].u),v = f(e[i].v);
        if(u != v)
        {
            if(r[u] > r[v])
            {
                pr[v] = u;
                r[u] += r[v];
            }
            else
            {
                pr[u] = v;
                r[v] += r[u];
            }
        }
        if(f(1) == f(2))
            break;
    }
}
int main()
{
    int t = 1;
    while(scanf("%d",&n) == 1 && n)
    {
        ans = 0;
        tot = 0;
        for(int i = 1;i <= n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            p[i] = point(a,b);
        }
        for(int i = 1;i <= n;i++)
            for(int j = i + 1;j <= n;j++)
                e[tot++] = edge(i,j,(p[i] - p[j]).norm());
        sort(e,e + tot);    
        kruskal();
        printf("Scenario #%d\n",t++);
        printf("Frog Distance = %.3lf\n\n",ans);
    }
}
