#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define INF 2000000000
#define maxn 1105
#define maxm (10000 + 200) * 2 + 100 * 1000
struct edge
{
    int p,val,next,anti;
    edge(){}
    edge(int a,int b,int c,int d):p(a),val(b),next(c),anti(d){}
}v[maxn],e[maxm],path[maxn],arc[maxn],zj[maxn];
int flow[maxn],pre[maxn],d[maxn],cnt[maxn];
int n,m,tot;
void init()
{
    tot = 0;
    for(int i = 0;i <=  n + 1;i++)
    {
        v[i].next = -1;
        d[i] = 0;
        cnt[i] = 0;
    }
    cnt[0] = n + 2;
}
void add(int a,int b,int c)
{
    e[tot] = edge(b,c,v[a].next,tot + 1);
    v[a].next = tot++;
    e[tot] = edge(a,0,v[b].next,tot - 1);
    v[b].next = tot++;
}
int mflow(int s,int t)
{
    int least,loc,k,i,total,now;
    bool flag;
    for(i = s;i <= t;i++)
        arc[i].next = v[i].next;
    for(total = 0,now = INF,i = s;d[s] < n + 2;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i].next;~k;k = e[k].next)
        {
            if(e[k].val > 0 && d[i] == d[e[k].p] + 1)
            {
                // cout << i << endl;
                now = (e[k].val < now)?e[k].val : now;
                arc[i].next = k;
                pre[e[k].p] = i;
                path[e[k].p].next = k;
                i = e[k].p;
                if(i == t)
                {
                    for(total += now;i != s;i = pre[i])
                    {
                        //cout << total << endl;
                        e[path[i].next].val -= now;
                        e[e[path[i].next].anti].val += now;
                    }
                    now = INF;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = n + 1,k = v[i].next;~k;k = e[k].next)
            {
                if(e[k].val > 0 && least > d[e[k].p])
                {
                    loc = k;
                    least = d[e[k].p];
                }
            }
            // cout << i << endl;
            arc[i].next = loc;
            cnt[d[i]] --;
            if(cnt[d[i]] == 0)
                break;
            d[i] = least + 1;
            cnt[d[i]] ++;
            if(i != s)
            {
                i = pre[i];
                now = flow[i];
            }
        }
    }
    return total;
}
int pig[maxn];
int main()
{
    scanf("%d %d",&m,&n);
    for(int i = 1;i <= m;i++)
    {
        zj[i].next = -1;
        scanf("%d",&pig[i]);
    }
    init();
    int opt,tar;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&opt);
        for(int j = 0;j < opt;j++)
        {
            scanf("%d",&tar);
            if(zj[tar].next == -1)
                add(i,n + 1,pig[tar]);
            else
            {
                for(int k = zj[tar].next;~k;k = e[k].next)
                    add(i,e[k].p,INF);
            }
            e[tot].next = zj[tar].next;
            e[tot].p = i;
            zj[tar].next = tot++;
        }
        int b;
        scanf("%d",&b);
        add(0,i,b);
    }
    printf("%d\n",mflow(0,n + 1));
}
