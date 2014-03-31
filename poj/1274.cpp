#include <iostream>
#include <cstring>
#include <cstdio>
#define N 200
#define M 200
using namespace std;
bool map[N + 2][M + 2];
int con[M + 2];
bool vis[M + 2];
int ans,n1,n2;
bool find(int x)
{
    for(int i = 1;i <= n2;i++)
    {
        if(map[x][i] && !vis[i])
        {
            vis[i] = true;
            if(con[i] == 0 || find(con[i]))
            {
                //0的情况是新路
                //find=1的情况是0-1-0的增广路（取反为1-0-1的增广路径）
                con[i] = x;
                return true;
            }
        }
    }
    return false;
}
void init()
{
    memset(map,false,sizeof(map));
    memset(con,0,sizeof(con));
    ans = 0;
}
int main()
{
    while(scanf("%d %d",&n1,&n2) == 2)
    {
        int t,a;
        init();
        for(int i = 1;i <= n1;i++)
        {
            scanf("%d",&t);
            for(int j = 0;j < t;j++)
            {
                scanf("%d",&a);
                map[i][a] = true;
            }
        }
        for(int i = 1;i <= n1;i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i))
                ans++;
        }
        printf("%d\n",ans);
    }
}
