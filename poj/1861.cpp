#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define maxn 1005
#define maxm (15000 + 5)
using namespace std;
int n,m,t;
struct edge
{
    int p,q,w;
    edge(){}
    edge(int a,int b,int c):p(a),q(b),w(c){}
}e[maxm],ans[maxn];
bool operator < (edge a,edge b)
{
    return a.w < b.w;
}
int f[maxn],r[maxn];
void init()
{
    for(int i = 1;i <= n;i++)
    {
        f[i] = i;
        r[i] = 1;
    }
}
int find(int x)
{
    return (f[x] == x)? x:f[x] = find(f[x]);
}
void kruskal()
{
    for(int i = 0;i < m;i++)
    {
        int u = find(e[i].p),v = find(e[i].q);
        if(u != v)
        {
            ans[t++] = edge(e[i].p,e[i].q,e[i].w);
            if(r[u] > r[v])
            {
                f[v] = u;
                r[u] += r[v];
            }
            else
            {
                f[u] = v;
                r[v] += r[u];
            }
        }
        if(t == n - 1)
            break;
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        e[i] = edge(a,b,c);
    }
    sort(e,e + m);
    t = 0;
    init();
    kruskal();
    printf("%d\n",ans[t - 1].w);
    printf("%d\n",t);
    for(int i = 0;i < t;i++)
        printf("%d %d\n",ans[i].p,ans[i].q);
}
