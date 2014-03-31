#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 205
#define maxm 50000
using namespace std;
const int inf = ~0u >> 1;
struct edge
{
    int p,next,val;
    edge(){}
    edge(int a,int b,int c):p(a),next(b),val(c){}
}e[maxm];
int pre[maxn],flow[maxn],cnt[maxn],d[maxn],st[maxn],arc[maxn],path[maxn];
int tot,n,N;
double R;
const double eps = 1e-6;
int comp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else if(x < -eps)
        return -1;
    else
        return 1;
}
void init()
{
    tot = 0;
    fill(st,st + n + 1,-1);
    fill(d,d + n + 1,0);
    fill(cnt,cnt + n + 1,0);
    cnt[0] = n + 1;
}
void add(int p,int q,int val)
{
    e[tot] = edge(q,st[p],val);
    st[p] = tot++;
    e[tot] = edge(p,st[q],0);
    st[q] = tot++;
}
int mflow(int s,int t)
{
    int now,sum,i,k,loc,least;
    bool flag;
    copy(st,st + n + 1,arc);
    for(sum = 0,i = s,now = inf;d[s] < n + 1;)
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
            for(least = n + 1,k = st[i];~k;k = e[k].next)
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
struct point
{
    double x,y;
    int num,val;
    point(){}
    point(double _x,double _y):x(_x),y(_y){}
    point(double _x,double _y,int _n,int _v):x(_x),y(_y),num(_n),val(_v){}
    point operator - (const point p)
    {
        return point(x - p.x,y - p.y);
    }
    double norm()
    {
        return x * x + y * y;
    }
}p[maxn];
int sol[maxn],NUM;
bool rel[105][105];
void gao()
{
    scanf("%d %lf",&N,&R);
    n = N + N + 1;
    int total = 0;
    NUM = 0;
    for(int i = 1;i <= N;i++)
    {
        double x,y;
        int num,val;
        scanf("%lf %lf %d %d",&x,&y,&num,&val);
        p[i] = point(x,y,num,val);
        total += num;
    }
    memset(rel,0,sizeof(rel));
    for(int i = 1;i <= N;i++)
        for(int j = i + 1;j <= N;j++)
            if(comp((p[i] - p[j]).norm() - R * R) <= 0)
                rel[i][j] = rel[j][i] = 1;
    for(int i = 1;i <= N;i++)
    {
        init();
        add(i + N,n,inf);
        for(int j = 1;j <= N;j++)
        {
            if(p[j].num > 0)
                add(0,j,p[j].num);
            if(i != j)
                add(j,j + N,p[j].val);
            else
                add(j,j + N,inf);
        }
        for(int j = 1;j <= N;j++)
            for(int k = 1;k <= N;k++)
                if(j != k && rel[j][k])
                    add(j + N,k,inf);
        int temp = mflow(0,n);
        //cout << "total:" << total << endl;
        //cout << "i:" << i << " flow:" << temp << endl;
        if(temp == total)
            sol[NUM++] = i;
    }
    if(NUM == 0)
        puts("-1");
    else
    {
        for(int i = 0;i < NUM;i++)
            printf("%d%c",sol[i] - 1,(i == NUM - 1?'\n':' '));
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
        gao();
}
