#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char map[12][12];
int n;
char cnt[12][12][5];
char dx[] = {1,0,-1,0};
char dy[] = {0,1,0,-1};
struct node
{
    int x,y;
    node(){}
    node(int a,int b):x(a),y(b){}
}ord[105];
int tot = 0;
int sx,sy;
void bfs()
{
    ord[tot++] = node(sx,sy);
    queue <node> Q;
    Q.push(node(sx,sy));
    map[sx][sy] = 2;
    while(!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        for(int i = 0;i < 4;i++)
        {
            char x = now.x + dx[i],y = now.y + dy[i];
            if(map[x][y] == 1)
            {
                map[x][y] = 2;
                Q.push(node(x,y));
                ord[tot++] = node(x,y);
                cnt[now.x][now.y][i] = true;
            }
        }
    }
}
char cor[4] = {'R','T','L','B'};
char opt[20];
int main()
{
    cin.getline(opt,20);
    int l = strlen(opt);
    bool mark = true;
    for(int i = 0;i < l;i++)
        if(opt[i] == ' ')
        {
            mark = false;
            break;
        }
    if(mark)
    {
        sscanf(opt,"%d",&n);
        memset(map,0,sizeof(map));
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i < n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if(i == 0)
                sx = a,sy = b;
            map[a][b] = 1;
        }
        tot = 0;
        bfs();
        printf("%d %d\n",sx,sy);
        for(int i = 0;i < tot;i++)
        {
            for(int j = 0;j < 4;j++)
                if(cnt[ord[i].x][ord[i].y][j])
                    putchar(cor[j]);
            putchar(i == tot - 1?'.':',');
            puts("");
        }
    }
    else
    {
        sscanf(opt,"%d %d",&sx,&sy);
        queue <node> Q;
        memset(map,0,sizeof(map));
        Q.push(node(sx,sy));
        //printf("%d %d\n",sx,sy);
        while(scanf("%s",opt) == 1)
        {
            node now = Q.front();
            map[now.x][now.y] = 1;
            Q.pop();
            for(int i = 0;i < strlen(opt);i++)
            {
                int x,y;
                bool mark = true;
                switch(opt[i])
                {
                    case 'R':
                        x = now.x + dx[0];
                        y = now.y + dy[0];
                        break;
                    case 'T':
                        x = now.x + dx[1];
                        y = now.y + dy[1];
                        break;
                    case 'L':
                        x = now.x + dx[2];
                        y = now.y + dy[2];
                        break;
                    case 'B':
                        x = now.x + dx[3];
                        y = now.y + dy[3];
                        break;
                    default:
                        mark = false;
                        break;
                }
                if(mark)
                    Q.push(node(x,y));
            }
            if(opt[strlen(opt) - 1] == '.')
                break;
        }
        tot = 0;
        for(int i = 1;i <= 10;i++)
            for(int j = 1;j <= 10;j++)
                if(map[i][j])
                    tot++;
        printf("%d\n",tot);
        for(int i = 1;i <= 10;i++)
            for(int j = 1;j <= 10;j++)
                if(map[i][j])
                    printf("%d %d\n",i,j);
    }
}