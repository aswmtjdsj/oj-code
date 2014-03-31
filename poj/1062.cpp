#include <iostream>
#include <cstdio>
#include <queue>
#define maxn 105
#define maxe (maxn * maxn)
#define INF (1 << 30)
using namespace std;
int value[maxn],r[maxn],dis[maxn];
int m,n;
struct edge
{
    int p,next,val;
    edge(){}
    edge(int a,int b,int c):p(a),next(b),val(c){}
}v[maxn],e[maxe];
bool in[maxn];
int tot;
void add(int p,int q,int val)
{
    e[tot] = edge(q,v[p].next,val);
    v[p].next = tot++;
}
int spfa(int d)
{
    int hi = d,lo = ((d - m) > 0) ? (d - m) : 0;
    queue <int> Q;
    dis[1] = 0;
    for(int i = 1;i <= n;i++)
        in[i] = false;
    for(int i = 2;i <= n;i++)
        dis[i] = INF;
    in[1] = true;
    Q.push(1);
    while(!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        in[now] = false;
        for(int i = v[now].next;~i;i = e[i].next)
        {
            int temp = e[i].p;
            if(r[temp] <= hi && r[temp] >= lo && dis[temp] > dis[now] + e[i].val)
            {
                dis[temp] = dis[now] + e[i].val;
                if(!in[temp])
                {
                    in[temp] = true;
                    Q.push(temp);
                }
            }
        }
    }
    int ans = INF;
    for(int i = 1;i <= n;i++)
    {
        if(ans > value[i] + dis[i])
            ans = value[i] + dis[i];
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&m,&n) == 2)
    {
        for(int i = 1;i <= n;i++)
        {
            v[i].next = -1;
            tot = 0;
        }
        for(int i = 1;i <= n;i++)
        {
            int k;
            scanf("%d%d%d",&value[i],&r[i],&k);
            for(int j = 0;j < k;j++)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                add(i,a,b);
            }
        }
        int ans = INF;
        for(int tt = r[1];tt <= r[1] + m;tt++)
        {
            int temp = spfa(tt);
            printf("%d\n",temp);
            if(temp < ans)
                ans = temp;
        }
        printf("%d\n",ans);
    }
}
