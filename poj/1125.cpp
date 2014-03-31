#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 105
#define maxm (maxn * maxn)
using namespace std;
const int inf = 100000;
struct edge
{
    int p,next,w;
    edge(){}
    edge(int a,int b,int c):p(a),next(b),w(c){}
}v[maxn],e[maxm];
int n,tot,ans;
int d[maxn];
bool vis[maxn];
void init()
{
    tot = 0;
    for(int i = 1;i <= n;i++)
        v[i].next = -1;
}
void add(int p,int q,int w)
{
    e[tot] = edge(q,v[p].next,w);
    v[p].next = tot++;
}
int dij(int s)
{
    for(int i = 1;i <= n;i++)
        d[i] = inf;
    memset(vis,false,sizeof(vis));
    d[s] = 0;
    for(int i = 0;i < n;i++)
    {
        int mm = inf;
        int mark = 1;
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && d[j] < mm)
            {
                mm = d[j];
                mark = j;
            }
        }
        vis[mark] = true;
        for(int k = v[mark].next;~k;k = e[k].next)
        {
            if(!vis[e[k].p] && d[e[k].p] > d[mark] + e[k].w)
                d[e[k].p] = d[mark] + e[k].w;
        }
    }
    int temp = 0;
    for(int i = 1;i <= n;i++)
        if(temp < d[i])
            temp = d[i];
    return temp;
}
int main()
{
    while(scanf("%d",&n) == 1 && n)
    {
        init();
        for(int i = 1;i <= n;i++)
        {
            int opt;
            scanf("%d",&opt);
            for(int j = 1;j <= opt;j++)
            {
                int p,w;
                scanf("%d %d",&p,&w);
                add(i,p,w);
            }
        }
        int ans = inf,mark = 0;
        for(int i = 1;i <= n;i++)
        {
            int temp = dij(i);
            if(ans > temp)
            {
                ans = temp;
                mark = i;
            }
        }
        if(ans == inf)
            printf("disjoint\n");
        else
            printf("%d %d\n",mark,ans);
    }
}
