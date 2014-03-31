#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 450
#define maxm 40000
using namespace std;
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val;
    edge(){}
    edge(int a,int b,int c):p(a),next(b),val(c){}
}e[maxm];
int flow[maxn],pre[maxn],cnt[maxn],d[maxn],path[maxn],arc[maxn],st[maxn];
int s,t,tot;
int name[55][10];
void init()
{
    tot = 0;
    fill(st,st + t + 1,-1);
    fill(d,d + t + 1,0);
    fill(cnt,cnt + t + 1,0);
    cnt[0] = t + 1;
}
void add(int p,int q,int val)
{
    //cout << p << ' ' << q << ' ' << val << endl;
    e[tot] = edge(q,st[p],val);
    st[p] = tot++;
    e[tot] = edge(p,st[q],0);
    st[q] = tot++;
}
int mflow()
{
    int now,sum,i,k,loc,least;
    bool flag;
    copy(st,st + t + 1,arc);
    for(sum = 0,now = inf,i = s;d[s] < t + 1;)
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
void gao()
{
    int n;
    int maxw = 0;
    scanf("%d",&n);
    s = 0;
    int sum = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= 9;j++)
        {
            scanf("%d",&name[i][j]);
            if(j == 9 && maxw < name[i][j])
                maxw = name[i][j];
            if(j == 8)
                sum += name[i][j];
        }
    t = maxw * 7 + n + 1;
    init();
    for(int i = 1;i <= maxw * 7;i++)
        add(s,i,1);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= 7;j++)
        {
            if(name[i][j] == 1)
            {
                for(int k = 1;k <= name[i][9];k++)
                    add(7 * (k - 1) + j,maxw * 7 + i,1);
            }
        }
        add(maxw * 7 + i,t,name[i][8]);
    }
    int ans = mflow();
    puts(ans==sum?"Yes":"No");
}
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i = 0;i < cas;i++)
        gao();
}
