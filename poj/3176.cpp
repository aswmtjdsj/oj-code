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
#define see(x) cerr << " LINE " << __LINE__ << ":" << #x << " : " << x << endl
#define SP system("pause")
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
void solve()
{
}
int M[355][355];
int main()
{
    /*#ifndef ONLINE_JUDGE
     *         freopen("data.in","r",stdin);
     *                 freopen("data.out","w",stdout);
     *                    #endif*/
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)
            scanf("%d",&M[i][j]);
    }
    for(int i = n - 1;i >= 1;i--)
    {
        for(int j = 1;j <= i;j++)
            M[i][j] = max(M[i + 1][j],M[i + 1][j + 1]) + M[i][j];
    }
    printf("%d\n",M[1][1]);
}
