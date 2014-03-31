#include <iostream>
#include <cstdio>
using namespace std;
#include <cstring>
#define maxn 20005
#define maxm (maxn * 4 + 200005 * 4)
const int inf = ~0u>>1;
struct edge
{
    int p,next,val,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),next(b),val(c),anti(d){}
}v[maxn],e[maxm],path[maxn],arc[maxn];
int flow[maxn],pre[maxn],d[maxn],cnt[maxn];
int tot,s,t,n;
void init()
{
    tot = 0;
    for(int i = 0;i <= n;i++)
    {
        v[i].next = -1;
        d[i] = 0;
        cnt[i] = 0;
    }
    cnt[0] = n + 1;
}
void add(int a,int b,int c)
{
    e[tot] = edge(b,v[a].next,c,tot + 1);
    v[a].next = tot++;
    e[tot] = edge(a,v[b].next,0,tot - 1);
    v[b].next = tot++;
}
int maxflow(int s,int t)
{
    int total,i,k,loc,least,now;
    bool flag;
    for(int i = 0;i <= n;i++)
        arc[i].next = v[i].next;
    for(total = 0,i = s,now = inf;d[i] < n + 1;)
    {
        //cout << i << endl;
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            //cout << k << endl;
            //cout << now << endl;
            //cout << d[i] << endl;
            if(e[k].val > 0 && d[i] == d[e[k].p] + 1)
            {
                now = min(e[k].val,now);
                pre[e[k].p] = i;
                path[e[k].p].next = k;
                arc[i].next = k;
                i = e[k].p;
                if(i == t)
                {
                    for(total += now;i != s;i = pre[i])
                    {
                        e[path[i].next].val -= now;
                        e[e[path[i].next].anti].val += now;
                    }
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n,k = v[i].next;~k;k = e[k].next)
            {
                //cout << e[k].val << endl;
                if(e[k].val && least > d[e[k].p])
                {
                    loc = k;
                    least = d[e[k].p];
                    //cout << least << endl;
                }
            }
            //      cout << least << endl;
            arc[i].next = loc;
            cnt[d[i]]--;
            //  cout << d[i] << endl;
            if(cnt[d[i]] == 0)
                break;
            d[i] = least + 1;
            //  cout << d[i] << endl;
            cnt[d[i]] ++ ;
            if(i != s)
            {
                i = pre[i];
                now = flow[i];
            }
        }
    }
    return total;
}
int main()
{
    int tn,tm;
    scanf("%d %d",&tn,&tm);
    n = tn + 1;
    init();
    for(int i = 1;i <= tn;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        add(0,i,a);
        add(i,n,b);
    }
    for(int i = 0;i < tm;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
    printf("%d\n",maxflow(0,n));
}
