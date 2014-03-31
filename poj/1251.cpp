#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int p[30],r[30];
struct edge
{
    int u,v,val;
    edge(){}
    edge(int _u,int _v,int _edge):u(_u),v(_v),val(_edge){}
    bool friend operator < (edge a,edge b)
    {
        return a.val < b.val;
    }
}e[80];
int find(int x)
{
    if(x == p[x])
        return x;
    else
        return p[x] = find(p[x]);
}
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        int tot = 0;
        for(int i = 0;i < n - 1;i++)
        {
            char o1;
            int t;
            scanf(" %c %d",&o1,&t);
            for(int j = 0;j < t;j++)
            {
                char o2;
                int val;
                scanf(" %c %d",&o2,&val);
                e[tot++] = edge(o1 - 'A',o2 - 'A',val);
                e[tot++] = edge(o2 - 'A',o1 - 'A',val);
            }
        }
        sort(e,e + tot);
        for(int i = 0;i < n;i++)
        {
            p[i] = i;
            r[i] = 1;
        }
        int ans = 0;
        for(int i = 0;i < tot;i++)
        {
            int u = find(e[i].u),v = find(e[i].v);
            if(u == v)
                continue;
            else
            {
                ans += e[i].val;
                if(r[u] > r[v])
                {
                    p[v] = u;
                    r[u] += r[v];
                }
                else
                {
                    p[u] = v;
                    r[v] += r[u];
                }
            }
        }
        printf("%d\n",ans);
    }
}
