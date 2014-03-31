/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int INF = 200000000;
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define parent(x) ((x) >> 1)
#define maxv 500
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
#define PQ priority_queue
struct edge
{
    int u,v,w;
    edge(){}
    edge(int a,int b,int c):u(a),v(b),w(c){}
    bool friend operator < (const edge &a,const edge &b)
    {
        return a.w < b.w;
    }
} e[maxe + 5];
int rk[maxv + 5],vt[maxv + 5];
int find(int x)
{
    if(vt[x] == x)
        return x;
    return vt[x] = find(vt[x]);
}
int main()
{
    int n,T;
    while(scanf("%d",&T) == 1)
    {
        for(int xx = 0;xx < T;xx++)
        {
            scanf("%d",&n);
            int t = 0;
            for(int i = 1;i <= n;i++)
                for(int j = 1;j <= n;j++)
                {
                    int a;
                    scanf("%d",&a);
                    if(i > j)
                        e[t++] = edge(i,j,a);
                }
            for(int i = 1;i <= n;i++)
            {
                rk[i] = 1;
                vt[i] = i;
            }
            sort(e,e + t);
            int tot = 0,total = 0;
            for(int i = 0;i < t;i++)
            {
                int u = find(e[i].u),v = find(e[i].v);
                if(u != v)
                {
                    if(total < e[i].w)
                        total = e[i].w;
                    if(rk[u] < rk[v])
                    {
                        vt[u] = v;
                        rk[v] += rk[u];
                    }
                    else
                    {
                        vt[v] = u;
                        rk[u] += rk[v];
                    }
                    tot++;
                }
                if(tot == n - 1)
                    break;
            }
            printf("%d\n",total);
        }
    }
}
