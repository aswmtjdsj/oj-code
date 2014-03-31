#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int w,h,ans;
const int inf = 10000;
struct node
{
    int x,y;
    node(){}
    node(int a,int b):x(a),y(b){}
    bool operator ==(const node p)
    {
        return x == p.x && y == p.y;
    }
}st,en;
const char dx[] = {-1,1,0,0};
const char dy[] = {0,0,-1,1};
char map[22][22];
bool check(node a)
{
    return 0 <= a.x && a.x < h && 0 <= a.y && a.y < w;
}
void dfs(node now,char tu[][22],int step)
{
    int x = now.x,y = now.y;
    if(step == 10)
        return ;
    for(int c = 0;c < 4;c++)
    {
        char tox = dx[c],toy = dy[c];
        int nx = x,ny = y;
        while(1)
        {
            nx += tox;
            ny += toy;
            if(!check(node(nx,ny)) || tu[nx][ny] == '1' || tu[nx][ny] == '3')
                break;
        }
        if(!check(node(nx,ny)))
            continue;
        else if(tu[nx][ny] == '1')
        {
            tu[nx][ny] = '0';
            nx -= tox;
            ny -= toy;
            if(nx != x || ny != y)
                dfs(node(nx,ny),tu,step+1);
            nx += tox;
            ny += toy;
            tu[nx][ny] = '1';
        }
        else if(tu[nx][ny] == '3')
            ans = min(ans,step+1);
    }
}
int main()
{
    while(scanf("%d %d",&w,&h) == 2 && ( w || h))
    {
        for(int i = 0;i < h;i++)
            for(int j = 0;j < w;j++)
            {
                char opt;
                scanf(" %c",&opt);
                map[i][j] = opt;
                if(opt == '2')
                    st = node(i,j);
                if(opt == '3')
                    en = node(i,j);
            }
        ans = inf;
        dfs(st,map,0);
        printf("%d\n",ans==inf?-1:ans);
    }
}
