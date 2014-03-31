#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char str[2005][10];
struct EDGE
{
    int u,v;
    int value;
    bool friend operator <(const EDGE &a,const EDGE &b)
    {
        return a.value < b.value;
    }
} edge[2005 * 2005];
int pi[2005],rk[2005];
int f(int x)
{
    if(x == pi[x])
        return x;
    return x = f(pi[x]);
}
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 0;i < n;i++)
        {
            pi[i] = i;
            rk[i] = 1;
        }
        int tot = 0,total = 0,m = 0;
        for(int i = 0;i < n;i++)
            scanf("%s",str[i]);
        for(int i = 0;i < n;i++)
            for(int j = i + 1;j < n;j++)
            {
                int t = 0;
                for(int k = 0;k < 7;k++)
                {
                    if(str[i][k] != str[j][k])
                        t++;
                }
                edge[m].u = i;
                edge[m].v = j;
                edge[m++].value = t;
            }
        sort(edge,edge + m);
        for(int i = 0;i < m;i++)
        {
            int a = f(edge[i].v),b = f(edge[i].u);
            if(a != b)
            {
                if(rk[a] < rk[b])
                {
                    pi[a] = b;
                    rk[b] += rk[a];
                }
                else
                {
                    pi[b] = a;
                    rk[a] += rk[b];
                }
                tot += edge[i].value;
                total ++;
                if(total == n - 1)
                    break;
            }
        }
        printf("The highest possible quality is 1/%d.\n",tot);
    }
}
