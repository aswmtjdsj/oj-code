#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 205
#define maxm 405
using namespace std;
const int INF = 200000000;
struct edge
{
    int p,next,val,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),next(b),val(c),anti(d){}
}v[maxn],path[maxn],arc[maxn],e[maxm];
int flow[maxn],d[maxn],cnt[maxn],pre[maxn],n,m,tot;
void init()
{
    tot = 0;
    for(int i = 1;i <= n;i++)
    {
        v[i].next = -1;
        d[i] = 0;
        cnt[i] = 0;
        path[i].next = -1;
    }
    cnt[0] = n;
}
void add(int a,int b,int c)
{
    e[tot] = edge(b,v[a].next,c,tot + 1);
    v[a].next = tot ++;
    e[tot] = edge(a,v[b].next,0,tot - 1);
    v[b].next = tot ++;
}
int mflow(int s,int t)
{
    int i,k,total,now,least,loc;
    bool flag;
    for(i = 1;i <= n;i++)
        arc[i].next = v[i].next;
    for(i = s,total = 0,now = INF;d[s] < n;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(e[k].val > 0 && d[i] == d[e[k].p] + 1)
            {
                if(now > e[k].val)
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
            cnt[d[i]] -- ;
            if(cnt[d[i]] == 0)
                break;
            d[i] = least + 1;
            cnt[d[i]] ++;
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
    while(scanf("%d %d",&m,&n) == 2)
    {
        init();
        for(int i = 0;i < m ;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            add(a,b,c);
        }
        printf("%d\n",mflow(1,n));
    }
}
