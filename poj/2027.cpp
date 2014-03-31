#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t) != EOF)
    {
        for(int i = 0;i < t;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            if(a >= b)
                printf("MMM BRAINS\n");
            else
                printf("NO BRAINS\n");}
    }
}
