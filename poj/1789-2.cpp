/*
     Coded by BUPT-[aswmtjdsj] @ Penalty
     */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int INF = 200000000;
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define parent(x) ((x) >> 1)
#define maxv 2000
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
#define PQ priority_queue
struct edge
{
    int u,v,w;
    edge(){}
    edge(int a,int b,int c):u(a),v(b),w(c){}
    bool friend operator < (const edge &a,const edge &b)
    {
        return a.w > b.w;
    }
};
bool vis[maxv + 5];
int mat[maxv + 5][maxv + 5];
char str[maxv + 5][10];
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 1;i <= n;i++)
            vis[i] = false;
        for(int i = 1;i <= n;i++)
            scanf("%s",str[i]);
        for(int i = 1;i <= n;i++)
            for(int j = i ;j <= n;j++)
            {
                if(i == j)
                    mat[i][j] = 0;
                else
                {
                    int t = 0;
                    for(int k = 0;k < 7;k++)
                    {
                        if(str[i][k] != str[j][k])
                            t++;
                    }
                    mat[i][j] = mat[j][i] = t;
                }
            }
        PQ <edge> Q;
        int mark = 1;
        int now = 1;
        vis[1] = true;
        int sum = 0;
        while(mark < n)
        {
            for(int i = 1;i <= n;i++)
            {
                if(i != now && !vis[i] && mat[i][now] > 0)
                {
                    edge t(now,i,mat[i][now]);
                    Q.push(t);
                }
            }
            while(!Q.empty() && vis[Q.top().v])
                Q.pop();
            sum += Q.top().w;
            now = Q.top().v;
            mark ++;
            vis[Q.top().v] = true;
        }
        printf("The highest possible quality is 1/%d.\n",sum);
    }
}
