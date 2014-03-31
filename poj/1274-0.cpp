#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 405
#define maxm 2 * maxn * maxn
#define INF 200000000
using namespace std;
struct edge
{
    int p,val,next,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),val(b),next(c),anti(d){}
}v[maxn],path[maxn],arc[maxn],e[maxm];
int flow[maxn],pre[maxn],d[maxn],cnt[maxn];
int m,n,tot;
void init()
{
    tot = 0;
    for(int i = 0;i <= m + n + 1;i++)
    {
        d[i] = 0;
        cnt[i] = 0;
        v[i].next = -1;
    }
    cnt[0] = m + n + 2;
}
void add(int a,int b,int c)
{
    e[tot] = edge(b,c,v[a].next,tot + 1);
    v[a].next = tot++;
    e[tot] = edge(a,0,v[b].next,tot - 1);
    v[b].next = tot++;
}
int mflow(int s,int t)
{
    int k,i,total,now,loc,least;
    bool flag;
    for(int i = 0;i <= m + n + 1;i++)
        arc[i].next = v[i].next;
    for(total = 0,now = INF,i = s;d[s] < m + n + 2;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(e[k].val > 0 && d[i] == d[e[k].p] + 1)
            {
                now = (e[k].val < now) ? e[k].val : now;
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
            for(least = m + n +1,k = v[i].next;~k;k = e[k].next)
            {
                if(e[k].val > 0 && d[e[k].p] < least)
                {
                    loc = k;
                    least = d[e[k].p];
                }
            }
            arc[i].next = loc;
            cnt[d[i]] --;
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
    while(scanf("%d%d",&n,&m) == 2)
    {
        init();
        for(int i = 1;i <= n;i++)
        {
            add(0,i,1);
            int op;
            scanf("%d",&op);
            for(int j = 1;j <= op;j++)
            {
                int p;
                scanf("%d",&p);
                add(i,n + p,1);
            }
        }
        for(int i = 1;i <= m;i++)
            add(i + n,m + n + 1,1);
        printf("%d\n",mflow(0,m + n + 1));
    }
}
