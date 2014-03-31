#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define X(a) (a).first
#define Y(a) (a).second
#define maxn 205
typedef pair<long long,int> S;
bool fucked[maxn];
int n;
S bfs()
{
    memset(fucked,0,sizeof(fucked));
    queue <S> Q;
    S temp = make_pair(1ll,1%n);
    fucked[1%n]=1;
    Q.push(temp);
    while(!Q.empty())
    {
        S now = Q.front();
        Q.pop();
        if(Y(now) == 0)
            return now;
        long long x = X(now) * 10;
        if(!fucked[(x%n)])
        {
            Q.push(make_pair(x,x%n));
            fucked[(x%n)] = 1;
        }
        if(!fucked[((x+1)%n)])
        {
            Q.push(make_pair(x+1,(x+1)%n));
            fucked[((x+1)%n)] = 1;
        }
    }
}
int main()
{
    while(scanf("%d",&n) == 1 && n)
        printf("%lld\n",X(bfs()));
}
