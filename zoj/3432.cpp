#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        char str[8],temp[8];
        for(int i = 0;i < 8;i++)
            str[i] = 0;
        for(int i = 0;i < 2 * n - 1;i++)
        {
            for(int j = 0;j < 8;j++)
                temp[j] = 0;
            getchar();
            for(int j = 0;j < 7;j++)
            {
                temp[j] = getchar();
                str[j] ^= temp[j];
            }
        }
        for(int i = 0;i < 7;i++)
            printf("%c",str[i]);
        printf("\n");
    }
}
