/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty in 608
 * */
/*
 * MIND if 'X' exists , 'X' must be in the last position otherwise -1 outputted
 * */
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char str[15];
    while(scanf("%s",str) != EOF)
    {
        int sum = 0;
        bool mark = false;
        int pos;
        for(int i = 0;i < 10;i++)
        {
            if(str[i] >= '0' && str[i] <= '9')
                sum +=( str[i] - '0') * (10 - i);
            if(str[i] == 'X')
                sum += 10 * (10 - i);
            if(str[i] == '?')
                pos = i;
        }
        for(int i = 0;i <= 10;i++)
        {
            if((sum + i * (10 - pos)) % 11 == 0)
            {
                mark = true;
                if(pos != 9)
                    if(i == 10)
                        mark = false;
                pos = i;
                break;
            }
        }
        if(mark)
        {
            if(pos != 10)
                printf("%d\n",pos);
            else
                printf("X\n");
        }
        else
            printf("-1\n");
    }
}
