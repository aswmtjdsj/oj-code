#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 105
bool map[maxn][maxn],vis[maxn];
int mac[maxn];
int n,m,k;
bool find(int x)
{
    for(int i = 1;i <= m;i++)
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
int main()
{
    while(scanf("%d",&n) == 1 && n)
    {
        memset(map,0,sizeof(map));
        memset(mac,0,sizeof(mac));
        scanf("%d %d",&m,&k);
        for(int i = 1;i <= k;i++)
        {
            int t,a,b;
            scanf("%d %d %d",&t,&a,&b);
            if(!a || !b)
                continue;
            map[a][b] = 1;
        }
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))
                ans++;
        }
        printf("%d\n",ans);
    }
}
