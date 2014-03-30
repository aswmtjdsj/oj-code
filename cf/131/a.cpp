#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	char str[105];
	while(scanf("%s",str) == 1)
	{
		int l = strlen(str);
		int cnt = 0;
		for(int i = 0;i < l;i++)
			if(isupper(str[i]))
				cnt++;
		if(cnt == l)
			for(int i = 0;i < l;i++)
				str[i] = tolower(str[i]);
		else
		{
			if(cnt == l - 1 && islower(str[0]))
			{
				str[0] = toupper(str[0]);
				for(int i = 1;i < l;i++)
					str[i] = tolower(str[i]);
			}
		}
		printf("%s\n",str);
	}
}
