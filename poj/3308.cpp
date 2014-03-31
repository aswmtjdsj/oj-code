#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include <cmath>
#define maxn 210
#define maxm 2000
const double inf = 1e2;
const double eps = 1e-6;
struct edge 
{
    int p,next,anti;
    double val;
    edge(){}
    edge(int _p,int _next,double _val,int _anti):p(_p),next(_next),val(_val),anti(_anti){}
}v[maxn],e[maxm],arc[maxn],path[maxn];
int flow[maxn],pre[maxn],d[maxn],cnt[maxn],tot,n,N,M;
int comp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else if(x < -eps)
        return -1;
    else
        return 1;
}
void init()
{
    tot = 0;
    n = 2 * (N + M) + 1;
    for(int i = 0;i <= n;i++)
        v[i].next = -1;
    memset(d,0,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    cnt[0] = n + 1;
}
void add(int p,int q,double val)
{
    e[tot] = edge(q,v[p].next,val,tot + 1);
    v[p].next = tot++;
    e[tot] = edge(p,v[q].next,0,tot - 1);
    v[q].next = tot++;
}
double mflow()
{
    int s = 0,t = n;
    int i,k,least,loc;
    double total,now;
    bool flag;
    for(i = 0;i <= n;i++)arc[i].next = v[i].next;
    for(total = 0,i = s,now = inf;d[s] < n + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(comp(e[k].val) > 0 && d[i] == d[e[k].p] + 1)
            {
                now = min(e[k].val,now);
                pre[e[k].p] = i;
                arc[i].next = k;
                path[e[k].p].next = k;
                i = e[k].p;
                if(i == t)
                {
                    for(total += now;i != s;i = pre[i])
                    {
                        e[path[i].next].val -= now;
                        e[e[path[i].next].anti].val += now;
                    }
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n + 1,k = v[i].next;~k;k = e[k].next)
            {
                if(comp(e[k].val) > 0 && least > d[e[k].p])
                {
                    loc = k;
                    least = d[e[k].p];
                }
            }
            arc[i].next = loc;
            cnt[d[i]]--;
            if(!cnt[d[i]])
                break;
            d[i] = least + 1;
            cnt[d[i]]++;
            if(i != s)
            {
                i = pre[i];
                now = flow[i];
            }
        }
    }
    return total;
}
void gao()
{
    int l;
    scanf("%d %d %d",&N,&M,&l);
    init();
    for(int i = 1;i <= N;i++)
    {
        double val;
        scanf("%lf",&val);
        add(0,i,inf);
        add(i,i + N,log(val)/log(2.0));
    }
    for(int i = 1;i <= M;i++)
    {
        double val;
        scanf("%lf",&val);
        add(N + N + i,N + N + M + i,log(val)/log(2.0));
        add(N + N + M + i,n,inf);
    }
    for(int i = 0;i < l;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        add(a + N,b + N + N,inf);
    }
    double ans = mflow();
    printf("%.4lf\n",pow(2.0,ans));
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)gao();
}
