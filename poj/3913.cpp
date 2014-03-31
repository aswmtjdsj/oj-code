#include <iostream>
#include <cstdio>
using namespace std;
#define od "Ordered"
#define un "Unordered"
int main()
{
    int n;
    scanf("%d",&n);
    puts("Gnomes:");
    for(int i = 0;i < n;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if(a > b && b > c)
            puts(od);
        else if(a < b && b < c)
            puts(od);
        else
            puts(un);
    }
}
