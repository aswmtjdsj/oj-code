#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
#define maxn 205
int p[maxn];
int mod[maxn];
int mat[maxn][maxn];
int pos[maxn][maxn];
char str[maxn],s[maxn];
int n,k;
int main()
{
    while(scanf("%d",&n) == 1 && n)
    {
        memset(pos,-1,sizeof(pos));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&p[i]);
            pos[i][i] = 0;
        }
        for(int i = 1;i <= n;i++)
            mod[i] = n + 1;
        for(int i = 1;i <= n;i++)
            mat[0][i] = i;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                mat[i][p[j]] = mat[i-1][j];
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                if(mat[j][i] == mat[0][i])
                {
                    mod[i] = j;
                    break;
                }
        /*for(int i = 1;i <= n;i++)
         *      {
         *                  printf("calc:(%d) ",mod[i]);
         *                              for(int j = 0;j <= mod[i];j++)
         *                                              printf("%d ",mat[j][i]);
         *                                                          puts("");
         *                                                                  }*/
        while(scanf("%d",&k) == 1 && k)
        {
            getchar();
            gets(str);
            int l = strlen(str);
            if(l < n)
            {
                for(int i = l;i < n;i++)
                    str[i] = ' ';
                str[n] = 0;
            }
            for(int i = 1;i <= n;i++)
            {
                int d = k % mod[i];
                s[i-1] = str[mat[d][i]-1];
            }
            s[n] = 0;
            printf("%s\n",s);
        }
        puts("");
    }
}
