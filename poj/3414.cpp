#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 105
struct node
{
    int x,y;
    int mth;
    node(){}
    node(int a,int b,int c):x(a),y(b),mth(c){}
}pre[maxn][maxn];
const int inf = 100000;
int A,B,C,ans,X,Y;
int d[maxn][maxn];
const char method[][20] = {"","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
void bfs()
{
    queue<node> Q;
    Q.push(node(0,0,0));
    d[0][0] = 0;
    while(!Q.empty())
    {
        node now = Q.front();
        int temp = d[now.x][now.y];
        if(now.x == C || now.y == C)
        {
            ans = min(ans,temp);
            if(ans == temp)
            {
                X = now.x;
                Y = now.y;
            }
        }
        Q.pop();
        for(int i = 1;i <= 6;i++)
        {
            if(i == 1 && now.x < A && d[A][now.y] > temp + 1)
            {
                pre[A][now.y] = node(now.x,now.y,i);
                Q.push(node(A,now.y,i));
                d[A][now.y] = temp + 1;
            }
            else if(i == 2 && now.y < B && d[now.x][B] > temp + 1)
            {
                pre[now.x][B] = node(now.x,now.y,i);
                d[now.x][B] = temp + 1;
                Q.push(node(now.x,B,i));
            }
            else if(i == 3 && now.x > 0 && d[0][now.y] > temp + 1)
            {
                pre[0][now.y] = node(now.x,now.y,i);
                d[0][now.y] = temp + 1;
                Q.push(node(0,now.y,i));
            }
            else if(i == 4 && now.y > 0 && d[now.x][0] > temp + 1)
            {
                pre[now.x][0] = node(now.x,now.y,i);
                d[now.x][0] = temp + 1;
                Q.push(node(now.x,0,i));
            }
            else if(i == 5 && now.x > 0 && now.y < B)
            {
                int b = min(B,now.y + now.x);
                int a = max(now.y + now.x - B,0);
                if(d[a][b] > temp + 1)
                {
                    pre[a][b] = node(now.x,now.y,i);
                    d[a][b] = temp + 1;
                    Q.push(node(a,b,i));
                }
            }
            else if(i == 6 && now.x < A && now.y > 0)
            {
                int a = min(A,now.y + now.x);
                int b = max(now.y + now.x - A,0);
                if(d[a][b] > temp + 1)
                {
                    pre[a][b] = node(now.x,now.y,i);
                    d[a][b] = temp + 1;
                    Q.push(node(a,b,i));
                }
            }
        }
    }
}
void dfs(int x,int y)
{
    if(pre[x][y].mth != 0)
        dfs(pre[x][y].x,pre[x][y].y);
    if(pre[x][y].mth != 0)
        puts(method[pre[x][y].mth]);
}
int main()
{
    scanf("%d %d %d",&A,&B,&C);
    for(int i = 0;i <= A;i++)
        for(int j = 0;j <= B;j++)
        {
            d[i][j] = inf;
            pre[i][j].mth = 0;
        }
    ans = inf;
    bfs();
    if(ans == inf)
        puts("impossible");
    else
    {
        printf("%d\n",ans);
        dfs(X,Y);
    }
}
