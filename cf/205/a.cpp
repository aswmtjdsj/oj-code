#include <iostream>
#include <cstdio>
using namespace std;

#define maxn 100005
int a[maxn];
int main()
{
    int n, ans = 0, value = 1000000005, cnt = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        if(value > a[i])
        {
            value = a[i];
            ans = i + 1;
        }
    }
    for(int i = 0;i < n;i++)
    {
        if(value == a[i])
        {
            cnt++;
        }
    }
    if(cnt > 1)
        puts("Still Rozdil");
    else
        printf("%d\n",ans);
}
