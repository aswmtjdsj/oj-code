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
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};
#define FOR(x,b,a) for(int x = b;x <= a;x++) 
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define parent(x) ((x) >> 1)
#define maxv 1000
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
#define PQ priority_queue
#define PB push_back
int n,m;
struct robot
{
    int x,y;
    char dir;
    robot(){}
    robot(int a,int b,char c):x(a),y(b),dir(c){}
    void read()
    {
        scanf("%d %d %c",&y,&x,&dir);
    }
}rb[105];
int M[105][105];
map <char,int> co;
int cop[] = {'S','E','N','W'};
void solve()
{
    scanf("%d %d",&m,&n);
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            M[i][j] = 0;
    int N,q;
    scanf("%d %d",&N,&q);
    for(int i = 1; i<= N;i++)
    {
        rb[i].read();
        M[rb[i].x][rb[i].y] = i;
    }
    int flag = 1, mark = 0;

    for(int i = 0;i < q;i++)
    {
        int a,b;
        char opt;
        scanf("%d %c %d",&a,&opt,&b);
        if(mark != 0)
            continue;
        if(opt == 'F')
        {
            robot temp(rb[a].x,rb[a].y,rb[a].dir);
            M[rb[a].x][rb[a].y] = 0;
            for(int j = 1;j <= b;j++)
            {
                temp.x += dx[co[temp.dir]];
                temp.y += dy[co[temp.dir]];
                if(temp.x < 1 || temp.x > n || temp.y < 1 || temp.y > m)
                    mark = -1;
                if(M[temp.x][temp.y] != 0)
                    mark = M[temp.x][temp.y];
                if(mark != 0)
                {
                    flag = a;
                    break;
                }
            }
            M[temp.x][temp.y] = a;
            rb[a].x = temp.x;
            rb[a].y = temp.y;
        }
        else
        {
            int mod = b % 4,temp;
            if(opt == 'L')
            {    
                temp = co[rb[a].dir] + mod;
                temp %= 4;
            }
            else
            {
                temp = co[rb[a].dir] - mod;
                if(temp < 0)
                    temp += 4;
                temp %= 4;
            }
            rb[a].dir = cop[temp];
        }

    }
    if(mark == 0)
        printf("OK\n");
    else if(mark == -1)
        printf("Robot %d crashes into the wall\n",flag);
    else
        printf("Robot %d crashes into robot %d\n",flag,mark);
}
int main()
{
    int t;
    co['W'] = 3;
    co['E'] = 1;
    co['N'] = 2;
    co['S'] = 0;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
        solve();
}
