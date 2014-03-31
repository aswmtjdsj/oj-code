#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char str[55];
    int t;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
    {
        printf("String #%d\n",i);
        scanf("%s",str);
        int l = strlen(str);
        for(int j = 0;j < l;j++)
            printf("%c",(str[j] == 'Z')?'A' : str[j] + 1);
        printf("\n\n");
    }
}
