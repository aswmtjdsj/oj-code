/*
 * POJ 3094 Quicksum
 * coded by [BUPT]-aswmtjdsj
 * time:2010-07-19
 * @915
 * */
#include <iostream>
using namespace std;
int main()
{
    char input[300];
    cin.getline(input,300);
    while(strcmp(input,"#"))
    {
        int sum=0,len;
        len=strlen(input);
        for(int i=0;i<len;i++)
        {
            if(input[i]!=' ')
                sum+=(i+1)*(input[i]-'A'+1);
        }
        printf("%d\n",sum);
        cin.getline(input,300);
    }
    //system("pause");
    return 0;
}
