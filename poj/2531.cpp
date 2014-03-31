#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define maxn 22
int map[maxn][maxn];
int n;
int ans;
bool color[maxn];
void dfs(int step,int temp)
{
    if(step == n)
    {
        ans = max(temp,ans);
        return ;
    }
    color[step] = 0;
    int ano = temp;
    for(int i = 0;i < step;i++)
        if(color[i] ^ color[step])
            ano += map[i][step];
    dfs(step+1,ano);
    ano = temp;
    color[step] = 1;
    for(int i = 0;i < step;i++)
        if(color[i] ^ color[step])
            ano += map[i][step];
    dfs(step+1,ano);
}
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            scanf("%d",&map[i][j]);
    ans = 0;
    dfs(0,0);
    printf("%d\n",ans);
}
