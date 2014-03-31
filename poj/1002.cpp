#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int cor[30];
struct list
{
    char value[10];
    bool friend operator <(const list &a,const list &b)
    {
        return strcmp(a.value,b.value) < 0;
    }
}l[100005];
void solve(int n)
{
    int t = 0;
    cor['A' - 'A'] = cor['B' - 'A'] = cor['C' - 'A'] = 2;
    cor['D' - 'A'] = cor['E' - 'A'] = cor['F' - 'A'] = 3;
    cor['G' - 'A'] = cor['H' - 'A'] = cor['I' - 'A'] = 4;
    cor['J' - 'A'] = cor['K' - 'A'] = cor['L' - 'A'] = 5;
    cor['M' - 'A'] = cor['N' - 'A'] = cor['O' - 'A'] = 6;
    cor['P' - 'A'] = cor['R' - 'A'] = cor['S' - 'A'] = 7;
    cor['T' - 'A'] = cor['U' - 'A'] = cor['V' - 'A'] = 8;
    cor['W' - 'A'] = cor['X' - 'A'] = cor['Y' - 'A'] = 9;
    char str[50];
    for(int i = 0;i < n;i++)
    {
        scanf("%s",str);
        int temp = 0;
        for(int j = 0;j < strlen(str);j++)
        {
            if(isdigit(str[j]))
                l[i].value[temp++] = str[j];
            else if(str[j] >= 'A' && str[j] <= 'Z')
                l[i].value[temp++] = '0' + cor[str[j] - 'A'];
            if(temp == 3)
                l[i].value[temp++] = '-';
        }
        l[i].value[temp] = 0;
    }
    //for(int i = 0;i < n;i++)
    //  //  printf("%s\n",l[i].value);
    sort(l,l + n);

    t = 1;
    bool mark = false;
    for(int i = 0;i < n - 1;i++)
    {
        if(!strcmp(l[i].value,l[i + 1].value))
        {
            t++;
            mark = true;
        }
        else
        {
            if(t > 1)
                printf("%s %d\n",l[i].value,t);
            t = 1;
        }
    }
    if(!strcmp(l[n - 1].value,l[n - 2].value))
        printf("%s %d\n",l[n - 1].value,t);
    if(!mark)
        printf("No duplicates.\n");
}
int main()
{
    //freopen("1155.in","r",stdin);
    int t;
    while(scanf("%d",&t) == 1)
        solve(t);
}
