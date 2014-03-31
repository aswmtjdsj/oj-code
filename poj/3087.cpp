#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#define maxn 105
using namespace std;
char s1[maxn],s2[maxn],s[maxn * 2],ts[maxn * 2];
int gao()
{
    int l;
    scanf("%d",&l);
    scanf(" %s %s %s",s1,s2,s);
    map<string,bool> M;
    int step = 0;
    bool mark = false;
    while(1)
    {
        int c = 0;
        for(int i = 0;i < l;i++)
        {
            ts[c++] = s2[i];
            ts[c++] = s1[i];
        }
        ts[c] = 0;
        step++;
        if(M[string(ts)])
            break;
        else
            M[string(ts)] = true;
        if(strcmp(ts,s) == 0)
        {   
            mark = true;
            break;
        }
        strncpy(s1,ts,l);
        strncpy(s2,ts + l,l);
    }
    return mark?step:-1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i = 1;i <= t;i++)
        printf("%d %d\n",i,gao());
}
