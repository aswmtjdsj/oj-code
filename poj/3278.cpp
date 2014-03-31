#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define maxn 100000
int dis[maxn+2];
struct dist
{
    int pos,step;
    dist(){}
    dist(int _p,int _s):pos(_p),step(_s){}
};
bool operator < (dist a,dist b)
{
    return a.step > b.step;
}
int n,k;
void pfs()
{
    fill(dis,dis + maxn+1,maxn+2);
    priority_queue <dist> Q;
    dis[n] = 0;
    Q.push(dist(n,0));
    while(!Q.empty())
    {
        dist now = Q.top();
        Q.pop();
        if(now.pos == k)
            break;
        if(now.pos < maxn && dis[now.pos+1] > dis[now.pos]+1)
        {
            dis[now.pos+1] = dis[now.pos] + 1;
            Q.push(dist(now.pos+1,dis[now.pos+1]));
        }
        if(now.pos > 0 && dis[now.pos-1] > dis[now.pos] + 1)
        {
            dis[now.pos-1] = dis[now.pos] + 1;
            Q.push(dist(now.pos-1,dis[now.pos-1]));
        }
        if(now.pos * 2 <= maxn && dis[now.pos*2] > dis[now.pos] + 1)
        {
            dis[now.pos*2] = dis[now.pos] + 1;
            Q.push(dist(now.pos*2,dis[now.pos*2]));
        }
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    pfs();
    printf("%d\n",dis[k]);
}
