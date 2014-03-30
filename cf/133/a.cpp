#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	string opt;
	while(cin >> opt)
	{
		string a = "H",b = "Q",c = "9";
		int ans = opt.find(a);
		if(ans == -1)
			ans = opt.find(b);
		if(ans == -1)
			ans = opt.find(c);
		puts(ans == -1?"NO":"YES");
	}
}
