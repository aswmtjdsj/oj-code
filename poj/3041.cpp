#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 505
bool map[maxn][maxn],vis[maxn];
int mac[maxn];
int n,k;
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
int main()
{
    scanf("%d%d",&n,&k);
    memset(map,0,sizeof(map));
    memset(mac,0,sizeof(mac));
    for(int i = 0;i < k;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
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
