#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int cow[20005];
int main()
{
    int n,l;
    scanf("%d %d",&n,&l);
    for(int i = 0;i < n;i++)
        scanf("%d",&cow[i]);
    sort(cow,cow + n);
    int j = n - 1;
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        while(cow[i] + cow[j] > l)
            j--;
        if(i >= j)
            break;
        ans += j - i;
    }
    printf("%d\n",ans);
}
