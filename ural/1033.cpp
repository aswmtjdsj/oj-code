#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char map[35][35];
bool vis[35][35];
int n;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool check(int x,int y)
{
    return 0 <= x && x < n && 0 <= y && y < n && map[x][y] != '#';
}
void dfs(int x,int y)
{
    vis[x][y] = true;
    for(int i = 0;i < 4;i++)
    {
        int nx = x + dx[i],ny = y + dy[i];
        if(check(nx,ny) && !vis[nx][ny])
            dfs(nx,ny);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            scanf(" %c",&map[i][j]);
    memset(vis,0,sizeof(vis));
    dfs(0,0);
    dfs(n-1,n-1);
    int ans = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
        {
            if(vis[i][j])
            {
                for(int k = 0;k < 4;k++)
                {
                    int x = i + dx[k],y = j + dy[k];
                    if(!check(x,y))
                        ans++;
                }
            }
        }
    ans -= 4;
    printf("%d\n",ans * 9);
}