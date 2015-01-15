#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 105
#define maxm 10005
int n,cnt;
struct edge
{
    int p,next;
    edge(){}
    edge(int a,int b):p(a),next(b){}
}e[maxm];
int st[maxn];
int tot;
void init()
{
    fill(st,st + n + 1,-1);
    tot = 0;
}
void add(int p,int q)
{
    e[tot] = edge(q,st[p]);
    st[p] = tot++;
}
int l[maxn];
bool vis[maxn];
void dfs(int x)
{
    vis[x] = true;
    for(int k = st[x];~k;k = e[k].next)
        if(!vis[e[k].p])
            dfs(e[k].p);
    l[cnt++] = x;
}
int main()
{
    scanf("%d",&n);
    init();
    for(int i = 1;i <= n;i++)
    {
        int opt;
        while(scanf("%d",&opt) == 1 && opt)
            add(opt,i);
    }
    cnt = 1;
    fill(vis,vis + n + 1,0);
    for(int i = 1;i <= n;i++)
        if(!vis[i])
            dfs(i);
    for(int i = 1;i <= n;i++)
        printf("%d%c",l[i],i == n?'\n':' ');
}