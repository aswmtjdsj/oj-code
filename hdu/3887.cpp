#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include <stack>
#define maxn 100005
int p,tr[maxn * 2],seq[maxn * 2],l[maxn],r[maxn],ans[maxn],tot,n,cnt;
stack <int> S;
bool vis[maxn];
#define bit(x) ((x) & -(x))
void mod(int x,int c)
{
    for(;x < cnt;x += bit(x))
        tr[x] += c;
}
int query(int x)
{
    int s = 0;
    for(;x > 0;x -= bit(x))
        s += tr[x];
    return s;
}
struct edge
{
    int p,next;
    edge(){}
    edge(int a,int b):p(a),next(b){}
}v[maxn],e[maxn * 2];
void init()
{
    tot = 0;
    cnt = 1;
    for(int i = 1;i <= n;i++)
        v[i].next = -1;
    memset(tr,0,sizeof(tr));
    memset(vis,0,sizeof(vis));
    while(!S.empty())
        S.pop();
}
void add(int p,int q)
{
    e[tot] = edge(q,v[p].next);
    v[p].next = tot++;
}
void dfs()
{
    S.push(p);
    while(!S.empty())
    {
        int now = S.top();
        if(!vis[now])
        {
            seq[cnt] = now;
            l[now] = cnt++;
            vis[now] = true;
        }
        bool flag = false;
        for(int k = v[now].next;~k;k = e[k].next)
        {
            if(!vis[e[k].p])
            {
                v[now].next = e[k].next;
                S.push(e[k].p);
                flag = true;
                break;
            }
        }
        if(flag)continue;
        if(vis[now])
        {
            S.pop();
            seq[cnt] = now;
            r[now] = cnt++;
        }
    }
}
void gao()
{
    for(int i = 1;i <= n;i++)
    {
        ans[i] = query(r[i] - 1) - query(l[i]);
        mod(l[i],1);
    }
}
int main()
{
    while(scanf("%d %d",&n,&p) == 2 && (n || p))
    {
        init();
        for(int i = 0;i < n - 1;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b);
            add(b,a);
        }
        dfs();
        gao();
        for(int i = 1;i <= n;i++)
        {
            printf("%d",ans[i]);
            putchar((i == n)?'\n':' ');
        }
    }
}
