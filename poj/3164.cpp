#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 105
#define type double
const double inf = 1e20;
const double eps = 1e-8;
int comp(double x)
{
    return fabs(x) < eps?0:x < -eps?-1:1;
}
struct node
{
    int u,v;
    type cost;
    node(){}
    node(int _u,int _v,type _c):u(_u),v(_v),cost(_c){}
}e[maxn * maxn];
int pre[maxn],id[maxn],vis[maxn];
type in[maxn];
type dirmst(int root,int nv,int ne)
{
    type ret = 0;
    while(1)
    {
        //find the smallest in-arc
        fill(in,in + nv,inf);
        for(int i = 0;i < ne;i++)
        {
            int u = e[i].u;
            int v = e[i].v;
            if(e[i].cost < in[v] && u != v)
            {
                pre[v] = u;
                in[v] = e[i].cost;
            }
        }
        for(int i = 0;i < nv;i++)
        {
            if(i == root)
                continue;
            if(comp(in[i] - inf) == 0)
                return -1;//there are some nodes other than root with no in-arc connected to it
        }
        //find the dir circle
        int cntnode = 0;
        fill(id,id + nv,-1);
        fill(vis,vis + nv,-1);
        in[root] = 0;
        for(int i = 0;i < nv;i++)
        {
            ret += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1)
            {
                for(int u = pre[v]; u != v;u = pre[u])
                    id[u] = cntnode;
                id[v] = cntnode++;
            }
        }
        if(cntnode == 0)
            break;//no circle
        for(int i = 0;i < nv;i++)
            if(id[i] == -1)
                id[i] = cntnode++;
        //compress the nodes
        for(int i = 0;i < ne;i++)
        {
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if(e[i].u != e[i].v)
                e[i].cost -= in[v];
        }
        nv = cntnode;
        root = id[root];
    }
    return ret;
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
    double norm()
    {
        return sqrt(x * x + y * y);
    }
}p[maxn];
int n,m;
int main()
{
    while(scanf("%d %d",&n,&m) == 2)
    {
        for(int i = 1;i <= n;i++)
        {
            double a,b;
            scanf("%lf %lf",&a,&b);
            p[i] = point(a,b);
        }
        for(int i = 0;i < m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            double temp = (p[a] - p[b]).norm();
            a--;
            b--;
            e[i] = node(a,b,temp);
        }
        double ans = dirmst(0,n,m);
        if(comp(ans + 1) == 0)
            puts("poor snoopy");
        else
            printf("%.2lf\n",ans);
    }
}
