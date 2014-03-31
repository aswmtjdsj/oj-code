#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool J(char a)
{
    return ((a <= 'z' && a >= 'a') || (a <= 'Z' && a >= 'A'));
}
int main()
{
    //freopen("za.in","r",stdin);
    int i,j;
    i = j = -1;
    char a,b;
    while((a = getchar()) != EOF)
    {
        if(J(a))
        {
            if(i == -1)
            {
                i = j = 0;
                putchar(a);
            }
            else
            {
                j++;
            }
            b = a;
        }
        else
        {
            if(j == 0)
            {
                i = j = -1;
            }
            else if(j > 0)
            {
                if(j - i > 1)
                    cout << j - i - 1;
                putchar(b);
                j = i = -1;
            }
            putchar(a);
        }
    }
}
