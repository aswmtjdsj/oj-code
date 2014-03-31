#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <fstream>
#include <cctype>
#define maxn 120
#define maxe 4000
using namespace std;
const int inf = ~0u>>1;
struct edge
{
    int p,next,val,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),next(b),val(c),anti(d){}
}v[maxn],e[maxe],arc[maxn],path[maxn];
int flow[maxn],cnt[maxn],d[maxn],pre[maxn];
int n,tot;
//n is the mark of the endpoint
//0 to n
//added to (n + 1) 's point
void init()
{
    tot = 0;
    for(int i = 0;i <= n;i++)
    {
        d[i] = 0;
        cnt[i] = 0;
        v[i].next = -1;
    }
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
    int k,least,loc,i,now,total;
    bool flag;
    for(int i = 0;i <= n;i++)
        arc[i].next = v[i].next;
    for(i = s,total = 0,now = inf;d[s] < n + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(e[k].val > 0 && d[i] == d[e[k].p]  + 1)
            {
                now = min(e[k].val,now);
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
struct line
{
    int a,b,c;
    line(){}
    line(int _a,int _b,int _c):a(_a),b(_b),c(_c){}
}l[1005];
int color[maxn];
void dfs1(int x,int c)
{
    color[x] = c;
    for(int k = v[x].next;~k;k = e[k].next)
    {
        if(!color[e[k].p] && e[k].val > 0)
        {
            //color[e[k].p] = c;
            dfs1(e[k].p,c);
        }
    }
}
void dfs2(int x,int c)
{
    color[x] = c;
    for(int k = v[x].next;~k;k = e[k].next)
    {
        if(!color[e[k].p] && e[k ^ 1].val)
        {
            //color[e[k].p] = c;
            dfs2(e[k].p,c);
        }
    }
}
int main()
{
    int N,M,L;
    while(scanf("%d %d %d",&N,&M,&L) == 3 && N)
    {
        n = N + M + 1;
        init();
        memset(color,0,sizeof(color));
        for(int i = 1;i <= N;i++)
            add(n,i,inf);
        for(int i = 1;i <= L;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            l[i] = line(a,b,c);
            add(a,b,c);
        }
        int ans = mflow(n,0);
        //cout << "ans" << ans << endl;
        //in-order arc is all even arc...
        //re-order arc is all odd arc...
        dfs1(n,1);//colored...
        dfs2(0,2);
        /*for(int i = 0;i <= n;i++)
          printf("%d %d\n",i,color[i]);
          */bool mark = false;
        for(int i = 1;i <= L;i++)
        {
            //if(color[l[i].a] && color[l[i].b] && color[l[i].a] != color[l[i].b])
            if(color[l[i].a] == 1 && color[l[i].b] == 2)
            {
                if(!mark)
                    mark = true;
                else
                    putchar(' ');
                printf("%d",i);
            }
        }
        puts("");
    }
}
