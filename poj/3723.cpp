/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
/*
 * Maximum Spanning Tree
 * Kruskal with negative edge value...
 * Vertices (girls M) label x + M
 * */
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct edge
{
    int p,q,w;
    bool friend operator < (edge a,edge b)
    {
        return a.w < b.w;
    }
}e[50005];
int r[20000],f[20000];
int find(int x)
{
    return (f[x] == x) ? x : f[x] = find(f[x]);
}
int n,m,R;
void solve()
{
    scanf("%d%d%d",&n,&m,&R);
    for(int i = 0;i < n + m;i++)
    {
        r[i] = 1;
        f[i] = i;
    }
    for(int i = 0;i < R;i++)
    {
        scanf("%d %d %d",&e[i].p,&e[i].q,&e[i].w);
        e[i].q += n;
        e[i].w = -e[i].w;
    }
    sort(e,e + R);
    int ans = 0;
    for(int i = 0;i < R;i++)
    {
        int a = find(e[i].p),b = find(e[i].q);
        if(a != b)
        {
            ans += e[i].w;
            if(r[a] > r[b])
            {
                f[b] = a;
                r[a] += r[b];
            }
            else
            {
                f[a] = b;
                r[b] += r[a];
            }
        }
    }
    printf("%d\n",10000 * (m + n) + ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
        solve();
}
