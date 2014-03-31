/*
 *  Coded by BUPT-[aswmtjdsj] @ Penalty in 608
 *   */
/*
 *  gets to input
 *   MIND:TEMP string should be long enough(not 10 but 100 in case of overflow)
 *    enumerate to set map
 *     BFS to set graph by use correspoing map
 *      MST PRIM
 *       */
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define see(x) //(cerr << "LINE " << __LINE__ << " : " << #x << " : " << x << endl)
#define mv 105
#define INF (1 << 30)
using namespace std;
char mp[55][55];
int cor[55][55];
int mat[mv][mv];
int dis[mv][mv];
int d[mv];
int c,r;
bool in[mv];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int wt[55];
int cnt;
struct point
{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
};
void bfs(point now)
{
    queue <point> Q;
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
            dis[i][j] = INF;
    int lb = cor[now.x][now.y];
    dis[now.x][now.y] = 0;
    Q.push(now);
    while(!Q.empty())
    {
        point temp(Q.front().x,Q.front().y);
        for(int i = 0;i < 4;i++)
        {
            point dir = point(temp.x + dx[i],temp.y + dy[i]);
            if(dir.x >= 0 && dir.x < r && dir.y >= 0 && dir.y < wt[dir.x] && mp[dir.x][dir.y] != '#' && dis[dir.x][dir.y] > dis[temp.x][temp.y] + 1)
            {
                dis[dir.x][dir.y] = dis[temp.x][temp.y] + 1;
                Q.push(dir);
            }
        }
        Q.pop();
    }
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
        {
            if(cor[i][j] == -1)
                continue;
            mat[lb][cor[i][j]] = mat[cor[i][j]][lb] = dis[i][j];
        }
}
int prim()
{
    for(int i = 0;i < cnt;i++)
    {
        in[i] = false;
        if(!i)
            d[i] = 0;
        else
            d[i] = INF;
    }
    int ans = 0;
    for(int i = 0;i < cnt;i++)
    {
        int minn = INF,mark = 0;
        for(int j = 0;j < cnt;j++)
        {
            if(!in[j] && d[j] < minn)
            {
                mark = j;
                minn = d[j];
            }
        }
        in[mark] = true;
        ans += d[mark];
        for(int j = 0;j < cnt;j++)
            if(!in[j] && d[j] > mat[mark][j])
                d[j] = mat[mark][j];
    }
    return ans;
}
void solve()
{
    scanf("%d %d",&c,&r);
    for(int i = 0;i < r;i++)//index map
        for(int j = 0;j < c;j++)
            cor[i][j] = -1;
    char temp[100];
    gets(temp);
    for(int i = 0;i < r;i++)//initial map
        gets(mp[i]);
    cnt = 1;
    for(int i = 0;i < r;i++)
    {
        wt[i] = strlen(mp[i]);
        for(int j = 0;j < wt[i];j++)
        {
            if(mp[i][j] == 'A')
                cor[i][j] = cnt++;
            else if(mp[i][j] == 'S')
                cor[i][j] = 0;
        }
    }
    for(int i = 0;i < cnt;i++)
        for(int j = 0;j < cnt;j++)
            mat[i][j] = INF;
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
        {
            if(cor[i][j] == -1)
                continue;
            point now(i,j);
            bfs(now);
        }
    printf("%d\n",prim());
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
        solve();
}
