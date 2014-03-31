#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct list
{
    char str[8];
    int hash,l;
    int read()
    {
        int in = scanf("%s",str);
        l = strlen(str);
        hash = 0;
        for(int i = 0;i < l;i++)
            hash += str[i] - 'a' + 1;
        return in;
    }
    bool friend operator < (list a,list b)
    {
        return (a.hash < b.hash) || (a.hash == b.hash && strcmp(a.str,b.str)< 0);
    }
}ls[105];
int t;
int bin(int x)
{
    int lo = 0,hi = t - 1,mid = (lo + hi) >> 1;
    while(lo < hi)
    {
        mid = (lo + hi) >> 1;
        if(ls[mid].hash < x)
            lo = mid + 1;
        else
            hi = mid;
    }
    if(ls[mid].hash == x)
        return mid;
    return mid + 1;
}
int main()
{
    t = 0;
    while(ls[t].read() == 1)
    {
        if(ls[t].str[0] == 'X')
            break;
        t++;
    }
    sort(ls,ls + t);
    char opt[8];
    while(scanf("%s",opt) == 1)
    {
        if(opt[0] == 'X')
            break;
        int h = 0,len = strlen(opt);
        for(int i = 0;i < len;i++)
            h += opt[i] - 'a' + 1;
        int pos = bin(h);
        bool ok = false;
        for(int i = pos;i < t;i++)
        {
            if(ls[i].hash != h)
            {
                if(!ok)
                    printf("NOT A VALID WORD\n");
                break;
            }
            bool mark = false;
            char t1[10],t2[10];
            strcpy(t1,ls[i].str);
            strcpy(t2,opt);
            sort(t1,t1 + ls[i].l);
            sort(t2,t2 + len);
            if(strcmp(t1,t2) == 0)
                mark = true;
            if(mark)
            {
                ok = true;
                printf("%s\n",ls[i].str);
            }
        }
        printf("******\n");
    }
}
