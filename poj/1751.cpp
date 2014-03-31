#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 760
struct point
{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
    point operator -(const point &p)
    {
        return point(x - p.x,y - p.y);
    }
    int norm2()
    {
        return x * x + y * y;
    }
}pt[maxn];
int n;
const int inf = ~0u >> 1;
int d[maxn][maxn];
int label[maxn];
bool vis[maxn];
int pre[maxn];
void prim()
{
    fill(label,label + n + 1,inf);
    label[1] = 0;
    for(int i = 1;i <= n;i++)
    {
        int mark = 1,MMM = inf;
        for(int j = 1;j <= n;j++)
            if(!vis[j] && MMM > label[j])
            {
                mark = j;
                MMM = label[j];
            }
        vis[mark] = true;
        for(int j = 1;j <= n;j++)
        {
            if(!vis[j] && d[mark][j] < label[j])
            {
                label[j] = d[mark][j];
                pre[j] = mark;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        pt[i] = point(x,y);
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            d[i][j] = (pt[i] - pt[j]).norm2();
    int m;
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        int p,q;
        scanf("%d %d",&p,&q);
        d[p][q] = d[q][p] = 0;
    }
    memset(vis,0,sizeof(vis));
    prim();
    for(int i = 1;i <= n;i++)
        if(d[i][pre[i]] != 0)
            printf("%d %d\n",i,pre[i]);
}
