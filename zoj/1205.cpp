#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[105],b[105],c[105];
int con(char a)
{
    if(a >= '0' && a <= '9')
        return  a - '0';
    if(a >= 'a' && a <= 'j')
        return a - 'a' + 10;
}
char to(int a)
{
    if(a < 10)
        return a + '0';
    else
        return a - 10 + 'a';
}
int main()
{
    while(scanf("%s %s",a,b) == 2)
    {
        memset(c,0,sizeof(c));
        int l1 = strlen(a),l2 = strlen(b),l = min(l1,l2);
        int now  = 0,res = 0,up = 0,t1 = l1 - 1,t2 = l2 - 1;
        while(l > 0)
        {
            c[now] = up;
            up = con(a[t1]) + con(b[t2]) + c[now];
            res = up % 20;
            up /= 20;
            c[now] = res;
            t1--;
            l--;
            t2--;
            now++;
        }
        while(t1 >= 0)
        {
            c[now] = up;
            up = con(a[t1]) + c[now];
            res = up % 20;
            up /= 20;
            c[now] = res;
            t1--;
            now++;
        }
        while(t2 >= 0)
        {
            c[now] = up;
            up = con(b[t2]) + c[now];
            res = up % 20;
            up /= 20;
            c[now] = res;
            t2--;
            now++;
        }
        c[now] = up;
        if(c[now] != 0)
            printf("%c",to(c[now]));
        for(int i = now - 1;i >= 0;i--)
            printf("%c",to(c[i]));
        printf("\n");
    }
}
