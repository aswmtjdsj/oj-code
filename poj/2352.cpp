#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 32005
int n,tr[maxn],cnt[maxn];
int bit(int x){return x & -x;}
void mod(int x,int val)
{
    for(int i = x;i <= maxn;i += bit(i))
        tr[i] += val;
}
int sum(int x)
{
    int ans = 0;
    for(int i = x;i > 0;i -= bit(i))
        ans += tr[i];
    return ans;
}
int main()
{
    scanf("%d",&n);
    //memset(tr,0,sizeof(tr));
    //memset(cnt,0,sizeof(cnt));
    for(int i = 0;i < n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        x++;
        cnt[sum(x)]++;
        //cout << (x - 1) << ' ' << sum(x) << endl;
        mod(x,1);
    }
    for(int i = 0;i < n;i++)
        printf("%d\n",cnt[i]);
}
