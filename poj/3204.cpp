#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 505
#define maxm 10100
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),next(b),val(c),anti(d){}
}v[maxn],e[maxm],path[maxn],arc[maxn];
int flow[maxn],d[maxn],cnt[maxn],pre[maxn];
int n,m,tot;
int color[maxn];
struct line
{
    int p,q;
    line(){}
    line(int a,int b):p(a),q(b){}
}l[maxm];
void init()
{
    tot = 0;
    for(int i = 0;i < n;i++)
    {
        v[i].next = -1;
        d[i] = 0;
        cnt[i] = 0;
    }
    cnt[0] = n;
}
void add(int p,int q,int c)
{
    e[tot] = edge(q,v[p].next,c,tot + 1);
    v[p].next = tot++;
    e[tot] = edge(p,v[q].next,0,tot - 1);
    v[q].next = tot++;
}
int mflow(int s,int t)
{
    int total,i,k,least,loc,now;
    bool flag;
    for(int i = 0;i < n;i++)
        arc[i].next = v[i].next;
    for(i = s,total = 0,now = inf;d[i] < n;)
    {
        flow[i] = now;
        for(k = arc[i].next,flag = false;~k;k = e[k].next)
        {
            if(e[k].val && d[i] == d[e[k].p] + 1)
            {
                now = min(now,e[k].val);
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
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n,k = v[i].next;~k;k = e[k].next)
            {
                if(e[k].val && least > d[e[k].p])
                {
                    least = d[e[k].p];
                    loc = k;
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
int ans;
void dfs1(int x)
{
    color[x] = 1;
    for(int k = v[x].next;~k;k = e[k].next)
    {
        if(e[k].val && !color[e[k].p])
            dfs1(e[k].p);
    }
}
void dfs2(int x)
{
    color[x] = 2;
    for(int k = v[x].next;~k;k = e[k].next)
    {
        if(e[k ^ 1].val && !color[e[k].p])
            dfs2(e[k].p);
    }
}
int main()
{
    ans = 0;
    scanf("%d %d",&n,&m);
    init();
    for(int i = 0;i < m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        l[i] = line(a,b);
        add(a,b,c);
    }
    mflow(0,n - 1);
    memset(color,0,sizeof(color));
    dfs1(0);
    dfs2(n - 1);
    for(int i = 0;i < m;i++)
    {
        //cout << color[l[i].p] << color[l[i].q] << endl;
        if(color[l[i].p] == 1 && color[l[i].q] == 2)
            ans++;
    }   
    printf("%d\n",ans);
    //cout << mflow(0,n - 1) << endl;
}
