#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	char str[102];
	cin >> str;
	char p[] = "hello";
	int m = 0;
	for(int i = 0;i < strlen(str);i++)
		if(str[i] == p[m])
			m++;
	if(m > 4)
		puts("YES");
	else
		puts("NO");
}
