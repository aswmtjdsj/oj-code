/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
/*
 * tree's diameter...
 * BFS twice
 * first to find one of the end point (from arbitrary point)
 * then find the other end point(the farthest point from the initial end point)
 * */
#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 40002
#include <cstring>
struct edge
{
    int p,next,w;
    edge(){}
    edge(int a,int b,int c):p(a),next(b),w(c){}
}v[maxn],e[maxn * 2];
int n,m,tot;
int d[maxn];
void init()
{
    tot = 0;
    for(int i = 1;i <= n;i++)
        v[i].next = -1;
}
void add(int p,int q,int w)
{
    e[tot] = edge(q,v[p].next,w);
    v[p].next = tot ++;
}
void adde(int p,int q,int w)
{
    add(p,q,w);
    add(q,p,w);
}
const int inf = 1 << 30;
int bfs(int x)
{
    for(int i = 1;i <= n;i++)
        d[i] = inf;
    d[x] = 0;
    queue <int> Q;
    Q.push(x);
    //cout << d[x] << endl;
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for(int k = v[now].next;~k;k = e[k].next)
        {
            if(d[e[k].p] > d[now] + e[k].w)
            {
                d[e[k].p] = d[now] + e[k].w;
                Q.push(e[k].p);
            }
        }
    }
    int mark = 0,MM = 0;
    for(int i = 1;i <= n;i++)
    {
        //cout << i << ' ' << d[i] << endl;
        if(MM < d[i])
        {
            MM = d[i];
            mark = i;
            //cout << MM << endl;
        }
    }
    return mark;
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        init();
        for(int i = 0;i < m;i++)
        {
            int a,b,c;
            char dd;
            scanf("%d %d %d %c",&a,&b,&c,&dd);
            adde(a,b,c);
        }
        int mark = bfs(1);
        //cout << mark << endl;
        int ans = bfs(mark);
        //cout << ans << endl;
        printf("%d\n",d[ans]);
    }
}
