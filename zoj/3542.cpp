#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#define PB push_back
using namespace std;
const int inf = ~0u >> 1;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x)
{
    return fabs(x) < eps ? 0:x < -eps?-1:1;
}
char str[5000];
int main()
{
    while(cin.getline(str,5000))
    {
        int l = strlen(str);
        int i = 0;
        char opt[20];
        int cnt = 0;
        while(1)
        {
            char row[5];
            sprintf(row,"%x",i);
            for(int j = 0;j < 4 - strlen(row);j++)
                putchar('0');
            printf("%s: ",row);
            bool mark = true;
            for(int j = 0;j < 16;j++)
            {
                opt[j] = mark?str[i]:-1;
                i++;
                if(i == l)
                    mark = false;
            }
            for(int j = 0;j < 16;j++)
            {
                if(opt[j] != -1)
                    printf("%x",opt[j]);
                else
                    printf("  ");
                if(j%2)
                    printf(" ");
            }
            for(int j = 0;j < 16;j++)
            {
                if(opt[j] == -1)
                    break;
                if(islower(opt[j]))
                    opt[j] = toupper(opt[j]);
                else if(isupper(opt[j]))
                    opt[j] = tolower(opt[j]);
                printf("%c",opt[j]);
            }
            puts("");
            if(!mark)
                break;
        }
    }
}
