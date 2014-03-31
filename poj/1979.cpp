#include <iostream>
#include <cstdio>
using namespace std;
#include <queue>
#include <cstring>
struct point
{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
}s;
int ans,w,h;
bool vis[25][25];
char mat[25][25];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool check(point n)
{
    return (1 <= n.x && n.x <= h) && (1 <= n.y && n.y <= w) && (mat[n.x][n.y] != '#') && !vis[n.x][n.y];
}
void bfs()
{
    memset(vis,0,sizeof(vis));
    queue <point> Q;
    Q.push(s);
    ans++;
    vis[s.x][s.y] = true;
    while(!Q.empty())
    {
        point now = Q.front();
        Q.pop();
        for(int i = 0;i < 4;i++)
        {
            int x = now.x + dx[i],y = now.y + dy[i];
            if(check(point(x,y)))
            {
                point temp = point(x,y);
                vis[x][y] = true;
                ans++;
                Q.push(temp);
            }
        }
    }
}
int main()
{
    while(scanf("%d %d",&w,&h) == 2 && (w || h))
    {
        for(int i = 1;i <= h;i++)
            for(int j = 1;j <= w;j++)
            {
                char opt;
                scanf(" %c",&opt);
                mat[i][j] = opt;
                if(opt == '@')
                    s = point(i,j);
            }
        ans = 0;
        bfs();
        printf("%d\n",ans);
    }
}
