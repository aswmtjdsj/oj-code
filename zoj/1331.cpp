#include <iostream>
#include <cstdio>
using namespace std;
inline int tri(int x)
{
    return x * x * x;
}
int main()
{
    int a ,b,c,ans,ans1,ans2;
    for(int n = 1;n <= 200;n++)
    {
        ans = tri(n);
        for(a = 2;a < n;a++)
        {
            ans1 = tri(a);
            for(b = a;b < n;b++)
            {
                ans2 = tri(b);
                for(c = b;c < n;c++)
                    if(ans1 + ans2 + tri(c) == ans)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",n,a,b,c);
            }
        }
    }
}
