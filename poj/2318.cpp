/*
 * Coded by BUPT-[aswmtjdsj] @ BSW in 915
 * */
/*
 * 叉积判断点与线段关系.....由于顺序已给出，线性扫描就好
 * */
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct point
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
}p[5005];
struct coor
{
    int u,l;
    int in;
    void input()
    {
        scanf("%d%d",&u,&l);
    }
}c[5005];
inline int cha(int x0,int y0,int x1,int y1,int x2,int y2)
{
    return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
void solve(int n)
{
    int m,x1,y1,x2,y2;
    scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
    int i,j;
    c[0].u = c[0].l = x1;
    c[n + 1].u = c[n + 1].l = x2;
    c[0].in = c[n + 1].in = 0;
    for(i = 1;i <= n;i++)
    {
        scanf("%d%d",&c[i].u,&c[i].l);
        c[i].in = 0;
    }
    for(i = 0;i < m;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    for(i = 0;i < m;i++)
    {
        for(j = 0;j <= n + 1;j++)
        {
            if(cha(p[i].x,p[i].y,c[j].u,y1,c[j].l,y2) < 0)
            {
                j--;
                break;
            }
            else if(cha(p[i].x,p[i].y,c[j].u,y1,c[j].l,y2) == 0)
            {
                break;
            }
        }
        if((j != n + 2 ) && ( j != -1))
            c[j].in++;
    }
    for(i = 0;i <= n;i++)
        printf("%d: %d\n",i,c[i].in);
    printf("\n");
}
int main()
{
    //freopen("2318.in","r",stdin);
    int n;
    while(scanf("%d",&n) != EOF && n)
    {
        solve(n);
    }
}
