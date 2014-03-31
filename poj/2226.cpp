#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 630
#define data 55
bool vis[maxn];
int mac[maxn];
bool map[maxn][maxn];
int r,c,cntx,cnty;
int conx[data][data],cony[data][data];
char old[maxn][maxn];
bool find(int x)
{
    for(int i = 1;i <= cnty;i++)
    {
        if(!vis[i] && map[x][i])
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
int main()
{
    scanf("%d %d",&r,&c);
    for(int i = 1;i <= r;i++)
        for(int j = 1;j <= c;j++)
            scanf(" %c",&old[i][j]);
    memset(conx,0,sizeof(conx));
    memset(cony,0,sizeof(cony));
    memset(map,0,sizeof(map));
    memset(mac,0,sizeof(mac));
    cntx = cnty = 0;
    for(int i = 1;i <= r;i++)
    {
        bool flag = false;
        for(int j = 1;j <= c;j++)
        {
            if(old[i][j] == '*')
            {
                if(!flag)
                {
                    conx[i][j] = ++cntx;
                    flag = true;
                }
                else
                {
                    if(conx[i][j - 1] != 0)
                        conx[i][j] = cntx;
                    else
                        conx[i][j] = ++cntx;
                }
            }
        }
    }
    for(int j = 1;j <= c;j++)
    {
        bool flag = false;
        for(int i = 1;i <= r;i++)
        {
            if(old[i][j] == '*')
            {
                if(!flag)
                {
                    cony[i][j] = ++cnty;
                    flag = true;
                }
                else
                {
                    if(cony[i - 1][j] != 0)
                        cony[i][j] = cnty;
                    else
                        cony[i][j] = ++cnty;
                }
            }
        }
    }/*
        for(int i = 1;i <= r;i++)
        {
        for(int j = 1;j <= c;j++)
        {
        cout << conx[i][j];
        }
        puts("");
        }
        for(int i = 1;i <= r;i++)
        {
        for(int j = 1;j <= c;j++)
        {
        cout << cony[i][j];
        }
        puts("");
        }*/
    for(int i = 1;i <= r;i++)
        for(int j = 1;j <= c;j++)
            if(conx[i][j] && cony[i][j])
                map[conx[i][j]][cony[i][j]] = 1;
    int ans = 0;
    //cout << cntx << ' ' << cnty << endl;
    for(int i = 1;i <= cntx;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
            ans++;
    }
    printf("%d\n",ans);
}
