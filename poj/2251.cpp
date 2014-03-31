#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int INF = 9000 + 3;
int l,r,c;
int map[35][35][35],dis[35][35][35];
int dx[] = {-1,1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
struct v
{
    int x,y,z;
    v(){}
    v(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
} s,e;
queue <v> Q;
bool judge(v temp,v now)
{
    return (temp.x >= 0 && temp.x < r) && (temp.y >= 0 && temp.y < c) && (temp.z >= 0 && temp.z < l) && map[temp.x][temp.y][temp.z] != 0 && dis[temp.x][temp.y][temp.z] > dis[now.x][now.y][now.z] + 1 ;
}
void bfs()
{
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
            for(int k = 0;k < l;k++)
                dis[i][j][k] = INF;
    dis[s.x][s.y][s.z] = 0;
    Q.push(s);
    while(!Q.empty())
    {
        v now = v(Q.front().x,Q.front().y,Q.front().z);
        for(int opt = 0;opt < 6;opt++)
        {
            v temp = v(now.x + dx[opt],now.y + dy[opt],now.z + dz[opt]);
            if(judge(temp,now))
            {
                dis[temp.x][temp.y][temp.z] = dis[now.x][now.y][now.z] + 1;
                Q.push(temp);
            }
        }
        Q.pop();
    }
}
int main()
{
    while(scanf("%d%d%d",&l,&r,&c) == 3 && (l || r || c))
    {
        for(int k = 0;k < l;k++)
        {
            for(int i = 0;i < r;i++)
            {
                for(int j = 0;j < c;j++)
                {
                    char opt;
                    scanf(" %c",&opt);
                    if(opt == 'S')
                    {
                        s = v(i,j,k);
                        map[i][j][k] = 1;
                    }
                    else if(opt == 'E')
                    {
                        e = v(i,j,k);
                        map[i][j][k] = 1;
                    }
                    else if(opt == '#')
                        map[i][j][k] = 0;
                    else if(opt == '.')
                        map[i][j][k] = 1;
                }
            }
        }
        bfs();
        int ans = dis[e.x][e.y][e.z];
        if(ans == INF)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n",ans);
    }
}
