#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int sol[10000];
int main()
{
    int price[6] = {10,50,100,500,1000,5000};
    int pos[6];
    //int sol[1000];//,sol2[1000];
    int a,t;
    while(scanf("%d",&a) != EOF)
    {
        pos[0] = a;
        int sum = 0;
        sum += pos[0] * price[0];
        t = 0;
        for(int i = 1;i < 6;i++)
        {
            scanf("%d",&pos[i]);
            sum += pos[i] * price[i];
        }
        int p;
        scanf("%d",&p);
        sol[t++] = sum / p;
        for(int i = 0;i < 6;i++)
        {
            if(pos[i] > 0)
            {
                int temp = (sum - price[i]) / p;
                for(int j = temp + 1;j < sol[0];j++)
                    sol[t++] = j;
                break;
            }
        }
        sort(sol,sol + t);
        printf("%d\n",t);
        for(int i = 0;i < t;i++)
        {
            if(i == 0)
                printf("%d",sol[i]);
            else
                printf(" %d",sol[i]);
        }
        printf("\n");
    }
}