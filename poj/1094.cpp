#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 30
bool mt[maxn][maxn];
int n,m,tot;
int c[maxn];
bool vis[maxn];
void dfs(int x)
{
    vis[x] = true;
    for(int k = 0;k < n;k++)
        if(!vis[k] && mt[x][k])
            dfs(k);
    c[tot++] = x;
}
int main()
{
    while(scanf("%d %d",&n,&m) == 2 && ( n || m))
    {
        memset(mt,0,sizeof(mt));
        for(int i = 0;i < n;i++)
            mt[i][i] = true;
        int calc = 0;
        bool flag = false;
        bool fuck = false;
        tot = 0;
        for(int k = 0;k < m;k++)
        {
            char a,b;
            scanf(" %c<%c",&a,&b);
            a -= 'A';
            b -= 'A';
            if(!flag && !fuck)
                calc++;
            if(mt[b][a] && !fuck)
                fuck = true;
            if(!flag && !fuck)
            {
                for(int i = 0;i < n;i++)
                    for(int j = 0;j < n;j++)
                        if(mt[i][a] && mt[b][j])
                            mt[i][j] = 1;
                int cnt = 0;
                for(int i = 0;i < n;i++)
                    for(int j = 0;j < n;j++)
                        if(mt[i][j])
                            cnt++;
                if(cnt == n * ( n + 1) / 2)
                {
                    memset(vis,0,sizeof(vis));
                    flag = true;
                    for(int i = 0;i < n;i++)
                        if(!vis[i])
                            dfs(i);
                    //toposort
                }
            }
        }
        if(flag)
        {
            printf("Sorted sequence determined after %d relations: ",calc);
            for(int i = n-1;i >=0;i--)
                printf("%c",c[i] + 'A');
            puts(".");
        }
        else if(fuck)
            printf("Inconsistency found after %d relations.\n",calc);
        else
            puts("Sorted sequence cannot be determined.");
    }
}
