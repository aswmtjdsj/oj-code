#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 100005
int num[maxn], sum, n;
bool cmp(int a, int b){return a > b;}

int oldcnt[11], nowcnt[11];

int main()
{
    cin >> n;
    sum = 0;
    memset(oldcnt, 0, sizeof(oldcnt));
    memset(nowcnt, 0, sizeof(nowcnt));
    for(int i = 0;i < n;i++)
    {
        cin >> num[i];
        sum += num[i];
        oldcnt[num[i]]++;
    }
    sort(num, num + n, cmp);
    bool zero = 0;
    for(int i = n - 1;i >= 0;i--)
    {
        if(num[i] == 0)
        {
            zero = 1;
            break;
        }
        if(num[i] == 1)
            break;
    }
    bool ok = 0;
    int mark = -1;
    int cnt = 0;
    if(sum % 3 == 0)
        ok = 1;
    if(!ok)
    {
        for(int i = 0;i < 10;i++)
            if((sum - i) % 3 == 0 && oldcnt[i] > 0)
            {
                ok = 1;
                oldcnt[i] --;
                break;
            }
    }
    if(!ok)
    {
        for(int i = 0;i < 10;i++)
            for(int j = 0;j < 10;j++)
            {
                if((sum - i - j) % 3 == 0 && oldcnt[i] > 0 && oldcnt[j] > 0)
                {
                    oldcnt[i]--;
                    oldcnt[j]--;
                    ok = 1;
                    break;
                }
            }
    }
    bool allzero = 1;
    for(int i = 1;i < 10;i++)
        if(oldcnt[i] > 0)
        {
            allzero = 0;
            break;
        }
    if(!ok || !zero)
        puts("-1");
    else if(allzero)
        puts("0");
    else
    {
        for(int i = 9;i >= 0;i--)
            for(int j = 0;j < oldcnt[i];j++)
                printf("%d", i);
        puts("");
    }
    //system("pause");
}
