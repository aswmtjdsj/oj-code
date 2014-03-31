#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 250
#define maxm 130000
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val,anti,len;
    edge(){}
    edge(int a,int b,int c,int d,int l):p(a),next(b),val(c),anti(d),len(l){}
}v[maxn],e[maxm],path[maxn],arc[maxn];
int flow[maxn],pre[maxn],d[maxn],cnt[maxn];
int n,tot,lo,hi,mid;
const int up = 60000;
void init()
{
    tot = 0;
    for(int i = 0;i <= n;i++)
    {
        d[i] = 0;
        v[i].next = -1;
        cnt[i] = 0;
    }
    cnt[0] = n + 1;
}
void add(int a,int b,int c,int d)
{
    e[tot] = edge(b,v[a].next,c,tot + 1,d);
    v[a].next = tot++;
    e[tot] = edge(a,v[b].next,0,tot - 1,d);
    v[b].next = tot++;
}
int map[maxn][maxn];
void floyd()
{
    for(int k = 1;k <= n - 1;k++)
        for(int i = 1;i <= n - 1;i++)
            for(int j = 1;j <= n - 1;j++)
            {
                if(i == j || map[i][k] == inf || map[k][j] == inf)
                    continue;
                if(map[i][j] == inf || map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
}
int mflow(int s,int t)
{
    int total,i,k,loc,least,now;
    bool flag;
    for(i = 0;i <= n;i++)
        arc[i].next = v[i].next;
    for(total = 0,i = s,now = inf;d[i] < n + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(e[k].val && e[k].len <= mid && d[i] == d[e[k].p] + 1)
            {
                now = min(e[k].val,now);
                pre[e[k].p] = i;
                path[e[k].p].next = k;//differ it
                arc[i].next = k;//from above
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
                if(e[k].val && e[k].len <= mid && least > d[e[k].p])
                {
                    loc = k;
                    least = d[e[k].p];
                }
            }
            arc[i].next = loc;//do not forget
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
    int k,c,m;
    scanf("%d %d %d",&k,&c,&m);
    n = k + c + 1;
    for(int i = 1;i <= k + c;i++)
        for(int j = 1;j <= k + c;j++)
        {
            scanf("%d",&map[i][j]);
            if(i != j && map[i][j] == 0)
                map[i][j] = inf;
        }
    floyd();/*
               for(int i = 1;i <= n - 1;i++)
               for(int j = 1;j <= n - 1;j++)
               {
               printf("%d ",map[i][j]);
               if(j == n - 1)printf("\n");     
               }*/
    lo = 1;
    hi = up;
    while(lo < hi)
    {
        mid = (lo + hi) >> 1;
        init();//do not forget      
        for(int i = 1;i <= k;i++)
        {
            add(0,i,m,0);
            for(int j = k + 1;j <= k + c;j++)
                if(map[i][j] != inf)
                    add(i,j,1,map[i][j]);
        }
        for(int i = k + 1;i <= k + c;i++)
            add(i,n,1,0);
        int ans = mflow(0,n);
        //cout << "ans" << ans << endl;
        if(ans == c)
            hi = mid;
        else
            lo = mid + 1;
        //cout << " lo" << lo << " hi" << hi << endl;
    }
    printf("%d\n",(lo + hi) >> 1);
}
