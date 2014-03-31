#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define maxn 10005
int p[maxn];
int n;
int dp[maxn][4];
int a[10];
bool vis[maxn];
int has[maxn];
void gao()
{
    memset(vis,0,sizeof(vis));
    while(1)
    {
        bool mark = false;
        for(int i = n - 1;i > 0;i--)
        {

            if(has[i] != 0 || vis[i])
                continue;
            mark = true;
            for(int j = 0;j < 6;j++)
            {
                if(j < 3)
                    a[j] = dp[p[i]][j];
                else
                    a[j] = dp[i][j - 3];
            }
            sort(a,a + 6);
            dp[p[i]][0] = a[5];
            dp[p[i]][1] = a[4];
            dp[p[i]][2] = a[3];
            has[p[i]]--;
            vis[i] = true;
        }
        if(!mark)
            break;
    }
}
int main()
{
    while(scanf("%d",&n) == 1)
    {
        memset(has,0,sizeof(has));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < 3;j++)
                dp[i][j] = -1;
        scanf("%d",&dp[0][0]);
        for(int i = 1;i < n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            dp[i][0] = b;
            p[i] = a;
            has[a] ++;
        }
        int q;
        gao();
        scanf("%d",&q);
        for(int i = 0;i < q;i++)
        {
            int opt;
            scanf("%d",&opt);
            bool mark = true;
            for(int j = 0;j < 3;j++)
            {
                if(dp[opt][j] == -1)
                {
                    mark = false;
                    break;
                }
            }
            if(!mark)
                puts("-1");
            else
            {
                for(int j = 0;j < 3;j++)
                {
                    printf("%d",dp[opt][j]);
                    printf("%c",(j == 2)?'\n':' ');
                }
            }
        }
    }
}
