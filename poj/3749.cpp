#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include <string>
#include <cctype>
int main()
{
    char opt[205];
    while(cin.getline(opt,205))
    {
        if(strcmp(opt,"START") == 0 || strcmp(opt,"END") == 0)
            continue;
        if(strcmp(opt,"ENDOFINPUT") == 0)
            break;
        int l = strlen(opt);
        for(int i = 0;i < l;i++)
        {
            if(isupper(opt[i]))
            {
                opt[i] -= 5;
                if(opt[i] < 'A')
                    opt[i] += 26;
            }
            printf("%c",opt[i]);
        }
        cout << endl;
    }
}
