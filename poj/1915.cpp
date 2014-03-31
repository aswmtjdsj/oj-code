/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#define see(x) cerr << " LINE " << __LINE__ << ":" << #x << " : " << x << endl
#define SP system("pause")
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int INF = 200000000;
//const int dx[4] = {0,0,-1,1};
//const int dy[4] = {-1,1,0,0};
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define parent(x) ((x) >> 1)
#define maxv 1000
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
#define PQ priority_queue
#define PB push_back
struct point
{
    int x,y;
    point(){}
    point(int a,int b):x(a),y(b){}
}s,t;
int l,d[305][305];
const int inf = 305 * 305;
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
bool check(int x,int y)
{
    return (0 <= x && x < l) && (0 <= y && y < l);
}
void bfs()
{
    queue <point> Q;
    Q.push(s);
    d[s.x][s.y] = 0;
    if(d[t.x][t.y] == 0)
        return ;
    while(!Q.empty())
    {
        point now = Q.front();
        Q.pop();
        for(int i = 0;i < 8;i++)
        {
            int x = now.x + dx[i],y = now.y + dy[i];
            if(check(x,y) && d[x][y] > d[now.x][now.y] + 1)
            {
                d[x][y] = d[now.x][now.y] + 1;
                Q.push(point(x,y));
            }
        }
    }
}
int main()
{
    /*#ifndef ONLINE_JUDGE
      freopen("data.in","r",stdin);
      freopen("data.out","w",stdout);
#endif*/
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&l);
        for(int j = 0;j < l;j++)
            for(int k = 0;k < l;k++)
                d[j][k] = inf;
        int a,b;
        scanf("%d %d",&a,&b);
        s = point(a,b);
        scanf("%d %d",&a,&b);
        t = point(a,b);
        bfs();
        printf("%d\n",d[t.x][t.y]);
    }
}
