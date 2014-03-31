#include <iostream>
#include <cstdio>
#include <cstring>
#define ac "Accepted"
#define wa "Wrong Answer"
using namespace std;
char str[105];
int z[105],j[105];
int cntz,cntj;
int main()
{
    while(scanf("%s",str) == 1)
    {
        //cout << str << endl;
        cntz = cntj = 0;
        int l = strlen(str);
        for(int i = 0;i < l;i++)
        {
            if(str[i] == 'Z')
                z[++cntz] = i;
            if(str[i] == 'J')
                j[++cntj] = i;
        }
        if(cntj != cntz || cntz > 1 || cntj > 1)
        {
            puts(wa);
            continue;
        }
        int left = z[cntz],right = j[1];
        //cout << left << ' ' << right << endl;
        if(right < left + 2)
            puts(wa);
        else if(right == left + 2)
        {
            int total = 0;
            for(int i = right + 1;i < l;i++)
                if(str[i] == 'O')
                    total++;
            if(total < 1)
                puts(wa);
            else
                puts(ac);
        }
        else if(right > left + 2)
        {
            int total = 0;
            for(int i = right + 1;i < l;i++)
                if(str[i] == 'O')
                    total ++;
            if(total < 2)
                puts(wa);
            else
                puts(ac);
        }
    }
}
