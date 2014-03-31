/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
/*
 * Why DFS TLE??
 * floyd 
 * if d[i][j] unconnected or d[i][j] < d[i][k] * d[k][j] then update
 * .....enumerate the n d[i][i]...
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#define maxn 35
using namespace std;
int n,m;
const double inf = 1e10;
const double eps = 1e-6;
double dis[35][35];
char str[35][1005];
int comp(double a)
{
    if(fabs(a) < eps)
        return 0;
    else if(a > eps)
        return 1;
    else
        return -1;
}
bool vis[maxn];
int find(char *s)
{
    for(int i = 1;i <= n;i++)
    {
        if(strcmp(s,str[i]) == 0)
            return i;
    }
}
int main()
{
    int t = 1;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                if(i != j)
                    dis[i][j] = inf;
                else
                    dis[i][j] = 1.0;
            }
        for(int i = 1;i <= n;i++)
            scanf("%s",str[i]);
        scanf("%d",&m);
        for(int i = 0;i < m;i++)
        {
            char o[1005];
            scanf("%s",o);
            int p = find(o);
            double w;
            scanf("%lf",&w);
            scanf("%s",o);
            int q = find(o);
            if(comp(dis[p][q] - w) < 0 || comp(dis[p][q] - inf) == 0)
                dis[p][q] = w;      
        }
        bool mark = false;
        /*for(int i = 1;i <= n;i++)
         *          for(int j = 1;j <= n;j++)
         *                      {
         *                                      printf("%.2lf ",dis[i][j]);
         *                                                      if(j == 30)puts("");
         *                                                                  }*/
        for(int k = 1;k <= n;k++)
        {
            for(int i = 1;i <= n;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    if(comp(dis[i][k] - inf) != 0 && comp(dis[k][j] - inf) != 0)
                    {
                        if(comp(dis[i][j] - inf) == 0 || comp(dis[i][j] - dis[i][k] * dis[k][j]) < 0)
                            dis[i][j] = dis[i][k] * dis[k][j];
                    }
                }
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(comp(dis[i][i] - 1.0) > 0)
                mark = true;
        }
        printf("Case %d: %s\n",t++,(mark)?"Yes":"No");
    }
}
