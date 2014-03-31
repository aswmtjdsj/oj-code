/*
 * Coded by BUPT-[aswmtjdsj] @ BSW in 915
 * */
/*
 * 方法类似 2318
 * 因为乱序输入隔板坐标，只需排序即可，关键照样是叉积判断坐标位置
 * 度数统计(计数)输出即可
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
int rec[5005];
inline int cha(int x0,int y0,int x1,int y1,int x2,int y2)
{
    return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}
void sort(int p,int t)
{
    if(p < t)
    {
        int i,j,q = (p + t) / 2;
        swap(c[q],c[t]);
        for(i = p - 1,j = p;j < t;j++)
        {
            if(c[j].u <= c[t].u)
            {
                i++;
                swap(c[j],c[i]);
            }
        }
        swap(c[i + 1],c[t]);
        sort(p,i);
        sort(i + 2,t);
    }
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
        rec[i] = 0;
    }
    sort(1,n);
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
        rec[c[i].in]++;
    printf("Box\n");
    for(i = 1;i <= n;i++)
    {
        if(rec[i] != 0)
        {
            printf("%d: %d\n",i,rec[i]);
        }
    }
}
int main()
{
    int n;
    while(scanf("%d",&n) != EOF && n)
    {
        solve(n);
    }
}
