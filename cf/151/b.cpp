#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
int t;
#define maxn 102
struct record
{
	int n;
	string name;
	int a,b,c;
	record(){a = b = c = 0;}
}rec[maxn];
int main()
{
	cin >> t;
	int ma = 0,mb = 0, mc = 0;
	char str[10],nstr[10];
	for(int i = 0;i < t;i++)
	{
		scanf("%d",&rec[i].n);
		cin >> rec[i].name;
		for(int j = 0;j < rec[i].n;j++)
		{
			scanf("%s",str);
			int l = strlen(str);
			int o = 0;
			for(int k = 0;k < l;k++)
				if(str[k] != '-')
					nstr[o++] = str[k];
			nstr[o] = 0;
			//a
			bool mark = false;
			bool flag = true;
			for(int k = 0;k < strlen(nstr)-1;k++)
				if(nstr[k] != nstr[k+1])
				{
					flag = false;
					break;
				}
			if(flag)
			{
				rec[i].a++;
				mark = true;
			}
			//b
			flag = true;
			for(int k = 0;k < strlen(nstr)-1;k++)
				if(nstr[k] <= nstr[k+1])
				{
					flag = false;
					break;
				}
			if(flag)
			{
				rec[i].b++;
				mark = true;
			}
			if(!mark)
				rec[i].c++;
		}
		ma = max(ma, rec[i].a);
		mb = max(mb, rec[i].b);
		mc = max(mc, rec[i].c);
	}
	printf("If you want to call a taxi, you should call:");
	int temp, orz;
	temp = orz = 0;
	for(int i = 0;i < t;i++)
		if(rec[i].a == ma)
			temp++;
	for(int i = 0;i < t;i++)
		if(rec[i].a == ma)
		{
			orz++;
			cout << ' ' << rec[i].name << (orz == temp?'.':',');
		}
	puts("");
	printf("If you want to order a pizza, you should call:");
	temp = orz = 0;
	for(int i = 0;i < t;i++)
		if(rec[i].b == mb)
			temp++;
	for(int i = 0;i < t;i++)
		if(rec[i].b == mb)
		{
			orz++;
			cout << ' ' << rec[i].name << (orz == temp?'.':',');
		}
	puts("");
	printf("If you want to go to a cafe with a wonderful girl, you should call:");
	temp = orz = 0;
	for(int i = 0;i < t;i++)
		if(rec[i].c == mc)
			temp++;
	for(int i = 0;i < t;i++)
		if(rec[i].c == mc)
		{
			orz++;
			cout << ' ' << rec[i].name << (orz == temp?'.':',');
		}
	puts("");
}
