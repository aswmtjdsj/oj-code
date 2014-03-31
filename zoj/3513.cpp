#include <iostream>
#include <cstring>
#include <map>
#include <cstdio>
using namespace std;
int main()
{
    int n,m,cas = 1;
    while(scanf("%d %d",&n,&m) == 2)
    {
        map <pair<int,int> ,int> M;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                int times;
                if(i == j)
                    M[make_pair(i,j)] = 1;
                else if(i > j)
                {
                    times = i / j;
                    bool flag = true;
                    for(int k = i - times * j;k < i;k += j)
                    {
                        if(M[make_pair(k,j)] == 1)
                        {
                            flag = false;
                            M[make_pair(i,j)] = 2;
                            break;
                        }
                    }
                    if(flag)
                        M[make_pair(i,j)] = 1;
                }
                else
                {
                    times = j / i;
                    bool flag = true;
                    for(int k = j - times * i;k < j;k += i)
                    {
                        if(M[make_pair(i,k)] == 1)
                        {
                            flag = false;
                            M[make_pair(i,j)] = 2;
                            break;
                        }
                    }
                    if(flag)
                        M[make_pair(i,j)] = 1;
                }
            }
        }
        printf("Case #%d:\n",cas++);
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
                printf("%c",(M[make_pair(i,j)] == 1)?'P':'H');
            puts("");
        }
        M.clear();
    }
}
