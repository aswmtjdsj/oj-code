/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
/*
 * Priority First Search
 * the fucking priority_queue ....i can't use it well
 * priority: length ,then cost
 * we can prove:when arriving at [n] point,the length is the optimal(greedy)
 * (every time we come from the optimal point)
 * insert the point into queue~
 * */
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define maxn 100 + 5
#define maxm 10000 + 5
using namespace std;
struct edge
{
    int p,next,len,cost;
    edge(){}
    edge(int a,int b,int c,int d):p(a),next(b),len(c),cost(d){}
}v[maxn],e[maxm];
struct point
{
    int id,len,cost;
    point(){}
    point(int a,int b,int c):id(a),len(b),cost(c){}
}p[maxn];
bool operator > (const point &p,const point &q)
{
    return p.len < q.len || (p.len == q.len && p.cost < q.cost);
}
bool operator < (const point &p,const point &q)
{
    return !(p > q);
}
int K,n,r,tot;
bool in[maxn];
void init()
{
    tot = 0;
    for(int i = 1;i <= n;i++)
        v[i].next = -1;
}
void add(int p,int q,int l,int c)
{
    e[tot] = edge(q,v[p].next,l,c);
    v[p].next = tot++;
}
priority_queue<point> Q;
int bfs()
{
    memset(in,false,sizeof(in));
    point s(1,0,0);
    p[1] = s;
    in[1] = true;
    Q.push(s);
    while(!Q.empty())
    {
        point now = Q.top();
        if(now.id == n)
            return now.len;
        Q.pop();
        int temp = now.id;
        for(int k = v[temp].next;~k;k = e[k].next)
        {
            point go(e[k].p,now.len + e[k].len,now.cost + e[k].cost);
            if(go.cost <= K)
                Q.push(go);
        }
    }
    return -1;
}
int main()
{
    scanf("%d%d%d",&K,&n,&r);
    init();
    for(int i = 0;i < r;i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        add(a,b,c,d);
    }
    printf("%d\n",bfs());
}
