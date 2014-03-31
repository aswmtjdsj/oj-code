#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ans,n,k;
#define maxn 10
char map[maxn][maxn];
struct node
{
    int x,y;
    node(){}
    node(int a,int b):x(a),y(b){}
};
node sol[maxn];
void dfs(int x,int y,int step)
{
    if(step == k)
        ans++;
    else
    {
        sol[step-1] = node(x,y);
        for(int i = x+1;i <= n;i++)
        {
            if(n - i + 1 + step < k)
                break;
            for(int j = 1;j <= n;j++)
            {
                if(map[i][j] == '.')
                    continue;
                int idx;
                for(idx = 0;idx < step;idx++)
                    if(j == sol[idx].y)
                        break;
                if(idx==step)
                    dfs(i,j,step+1);
            }
        }
    }
}
void gao()
{
    ans = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            scanf(" %c",&map[i][j]);
    if(k > n || k <= 0)
    {
        puts("0");
        return ;
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(map[i][j] == '#')
            {
                //cout << "fuck" << i  << ' ' << j << endl;
                dfs(i,j,1);
            }
    printf("%d\n",ans);
}
int main()
{
    while(scanf("%d %d",&n,&k) == 2 && (~n || ~k))
        gao();
}
