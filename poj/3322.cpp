#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define maxn 505
#define X(a) (a).first
#define Y(a) (a).second
const int inf = 500 * 500 + 5;
typedef pair<int,int> pii;
pii operator + (const pii a, const pii b)
{
    return make_pair(X(a)+X(b), Y(a)+Y(b));
}
struct status
{
    pii now;
    int k;
    int step;
    status(){}
    status(pii _n,int _k, int _s):now(_n), k(_k), step(_s){}
};
pii d[] = {make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1)};
int co[] = {1,0,3,2};
char ditu[maxn][maxn];
int r,c;
int dis[maxn][maxn][6];

bool check(pii a)
{
    int x = X(a),y = Y(a);
    return 0 <= x && x < r && 0 <= y && y < c;
}

void bfs()
{
    pii s, e;
    int nk = 4;
    for(int i = 0;i < r;i++)
        for(int j = 0;j < c;j++)
        {
            if(ditu[i][j] == 'X')
                s = make_pair(i, j);
            if(ditu[i][j] == 'O')
                e = make_pair(i, j);
        }
    for(int k = 0;k < 4;k++)
    {
        pii ns = s + d[k];
        if(ditu[X(ns)][Y(ns)] == 'X')
        {
            nk = k;
            dis[X(s)][Y(s)][k] = 0;
            dis[X(ns)][Y(ns)][co[k]] = 0;
        }
    }
    queue <status> Q;
    Q.push(status(s, nk, 0));
    while(!Q.empty())
    {
        status temp = Q.front();
        Q.pop();
        //printf("STEP:%d X:%d Y:%d DIR:%d\n",temp.step,X(temp.now),Y(temp.now),temp.k);
        if(ditu[X(temp.now)][Y(temp.now)] == 'O')
            continue;
        if(temp.k == 4)
        {
            for(int k = 0;k < 4;k++)
            {
                pii nt = temp.now + d[k],nt2 = nt + d[k];
                if(!check(nt) ||  !check(nt2) || ditu[X(nt)][Y(nt)] == '#' or ditu[X(nt2)][Y(nt2)] == '#')
                {//puts("fuck1");
                    continue;
                }
                bool flag = false;
                if(dis[X(nt)][Y(nt)][k] > temp.step + 1)
                {
                    flag = true;
                    dis[X(nt)][Y(nt)][k] = temp.step + 1;
                }
                if(dis[X(nt2)][Y(nt2)][co[k]] > temp.step + 1)
                {
                    dis[X(nt2)][Y(nt2)][co[k]] = temp.step + 1;
                    flag = true;
                }
                if(flag)
                    Q.push(status(nt,k,temp.step+1));
            }
        }
        else
        {
            pii now = temp.now,now2 = now + d[temp.k];
            for(int k = 0;k < 4;k++)
            {
                if(k == temp.k || k == co[temp.k])
                {
                    pii np = (k == temp.k) ? now2 + d[k]: now +d[k];
                    if(!check(np) or (ditu[X(np)][Y(np)] == 'E' or ditu[X(np)][Y(np)] == '#'))
                    {//puts("fuck2");
                        continue;
                    }
                    if(dis[X(np)][Y(np)][4] > temp.step + 1)
                    {
                        dis[X(np)][Y(np)][4] = temp.step + 1;
                        Q.push(status(np,4,temp.step+1));
                    }
                }
                else
                {
                    pii nt = now + d[k],nt2 = now2 + d[k];
                    if(!check(nt) or  !check(nt2) or (ditu[X(nt)][Y(nt)] == '#' or ditu[X(nt2)][Y(nt2)] == '#'))
                    {//puts("fuck3");
                        continue;
                    }
                    bool flag = false;
                    if(dis[X(nt)][Y(nt)][temp.k] > temp.step + 1)
                    {
                        flag = true;
                        dis[X(nt)][Y(nt)][temp.k] = temp.step + 1;
                    }
                    if(dis[X(nt2)][Y(nt2)][co[temp.k]] > temp.step + 1)
                    {
                        dis[X(nt2)][Y(nt2)][co[temp.k]] = temp.step + 1;
                        flag = true;
                    }
                    if(flag)
                        Q.push(status(nt,temp.k,temp.step+1));
                }
            }
        }
    }
    if(dis[X(e)][Y(e)][4] != inf) 
        printf("%d\n",dis[X(e)][Y(e)][4]);
    else
        puts("Impossible");
}

int main()
{
    while(scanf("%d %d",&r,&c) == 2 && ( r || c))
    {
        for(int i = 0;i < r;i++)
            scanf("%s",ditu[i]);
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
                for(int k = 0;k < 5;k++)
                    dis[i][j][k] = inf;
        bfs();
    }
}
