#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 250
#define maxe 30000
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),next(b),val(c),anti(d){}
}v[maxn],e[maxe],path[maxn],arc[maxn];
int n,N,m,tot,flow[maxn],pre[maxn],cnt[maxn],d[maxn];
void init()
{
    tot = 0;
    memset(cnt,0,sizeof(cnt));
    memset(d,0,sizeof(cnt));
    for(int i = 0;i <= n;i++)v[i].next = -1;
    cnt[0] = n + 1;
}
void add(int p,int q,int val)
{
    e[tot] = edge(q,v[p].next,val,tot + 1);
    v[p].next = tot++;
    e[tot] = edge(p,v[q].next,0,tot - 1);
    v[q].next = tot++;
}
int mflow(int s,int t)
{
    int i,k,least,loc,now,total;
    bool flag;
    for(int i = 0;i <= n;i++)arc[i].next = v[i].next;
    for(total = 0,i = s,now = inf;d[s] < n + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(e[k].val && d[i] == d[e[k].p] + 1)
            {
                now = min(e[k].val,now);
                path[e[k].p].next = k;
                arc[i].next = k;
                pre[e[k].p] = i;
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
                if(e[k].val && d[e[k].p] < least)
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
void solve()
{
    scanf("%d %d",&N,&m);
    n = 2 * N + 1;
    init();
    for(int i = 1;i <= N;i++)
    {
        add(0,i,1);
        add(i + N,n,1);
    }
    for(int i = 0;i < m;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        add(p,q + N,1);
    }
    int ans = mflow(0,n);
    //cout << ans << endl;
    printf("%d\n",N - ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)solve();
}
