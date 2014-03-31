/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 915
 * */
/*
 * BFS + psedo-DFS.....(just simulation)
 * do not use such 'standard' "recursive" techniques...such as mark array and blabla...
 * just simulate left-up-right-down(go back!!!no matter we go back...just do not MARK it)
 * and every step ,step++
 * when finding the end,stop....
 * */
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <stack>
#define maxn 50
using namespace std;
const int inf = 10000;
struct point
{
    int x,y,dir;
    point(){}
    point(int a,int b):x(a),y(b){}
    point(int a,int b,int c):x(a),y(b),dir(c){}
}st,en;
bool vis[maxn][maxn];
int dis[maxn][maxn];
char M[maxn][maxn];
int T,h,w,a1,a2,a3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool check(int x,int y)
{
    return (1 <= x && x <= w) && (1 <= y && y <= h) && (M[x][y] != '#');
}
int init(point q)
{
    memset(vis,false,sizeof(vis));
    if(q.x == 1)
        return 2;
    if(q.x == w)
        return 0;
    if(q.y == 1)
        return 1;
    if(q.y == h)
        return 3;
}
int dfs(point s,point t,int dir,int step,int mod)
{
    if(s.x == t.x && s.y == t.y)
        return step + 1;
    if(check(s.x,s.y) == 0)
        return 0;
    int ss;
    for(int i = 0;i < 4;i++)
    {
        int temp = dir - 1 + i;
        temp += 4;
        temp %= 4;
        int xx = s.x + dx[temp],yy = s.y + dy[temp];
        ss = dfs(point(xx,yy),t,temp,step + 1,mod);
        if(ss > 0)
            break;
    }
    return ss;
}
void bfs()
{
    queue <point> Q;
    dis[st.x][st.y] = 1;
    Q.push(st);
    while(!Q.empty())
    {
        point now = Q.front();
        Q.pop();
        for(int i = 0;i < 4;i++)
        {
            int xx = now.x + dx[i],yy = now.y + dy[i];
            if(check(xx,yy) && dis[xx][yy] > dis[now.x][now.y] + 1)
            {
                dis[xx][yy] = dis[now.x][now.y] + 1;
                Q.push(point(xx,yy));
            }
        }
    }
}
void solve()
{
    scanf("%d %d",&h,&w);
    for(int i = 1;i <= w;i++)
        for(int j = 1;j <= h;j++)
        {
            scanf(" %c",&M[i][j]);
            if(M[i][j] == 'E')
                en = point(i,j);
            else if(M[i][j] == 'S')
                st = point(i,j);
            dis[i][j] = inf;
        }
    int dir;
    a1 = a2 = 0;
    dir = init(st);
    a1= dfs(st,en,dir,0,1);
    dir = init(en);
    a2=dfs(en,st,dir,0,2);
    bfs();
    a3 = dis[en.x][en.y];
    printf("%d %d %d\n",a1,a2,a3);
}
int main()
{
    scanf("%d",&T);
    for(int i = 0;i < T;i++)
        solve();
}
