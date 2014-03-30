#include <cstdio>
#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int hashsize = 100003;
int n;
int cnt;
int v[hashsize];
struct edge
{
	int next;
	char str[40];
	int times;
	edge(){}
	edge(int n,char *s, int t){next = n;strcpy(str,s);times = t;}
}e[hashsize];
void init()
{
	cnt = 0;
	memset(v, -1, sizeof(v));
}
int calc(char * s)
{
	int idx = 1;
	int l = strlen(s);
	int ans = 0;
	for(int i = 0;i < l;i++)
	{
		int det = isalpha(s[i])?s[i] - 'a':s[i] - '1' + 26;
		ans += det * idx;
		ans %= hashsize;
		idx = (idx * 36) % hashsize;
	}
	return ans;
}
void ins(char * s, int t)
{
	int h = calc(s);
	e[cnt] = edge(v[h], s, t);
	v[h] = cnt++;
}
int find(char * s)
{
	int h = calc(s);
	for(int k = v[h];~k;k = e[k].next)
	{
		if(strcmp(e[k].str, s) == 0)
		{
			return ++e[k].times;
		}
	}
	return -1;
}
char str[40];
int main()
{
	cin >> n;
	init();
	for(int i = 0;i < n;i++)
	{
		scanf("%s", str);
		int fuck = find(str);
		if(fuck == -1)
		{
			ins(str, 0);
			puts("OK");
		}
		else
		{
			char a[10];
			sprintf(a, "%d", fuck);
			strcat(str, a);
			puts(str);
		}
	}
}
