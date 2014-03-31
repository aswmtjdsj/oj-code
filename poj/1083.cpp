/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 912
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
int main()
{
    int t;
    scanf("%d",&t);
    int cor[205];
    for(int i = 0;i < t;i++)
    {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= 200;i++)
            cor[i] = 0;
        for(int j = 0;j < n;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            int m1 = (min(a,b) + 1) / 2,m2 = (max(a,b) + 1) / 2;
            for(int k = m1;k <= m2;k++)
                cor[k] ++;
        }
        int ans = 0;
        for(int j = 1;j <= 200;j++)
            ans = (ans < cor[j]) ? cor[j] : ans;
        printf("%d\n",ans * 10);
    }
}
