#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
#define maxn 500
#define maxm 10000
int n,m;
double limit;
struct edge
{
    int p,q;
    double l;
    edge(){}
    edge(int a,int b,double c):p(a),q(b),l(c){}
}e[maxm];
const double eps = 1e-8;
int comp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else if(x < -eps)
        return -1;
    else
        return 1;
}
bool operator < (const edge &a,const edge &b)
{
    return comp(a.l - b.l) < 0;
}
int f[maxn],r[maxn];
int find(int x)
{
    if(f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
char str[maxn][25];
int main()
{
    scanf("%lf",&limit);
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
        scanf("%s",str[i]);
    int m;
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        char ab[25],ba[25];
        double temp;
        scanf("%s %s %lf",ab,ba,&temp);
        int p,q;
        for(int j = 1;j <= n;j++)
            if(!strcmp(ab,str[j]))
            {
                p = j;
                break;
            }
        for(int j = 1;j <= n;j++)
            if(!strcmp(ba,str[j]))
            {
                q = j;
                break;
            }
        e[i] = edge(p,q,temp);
    }
    sort(e,e + m);
    for(int i = 1;i <= n;i++)
    {
        f[i] = i;
        r[i] = 1;
    }
    double ans = 0;
    for(int i = 0;i < m;i++)
    {
        int p,q;
        p = find(e[i].p),q = find(e[i].q);
        if(p != q)
        {
            ans += e[i].l;
            if(r[p] > r[q])
            {
                f[q] = p;
                r[p] += r[q];
            }
            else
            {
                f[p] = q;
                r[q] += r[p];
            }
        }
    }
    if(comp(ans - limit) > 0)
        puts("Not enough cable");
    else
        printf("Need %.1lf miles of cable\n",ans);
}
