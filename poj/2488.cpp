#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 30
int n;
int r,c;
bool vis[maxn][maxn];
struct node
{
    int x,y;
    node(){}
    node(int a,int b):x(a),y(b){}
};
int dx[] = {-1,1,-2,2,-2,2,-1,1};
int dy[] = {-2,-2,-1,-1,1,1,2,2};
bool check(int x,int y)
{
    return 1 <= x && x <= r && 1 <= y && y <= c && !vis[x][y];
}
node sol[maxn];
bool dfs(int x,int y,int step)
{
    if(step == r * c - 1)
    {
        sol[step] = node(x,y);
        return true;
    }
    else
    {
        vis[x][y] = true;
        for(int i = 0;i < 8;i++)
        {
            int tx = x + dx[i],ty = y + dy[i];
            if(check(tx,ty) && dfs(tx,ty,step + 1))
            {
                sol[step] = node(x,y);
                return true;
            }
        }
        vis[x][y] = false;
        return false;
    }
}
void gao()
{
    scanf("%d %d",&r,&c);
    bool mark = false;
    for(int i = 1;i <= r;i++)
    {
        for(int j = 1;j <= c;j++)
        {
            for(int t1 = 1;t1 <= r;t1++)
                for(int t2 = 1;t2 <= c;t2++)
                    vis[t1][t2] = false;
            mark = dfs(i,j,0);
            if(mark)
                break;
        }
        if(mark)
            break;
    }
    if(mark)
    {
        for(int i = 0;i < r * c;i++)
            printf("%c%d",sol[i].y + 'A'-1,sol[i].x);
        puts("");
    }
    else
        puts("impossible");
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        printf("Scenario #%d:\n",i);
        gao();
        puts("");
    }
}
