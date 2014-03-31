#include <iostream>
#include <cstdio>
using namespace std;
#include <cstring>
#define maxn 150
bool map[maxn][maxn],vis[maxn];
int mac[maxn];
int n,m;
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
void solve()
{
    memset(map,0,sizeof(map));
    memset(mac,0,sizeof(mac));
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        memset(vis,false,sizeof(vis));
        if(find(i))
            ans++;
    }
    //  cout << ans << endl;
    printf("%d\n",n - ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
        solve();
}
