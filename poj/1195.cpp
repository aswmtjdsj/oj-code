/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty
 * */
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
const int dx[4] = {0,0,-1,1};
const int dy[4] = {-1,1,0,0};
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define parent(x) ((x) >> 1)
#define maxv 1000
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
#define PQ priority_queue
#define PB push_back
int m[(1 << 10 ) + 5][(1 << 10 ) + 5],s,l,b,r,t;
int low(int x)
{
    return x & (x ^( x - 1));
}
int sum(int x,int y)
{
    int ans = 0;
    for(int i = x;i > 0;i -= low(i))
        for(int j = y;j > 0;j -= low(j))
            ans += m[i][j];
    return ans;
}
void modi(int x,int y,int a)
{
    for(int i = x;i <= s;i += low(i))
        for(int j = y;j <= s ;j += low(j))
            m[i][j] += a;
}
int opt;
int main()
{
    while(scanf("%d",&opt) == 1 && opt != 3)
    {
        if(opt == 0)
        {
            scanf("%d",&s);
            for(int i = 1;i <= s;i++)
                for(int j = 1;j <= s;j++)
                    m[i][j] = 0;
        }
        if(opt == 1)
        {
            int x,y,a;
            scanf("%d%d%d",&x,&y,&a);
            modi(x + 1,y + 1,a);
        }
        if(opt == 2)
        {
            scanf("%d%d%d%d",&l,&b,&r,&t);
            printf("%d\n",sum(r + 1,t + 1) + sum(l,b) - sum(l,t + 1) - sum(r + 1,b));
        }
    }
}
