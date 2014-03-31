#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 505
bool map[maxn][maxn],vis[maxn];
int mac[maxn],n;
struct point
{
    int x,y;
    point(){}
    point(int _x,int _y):x(_x),y(_y){}
};
int fab(int x)
{
    return (x > 0)?x : -x;
}
int dis(const point &a,const point &b)
{
    return fab(a.x - b.x) + fab(a.y - b.y);
}
struct node
{
    point s,t;
    int a,b;
    node(){}
    node(int x,point _s,point _t)
    {
        s = _s;
        t = _t;
        a = x;
        int len = dis(s,t);
        b = a + len;
        //printf("start:%d\n",a);
        //printf("end:%d\n",b);
    }
}st[maxn];
bool find(int x)
{
    for(int i = 1;i <= n;i++)
    {
        if(map[x][i] && !vis[i])
        {
            vis[i] = true;
            if(!mac[i] || find(mac[i]))
            {
                mac[i] = x;
                return true;
            }
        }
    }
    return false;
}
void solve()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        int a,b;
        int in[4];
        scanf(" %d:%d",&a,&b);
        int temp = a * 60 + b;
        for(int j = 0;j < 4;j++)
            scanf(" %d",&in[j]);
        st[i] = node(temp,point(in[0],in[1]),point(in[2],in[3]));
    }
    memset(map,0,sizeof(map));
    memset(mac,0,sizeof(mac));
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            if(st[j].a > st[i].b + dis(st[i].t,st[j].s))
                map[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
            ans++;
    }
    printf("%d\n",n - ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)solve();
}
