#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
#define maxn 105
using namespace std;
const short inf = 20000;
bool con[maxn][maxn][7];
char mat[maxn][maxn];
bool road[maxn][maxn];
bool zoc[maxn][maxn];
int n,m,MP;
int stx,sty,enx,eny;
const double eps = 1e-6;
char comp(double x)
{
    if(fabs(x) < eps)
        return 0;
    else if(x < -eps)
        return -1;
    else
        return 1;
}
struct status
{
    short x,y,turn;
    float mp;
    status(){}
    status(short _x,short _y,float _m,short _t):x(_x),y(_y),mp(_m),turn(_t){}
};
/*bool operator < (const status a,const status b)
 * {
 *     return (a.turn > b.turn || (a.turn == b.turn && comp(a.mp - b.mp) < 0));
 *     }*/
struct dist
{
    short turn;
    float mp;
    dist(){}
    dist(float _m,int _t):turn(_t),mp(_m){}
} dis[maxn][maxn];
/*
 * 6 nw
 * 5 w
 * 4 sw
 * 3 se
 * 2 e
 * 1 ne
 * */
char dx1[] = {0,-1,0,1,1,0,-1};//even
char dy1[] = {0,1,1,1,0,-1,0};
char dx2[] = {0,-1,0,1,1,0,-1};//odd
char dy2[] = {0,0,1,0,-1,-1,-1};
bool check(short x,short y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}
void bfs()
{
    queue <status> Q;
    Q.push(status(stx,sty,MP,1));
    dis[stx][sty] = dist(MP,1);
    while(!Q.empty())
    {
        status now = Q.front();
        Q.pop();
        //if(now.x == enx && now.y == eny)
        //break;
        if(comp(now.mp) <= 0)
        {
            now.mp = MP;
            now.turn ++;
        }
        for(int i = 1;i <= 6;i++)
        {
            int x,y;
            if(now.x % 2 == 0)
            {
                x = now.x + dx1[i];
                y = now.y + dy1[i];
            }
            else
            {
                x = now.x + dx2[i];
                y = now.y + dy2[i];
            }
            float pm = now.mp;
            if(!check(x,y) || mat[x][y] == 3)
                continue;
            else if(zoc[x][y] == 1 && zoc[now.x][now.y] == 1)
            {
                if(dis[x][y].turn > now.turn || (dis[x][y].turn == now.turn && comp(dis[x][y].mp) < 0))
                {
                    Q.push(status(x,y,0,now.turn));
                    dis[x][y] = dist(0,now.turn);
                }
            }
            else if(road[x][y] == true && road[now.x][now.y] == true)
            {
                if(dis[x][y].turn > now.turn || (dis[x][y].turn == now.turn && comp(dis[x][y].mp - (pm - 0.25)) < 0))
                {
                    Q.push(status(x,y,pm - 0.25,now.turn));
                    dis[x][y] = dist(pm - 0.25,now.turn);
                }
            }
            else if(con[now.x][now.y][i] == 1)
            {
                if(dis[x][y].turn > now.turn || (dis[x][y].turn == now.turn && comp(dis[x][y].mp) < 0))
                {
                    Q.push(status(x,y,0,now.turn));
                    dis[x][y] = dist(0,now.turn);
                }
            }
            else if(mat[x][y] == 1)
            {
                if(dis[x][y].turn > now.turn || (dis[x][y].turn == now.turn && comp(dis[x][y].mp - (pm - 2)) < 0))
                {
                    Q.push(status(x,y,pm - 2,now.turn));
                    dis[x][y] = dist(pm - 2,now.turn);
                }
            }
            else if(mat[x][y] == 0)
            {
                if(dis[x][y].turn > now.turn || (dis[x][y].turn == now.turn && comp(dis[x][y].mp - (pm - 1)) < 0))
                {
                    Q.push(status(x,y,pm - 1,now.turn));
                    dis[x][y] = dist(pm - 1,now.turn);
                }
            }
        }
    }
}
/*
   0 cost 1
   1 cost 2
   3 can't
   */
void fuck(short x,short y)
{
    for(short i = 1;i <= 6;i++)
    {
        if(x % 2 == 0 && check(x + dx1[i],y + dy1[i]))
            zoc[x + dx1[i]][y + dy1[i]] = true;
        else
        {
            if( check(x + dx2[i],y + dy2[i]))
                zoc[x + dx2[i]][y + dy2[i]] = true;
        }
    }
}

void gao()
{
    scanf("%d %d %d",&n,&m,&MP);
    for(short i = 1;i <= n;i++)
        for(short j = 1;j <= m;j++)
        {
            road[i][j] = 0;
            mat[i][j] = -1;
            zoc[i][j] = 0;
        }
    for(short i = 1;i <= n;i++)
        for(short j = 1;j <= m;j++)
        {
            int opt;
            scanf("%d",&opt);
            for(short k = 9;k >= 0;k--)
            {
                if(opt >= (1 << k))
                {
                    opt -= (1 << k);
                    if(k > 3)
                        con[i][j][k - 3] = true;
                    else
                    {
                        if(k == 3)
                        {
                            mat[i][j] = 3;
                            fuck(i,j);
                        }
                        else
                        {
                            if(mat[i][j] == -1)
                                mat[i][j] = k;
                            if(mat[i][j] == 2)
                            {
                                mat[i][j] = k;
                                road[i][j] = true;
                            }
                        }
                    }
                }
                else
                {
                    if(k > 3)
                        con[i][j][k - 3] = false;
                }
            }
        }
    for(short i = 1;i <= n;i++)
        for(short j = 1;j <= m;j++)
            dis[i][j] = dist(0,inf);
    scanf("%d %d %d %d",&stx,&sty,&enx,&eny);
    stx++;
    sty++;
    enx++;
    eny++;
    bfs();
    short ans = dis[enx][eny].turn;
    printf("%d\n",(ans == inf?-1:ans));
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
    {
        printf("Case %d: ",i);
        gao();
    }
}
