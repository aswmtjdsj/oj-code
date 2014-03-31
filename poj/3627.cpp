#include <iostream>
#include <cstdio>
using namespace std;
#include <algorithm>
int a[20005];
int main()
{
    int n,b;
    cin >> n >> b;
    for(int i = 0;i <n;i++)
        scanf("%d",&a[i]);
    sort(a,a + n);
    int i;
    for(i = n - 1;i>=0;i--)
    {
        b -= a[i];
        if(b <= 0)
            break;
    }
    printf("%d\n",n - i);
}
