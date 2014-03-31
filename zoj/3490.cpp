#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char str[200],now[200],temp[200];
int n,t;
bool check(char a)
{
    return ('0' <= a && a <= '9') || ('a' <= a && a <= 'z') || ('A' <= a && a <= 'Z');
}
void solve()
{
    int l;
    int mark;
    strcpy(now,str);
    for(int i = 1;i <= n;i++)
    {
        l = strlen(now);
        mark = l;
        for(int j = l - 1;j >= 0;j--)
            if(check(now[j]))
            {
                mark = j;
                break;
            }
        if(mark == l)
            mark = l - 1;
        //cout << now[mark] << endl;
        int ar;
        int mod;
        int add = 1;
        ar = add;
        while(ar)
        {
            add = ar;
            if(isdigit(now[mark]))
            {
                mod = now[mark] - '0' + add;
                if(mod > 9)
                {
                    ar = 1;
                    mod = 0;
                }
                else
                    ar = 0;
                now[mark] = '0' + mod;
                if(ar)
                {
                    int fuck = mark;
                    for(int i = mark - 1;i >= 0;i--)
                        if(check(now[i]))
                        {
                            fuck = i;
                            break;
                        }
                    if(fuck != mark)
                    {
                        mark = fuck;
                        continue;
                    }
                    else
                    {
                        strncpy(temp,now,mark);
                        temp[mark] = '1';
                        temp[mark + 1] = 0;
                        strcat(temp,&now[mark]);
                        strcpy(now,temp);
                        break;
                    }
                }
            }
            else if(isupper(now[mark]))
            {
                mod = now[mark] - 'A' + add;
                if(mod > 25)
                {
                    ar = 1;
                    mod = 0;
                }
                else
                    ar = 0;
                now[mark] = 'A' + mod;
                if(ar)
                {
                    int fuck = mark;
                    for(int i = mark - 1;i >= 0;i--)
                        if(check(now[i]))
                        {
                            fuck = i;
                            break;
                        }
                    /*if(now[mark] == '.')
                      cout << mark << endl;*/
                    if(fuck != mark)
                    {
                        mark = fuck;
                        continue;
                    }
                    else
                    {
                        strncpy(temp,now,mark);
                        temp[mark] = 'A';
                        temp[mark + 1] = 0;
                        strcat(temp,&now[mark]);
                        strcpy(now,temp);
                        break;
                    }
                }
            }
            else if(islower(now[mark]))
            {
                mod = now[mark] - 'a' + add;
                if(mod > 25)
                {
                    ar = 1;
                    mod = 0;
                }
                else
                    ar = 0;
                now[mark] = 'a' + mod;
                if(ar)
                {
                    int fuck = mark;
                    for(int i = mark - 1;i >= 0;i--)
                        if(check(now[i]))
                        {
                            fuck = i;
                            break;
                        }
                    if(fuck != mark)
                    {
                        mark = fuck;
                        continue;
                    }
                    else
                    {
                        strncpy(temp,now,mark);
                        temp[mark] = 'a';
                        temp[mark + 1] = 0;
                        strcat(temp,&now[mark]);
                        strcpy(now,temp);
                        break;
                    }
                }
            }
            else
            {
                now[mark] += add;
                break;
            }
        }
        cout << now << endl;
    }
}
int main()
{
    scanf("%d",&t);
    for(int i = 0;i < t;i++)
    {
        scanf("%s %d",str,&n);
        solve();
        puts("");
    }
}
