#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 10000
bool p[maxn];
int cnt;
int map[maxn];
#define maxm (40 * 10000)
struct edge
{
    int p,next;
    edge(){}
    edge(int a,int b):p(a),next(b){}
}e[maxm];
int tot;
int st[1500];
void init()
{
    tot = 0;
    cnt = 0;
    fill(st,st + 1500,-1);
}
void prime()
{
    p[2] = true;
    for(int i = 3;i < maxn;i += 2)
        p[i] = true;
    for(int i = 3;i < maxn;i++)
        if(p[i])
        {
            for(int j = i * 2;j < maxn;j += i)
                p[j] = false;
        }
    for(int j = 2;j < maxn;j++)
        if(p[j])
            map[j] = ++cnt;
}
void add(int p,int q)
{
    e[tot] = edge(q,st[p]);
    st[p] = tot++;
}
void graph()
{
    for(int i = 1000;i < maxn;i++)
    {
        if(p[i])
        {
            int idx = 1;
            int u = map[i];
            for(int j = 0;j < 4;j++)
            {
                int dig = (i / idx) % 10;
                for(int k = 0;k < 10;k++)
                {
                    int other = i - dig * idx + k * idx;
                    if(other > 1000 && p[other])
                        add(u,map[other]);
                }
                idx *= 10;
            }
        }
    }
}
int ST,EN;
const int inf = 100000;
int d[1500];
void bfs()
{
    queue<int> Q;
    Q.push(ST);
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for(int k = st[now];~k;k = e[k].next)
        {
            if(d[e[k].p] > d[now] + 1)
            {
                Q.push(e[k].p);
                d[e[k].p] = d[now] + 1;
            }
        }
    }
}
void gao()
{
    int l,r;
    scanf("%d %d",&l,&r);
    ST = map[l],EN = map[r];
    fill(d,d + 1500,inf);
    d[ST] = 0;
    if(d[EN] != 0)
        bfs();
    printf("%d\n",d[EN]);
}
int main()
{
    prime();
    init();
    graph();
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
        gao();
}
