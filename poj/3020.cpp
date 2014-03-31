#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define maxn 405
#define maxh 42
#define maxw 12
bool in[maxh][maxw];
bool map[maxn][maxn];
bool vis[maxn];
int mac[maxn];
int num[maxh][maxw];
int h,w,n;
bool find(int x)
{
    for(int i = 1;i <= n;i++)
    {
        if(map[x][i] && !vis[i])
        {
            vis[i] = true;
            if(!mac[i] || find(mac[i]))
            {
                mac[i] = x;
                return true;
            }
        }
    }
    return false;
}
void gao()
{
    scanf("%d %d",&h,&w);
    n = h * w;
    int tot = 0;
    for(int i = 1;i <= h;i++)
        for(int j = 1;j <= w;j++)
        {
            char opt;
            scanf(" %c",&opt);
            in[i][j] = (opt == '*')?1:0;
            if(opt == '*')tot++;
            num[i][j] = (i - 1) * w + j;
        }
    memset(map,0,sizeof(map));
    memset(mac,0,sizeof(mac));
    for(int i = 1;i <= h;i++)
        for(int j = 1;j <= w - 1;j++)
            if(in[i][j] && in[i][j + 1])
                map[num[i][j]][num[i][j+1]]=map[num[i][j+1]][num[i][j]]=1;
    for(int j = 1;j <= w;j++)
        for(int i = 1;i <= h - 1;i++)
            if(in[i][j] && in[i + 1][j])
                map[num[i][j]][num[i+1][j]]=map[num[i+1][j]][num[i][j]]=1;
    /*for(int i = 1;i <= n;i++)
     *      for(int j = 1;j <= n;j++)
     *                  cout << map[i][j] << (j==n?"\n":"");*/
    int ans = 0;
    //cout << tot << endl;
    for(int i = 1;i <= n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
            ans++;
    }
    printf("%d\n",tot - ans/2);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)gao();
}
