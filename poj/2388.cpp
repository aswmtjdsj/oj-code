#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
main()
{
    //   freopen("2388.in","r",stdin);
    //  freopen("2388c.out","w",stdout);
    int n,arr[10050];
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0 ;i < n;i++)
            scanf("%d",&arr[i]);
        sort(arr,arr + n);
        /*   for(int i = 0;i < n;i++)
             printf("%d\n",arr[i]);
             printf("\n");*/
        printf("%d\n",arr[(n - 1) / 2]);
    }
}
