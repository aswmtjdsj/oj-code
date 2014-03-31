#include <iostream>
#include <cstdio>
using namespace std;
int map[25][25],newm[25][25];
int d[20];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main()
{
    int t;
    scanf("%d",&t);
    for(int p = 0;p < t;p++)
    {
        int n;
        scanf("%d",&n);
        for(int i = 0;i < 16;i++)
            scanf("%d",&d[i]);
        for(int i = 0;i < 20;i++)
            for(int j = 0;j < 20;j++)
                scanf("%d",&map[i][j]);
        for(int c = 0;c < n;c++)
        {
            for(int i = 0;i < 20;i++)
                for(int j = 0;j < 20;j++)
                {
                    newm[i][j] = map[i][j];
                    for(int b = 0;b < 4;b++)
                    {
                        if(i + dx[b] >= 0 && i + dx[b] < 20 && j + dy[b] >= 0 && j + dy[b] < 20)
                            newm[i][j] += map[i + dx[b]][j + dy[b]];
                    }
                }
            for(int i = 0;i < 20;i++)
                for(int j = 0;j < 20;j++)
                {
                    //printf("%d ",newm[i][j]);
                    if(map[i][j] + d[newm[i][j]] > 3)
                        map[i][j] = 3;
                    else if(d[newm[i][j]] + map[i][j] < 0)
                        map[i][j] = 0;
                    else
                        map[i][j] += d[newm[i][j]];
                    //if(j == 19)
                    //  printf("\n");
                }
        }
        for(int i = 0;i < 20;i++)
            for(int j = 0;j < 20;j++)
            {
                switch(map[i][j])
                {
                    case 0:
                        printf(".");
                        break;
                    case 1:
                        printf("!");
                        break;
                    case 2:
                        printf("X");
                        break;
                    case 3:
                        printf("#");
                        break;
                }
                if(j == 19)
                    printf("\n");
            }
        if(p != t - 1)
            printf("\n");
    }
}
