#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 1025
#define maxm 90000
#define maxb 22
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val;
    edge(){}
    edge(int _p,int _n,int _v):p(_p),next(_n),val(_v){}
}e[maxm];
int flow[maxn],pre[maxn],cnt[maxn],d[maxn],path[maxn],v[maxn],arc[maxn];
int tot,last,n,b;
void init()
{
    last = n + b + 1;
    tot = 0;
    fill(v,v + last + 1,-1);
    fill(cnt,cnt + last + 1,0);
    fill(d,d + last + 1,0);
    cnt[0] = last + 1;
}
void add(int p,int q,int val)
{
    e[tot] = edge(q,v[p],val);
    v[p] = tot++;
    e[tot] = edge(p,v[q],0);
    v[q] = tot++;
}
int mflow()
{
    int s = 0,t = last;
    int now,sum,i,k,least,loc;
    bool flag;
    for(int i = 0;i <= last;i++)
        arc[i] = v[i];
    for(sum = 0,now = inf,i = s;d[s] < last + 1;)
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
                        e[path[i]^1].val += now;
                    }
                    now = inf;
                }
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            for(least = last + 1,k = v[i];~k;k = e[k].next)
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
int cow[maxn][maxb];
int barn[maxb];
void graph(int low,int up)
{
    for(int i = 1;i <= n;i++)
    {
        add(0,i,1);
        for(int j = low;j <= up - 1;j++)
            add(i,cow[i][j] + n,1);
    }
    for(int j = 1;j <= b;j++)
        add(j + n,last,barn[j]);
}
int main()
{
    scanf("%d %d",&n,&b);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= b;j++)
            scanf("%d",&cow[i][j]);
    for(int i = 1;i <= b;i++)
        scanf("%d",&barn[i]);
    int l = 1,r = b,mid;
    int ans = b;
    while(l < r)
    {
        mid = (l + r) >> 1;
        bool flag = false;
        for(int i = 1;i + mid - 1 <= b;i++)
        {
            init();
            graph(i,i + mid);
            int temp = mflow();
            //cout << temp << " temp " << i << " i " << i + mid - 1 << " j" << endl;
            if(temp == n)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            r = mid;
            if(ans > mid)
                ans = mid;
        }
        else
            l = mid + 1;
    }
    printf("%d\n",ans);
}
