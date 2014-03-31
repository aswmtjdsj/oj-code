#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 405
#define maxm 45000
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val,anti;
    edge(){}
    edge(int _p,int _n,int _v,int _a):p(_p),next(_n),val(_v),anti(_a){}
}e[maxm];
int flow[maxn],v[maxn],arc[maxn],cnt[maxn],d[maxn],path[maxn],pre[maxn];
int tot,n,N,F,D;
void init()
{
    n = N + N + F + D + 1;
    tot = 0;
    for(int i = 0;i <= n;i++)
        v[i] = -1;
    memset(d,0,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    cnt[0] = n + 1;
}
void add(int p,int q,int val)
{
    e[tot] = edge(q,v[p],val,tot + 1);
    v[p] = tot++;
    e[tot] = edge(p,v[q],0,tot - 1);
    v[q] = tot++;
}
int mflow()
{
    int s = 0,t = n;
    for(int i = 0;i <= n;i++)
        arc[i] = v[i];
    int sum,k,loc,i,least,now;
    bool flag;
    for(sum = 0,now = inf,i = s;d[s] < n + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i];~k;k = e[k].next)
        {
            if(e[k].val && d[i] == d[e[k].p] + 1)
            {
                now = min(now,e[k].val);
                path[e[k].p] = k;
                pre[e[k].p] = i;
                arc[i] = k;
                i = e[k].p;
                if(i == t)
                {
                    for(sum += now;i != s;i = pre[i])
                    {
                        e[path[i]].val -= now;
                        e[path[i]^1].val += now;
                    }
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n + 1,k = v[i];~k;k = e[k].next)
            {
                if(e[k].val && d[e[k].p] < least)
                {
                    least = d[e[k].p];
                    loc = k;
                }
            }
            cnt[d[i]]--;
            if(cnt[d[i]] == 0)
                break;
            arc[i] = loc;
            d[i] = least + 1;
            cnt[d[i]]++;
            if(i != s)
            {
                i = pre[i];
                now = flow[i];
            }
        }
    }
    return sum;
}
int main()
{
    scanf("%d %d %d",&N,&F,&D);
    init();
    for(int i = 1;i <= F;i++)
        add(0,i,1);
    for(int i = 1;i <= D;i++)
        add(N + N + F + i,n,1);
    for(int i = 1;i <= N;i++)
        add(i + F,i + F + N,1);
    for(int i = 1;i <= N;i++)
    {
        int f,d;
        scanf("%d %d",&f,&d);
        for(int j = 0;j < f;j++)
        {
            int num;
            scanf("%d",&num);
            add(num,i + F,1);
        }
        for(int j = 0;j < d;j++)
        {
            int num;
            scanf("%d",&num);
            add(i + F + N,N + N + F + num,1);
        }
    }
    printf("%d\n",mflow());
}
