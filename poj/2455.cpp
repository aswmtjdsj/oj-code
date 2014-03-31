#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 205
#define maxm 160100
#define maxe 40005
struct temp
{
    int p,q,val;
    temp(){}
    temp(int a,int b,int c):p(a),q(b),val(c){}
}tmp[maxe];
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val;
    edge(){}
    edge(int a,int b,int c):p(a),next(b),val(c){}
}e[maxm];
int flow[maxn],arc[maxn],pre[maxn],d[maxn],cnt[maxn],st[maxn],path[maxn];
int tot,n,s,t,p,T;
void init()
{
    tot = 0;
    s = 0;
    t = n + 1;
    fill(st,st + t + 1,-1);
    fill(d,d + t + 1,0);
    fill(cnt ,cnt + t + 1,0);
    cnt[0] = t + 1;
}
void add(int p,int q,int val)
{
    e[tot] = edge(q,st[p],val);
    st[p] = tot++;
    e[tot] = edge(p,st[q],0);
    st[q] = tot++;
}
int mflow()
{
    int sum,now,i,k,loc,least;
    bool flag;
    copy(st,st + t + 1,arc);
    for(sum = 0,i = s,now = inf;d[s] < t + 1;)
    {
        flow[i] = now;
        for(flag = false,k = arc[i];~k;k = e[k].next)
        {
            if(e[k].val && d[i] == d[e[k].p] + 1)
            {
                now = min(e[k].val,now);
                pre[e[k].p] = i;
                path[e[k].p] = k;
                arc[i] = k;
                i = e[k].p;
                if(i == t)
                {
                    for(sum += now;i != s;i = pre[i])
                    {
                        e[path[i]].val -= now;
                        e[path[i] ^ 1].val += now;
                    }
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = t + 1,k = st[i];~k;k = e[k].next)
            {
                if(e[k].val && d[e[k].p] < least)
                {
                    least = d[e[k].p];
                    loc = k;
                }
            }
            cnt[d[i]]--;
            if(!cnt[d[i]])
                break;
            d[i] = least + 1;
            cnt[d[i]]++;
            arc[i] = loc;
            if(i != s)
            {
                i = pre[i];
                now = flow[i];
            }
        }
    }
    return sum;
}
int main()
{
    scanf("%d %d %d",&n,&p,&T);
    int mark = 0;   
    for(int i = 0;i < p;i++)
    {
        scanf("%d %d %d",&tmp[i].p,&tmp[i].q,&tmp[i].val);
        if(mark < tmp[i].val)
            mark = tmp[i].val;
    }
    int lo = 0,hi = mark,mid;
    while(lo < hi)
    {
        mid = (lo + hi) >> 1;
        init();
        add(s,1,T);
        add(n,t,inf);
        for(int i = 0;i < p;i++)
            if(tmp[i].val <= mid)
            {
                add(tmp[i].p,tmp[i].q,1);
                add(tmp[i].q,tmp[i].p,1);
            }
        int ans = mflow();
        if(ans == T)
            hi = mid;
        else
            lo = mid + 1;
    }
    printf("%d\n",(lo + hi) >> 1);
}
