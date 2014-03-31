#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 10005
#define maxm 50005
using namespace std;
struct edge
{
    int p,next;
    edge(int _p,int _n):p(_p),next(_n){}
    edge(){}
}ef[maxm],et[maxm],last[maxm];
int from[maxn],to[maxn],final[maxn];
int pt1,pt2,pt3,n,m;
int color[maxn],cnt;
bool vf[maxn],vt[maxn],vl[maxn],ext[maxn];
int ord[maxn],stat;
int in[maxn],out[maxn],cont[maxn];
void init()
{
    cnt = pt1 = pt2 = pt3 = stat = 0;
    fill(from,from + n + 1,-1);
    fill(to,to + n + 1,-1);
    fill(final,final + n + 1,-1);
    memset(vf,0,sizeof(vf));
    memset(vt,0,sizeof(vt));
    memset(vl,0,sizeof(vl));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(cont,0,sizeof(cont));
}
void add0(int a,int b)
{
    ef[pt1] = edge(b,from[a]);
    from[a] = pt1++;
}
void add1(int a,int b)
{
    et[pt2] = edge(b,to[a]);
    to[a] = pt2++;
}
void add2(int a,int b)
{
    last[pt3] = edge(b,final[a]);
    final[a] = pt3++;
}
void dfs1(int p)
{
    vf[p] = true;
    for(int k = from[p];~k;k = ef[k].next)
        if(!vf[ef[k].p])
            dfs1(ef[k].p);
    ord[stat++] = p;
}
void dfs2(int p)
{
    color[p] = cnt;
    vt[p] = true;
    for(int k = to[p];~k;k = et[k].next)
        if(!vt[et[k].p])
            dfs2(et[k].p);
}
void dfs3(int old,int now)
{
    if(old != now)
    {
        out[old]++;
        in[now]++;
    }
    vl[now] = true;
    for(int k = final[now];~k;k = last[k].next)
        if(!vl[last[k].p])
            dfs3(now,last[k].p);
}
int main()
{
    while(scanf("%d %d",&n,&m) == 2)
    {
        init();
        for(int i = 0;i < m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            add0(a,b);
            add1(b,a);
        }
        for(int i = 1;i <= n;i++)
            if(!vf[i])
                dfs1(i);
        for(int i = stat - 1;i >= 0;i--)
            if(!vt[ord[i]])
            {
                cnt++;
                dfs2(ord[i]);
            }
        for(int i = 1;i <= n;i++)
        {
            cont[color[i]]++;
            memset(ext,0,sizeof(ext));
            for(int k = from[i];~k;k = ef[k].next)
            {
                if(!ext[color[ef[k].p]] && color[i] != color[ef[k].p])
                {
                    add2(color[i],color[ef[k].p]);
                    //cout << color[i] << ' ' << color[ef[k].p] << endl;
                    ext[color[ef[k].p]] = true;
                    in[color[ef[k].p]]++;
                    out[color[i]]++;
                }
            }
        }
        int ans = 0;
        int flag = 0;
        for(int i = 1;i <= cnt;i++)
        {
            if(out[i] == 0)
            {
                flag ++;
                ans += cont[i];
            }
        }
        printf("%d\n",(flag == 1)?ans:0);
    }
}
