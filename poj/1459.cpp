#include <iostream>
#include <cstdio>
#include <cstring>
#define maxv 110
#define maxe 24200
#define INF 200000000
using namespace std;
struct edge
{
    int p,val,next,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),val(b),next(c),anti(d){}
}e[maxe],v[maxv],arc[maxv],path[maxv];
int flow[maxv],d[maxv],cnt[maxv],pre[maxv],tot,n,m,N,np,nc;
void init()
{
    tot = 0;
    for(int i = 0;i <= n + 1;i++)
    {
        v[i].next = -1;
        d[i] = 0;
        cnt[i] = 0;
    }
    cnt[0] = n;
}
void add(int p,int q,int val)
{
    e[tot] = edge(q,val,v[p].next,tot + 1);
    v[p].next = tot++;
    e[tot] = edge(p,0,v[q].next,tot - 1);
    v[q].next = tot++;
}
int mflow(int s,int t)
{
    int i,total,now,k,loc,least;
    bool flag;
    for(i = 0;i <= n + 1;i++)
        arc[i].next = v[i].next;
    for(total = 0,now = INF,i = s;d[s] < n;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(d[i] == d[e[k].p] + 1 && e[k].val > 0)
            {
                if(e[k].val < now)
                    now = e[k].val;
                pre[e[k].p] = i;
                path[e[k].p].next = k;
                arc[i].next = k;
                i = e[k].p;
                if(i == t)
                {
                    for(total += now;i != s;i = pre[i])
                    {
                        e[path[i].next].val -= now;
                        e[e[path[i].next].anti].val += now;
                    }
                    now = INF;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n - 1,k = v[i].next;~k;k = e[k].next)
            {
                if(e[k].val > 0 && d[e[k].p] < least)
                {
                    loc = k;
                    least = d[e[k].p];
                }
            }
            arc[i].next = loc;
            cnt[d[i]]--;
            if(cnt[d[i]] == 0)
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
int main()
{
    while(scanf("%d %d %d %d",&N,&np,&nc,&m) == 4)
    {
        n = N + 2;
        init();
        for(int i = 0;i < m;i++)
        {
            int a,b,c;
            scanf(" (%d,%d)%d",&a,&b,&c);
            add(a,b,c);
        }
        for(int i = 0;i < np;i++)
        {
            int a,b;
            scanf(" (%d)%d",&a,&b);
            add(n,a,b);
        }
        for(int i = 0;i < nc;i++)
        {
            int a,b;
            scanf(" (%d)%d",&a,&b);
            add(a,n + 1,b);
        }
        printf("%d\n",mflow(n,n + 1));
    }
}
