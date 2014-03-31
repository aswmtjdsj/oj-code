#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000];
void reverse(int i,int j)
{
    if(i >= j)
        return ;
    while(i < j)
    {
        swap(str[i],str[j]);
        i++;
        j--;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
    {
        int n;
        scanf("%d",&n);
        cin.getline(str,1000);
        for(int j = 0;j < n;j++)
        {
            cin.getline(str,1000);
            int p = 0,q = 0;
            int l = strlen(str);
            while(q < l)
            {
                if(str[q] == ' ')
                {
                    reverse(p,q - 1);
                    p = q + 1;
                }
                q++;
            }
            reverse(p,l - 1);
            printf("%s\n",str);
        }
        if(i != t - 1)
            printf("\n");
    }
}
