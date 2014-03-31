#include <iostream>
#include <cstdio>
using namespace std;
int h[55];
int main()
{
    int n,avg,t = 1;
    while(scanf("%d",&n) == 1 && n)
    {
        int sum=  0;
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&h[i]);
            sum += h[i];
        }
        avg = sum / n;
        int ans = 0;
        for(int i = 0;i < n;i++)
            ans += (h[i] > avg) ? (h[i] - avg) : 0;
        printf("Set #%d\n",t++);
        printf("The minimum number of moves is %d.\n\n",ans);
    }
}
