#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    char a[5],b[5];
    for(int i = 0;i < n;i++)
    {
        int at = 0,bt = 0;
        scanf("%s %s",a,b);
        for(int j = 0;j < 4;j++)
        {
            for(int k = 0;k < 4;k++)
            {
                if(b[j] == a[k])
                {
                    //cout << b[j] << a[k] << endl;
                    if(j == k)
                        at++;
                    else
                        bt++;
                }
            }
        }
        printf("%dA%dB\n",at,bt);
    }
}
