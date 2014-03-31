/*
 * Coded by BUPT-[aswmtjdsj] @ Penalty
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int INF = 200000000;
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) + 1)
#define parent(x) ((x) >> 1)
#define maxv 2000
#define maxe (maxv * maxv)
#define sqr(x) ((x) * (x))
struct node
{
    int w,p;
    node(int a,int b):p(a),w(b){}
    node(){}
    bool friend operator < ( const node &a,const node &b)
    {
        return a.w < b.w;
    }
    void operator = (const node &b)
    {
        w = b.w;
        p = b.p;
    }
};
struct heap
{
    int size;
    node it[maxv + 5];
    int hash[maxv + 5];
    heap(int n)
    {
        size = 0;
        for(int i = 1;i <= n;i++)
            hash[i] = 0;
    }
    void down(int x)
    {
        int l = left(x),r = right(x),s;
        if(l <= size && it[l] < it[x])
            s = l;
        else
            s = x;
        if(r <= size && it[r] < it[s])
            s = r;
        if(s != x)
        {
            swap(hash[it[x].p],hash[it[s].p]);
            swap(it[x],it[s]);
            down(s);
        }
    }
    void up(int x)
    {
        int p = parent(x);
        while(p >= 1 && it[x] < it[p])
        {
            swap(hash[it[x].p],hash[it[p].p]);
            swap(it[x],it[p]);
            x = p;
            p = parent(x);
        }
    }
    void push(node a)
    {
        size++;
        it[size] = a;
        hash[a.p] = size;
        up(size);
    }
    node top()
    {
        return it[1];
    }
    void pop()
    {
        swap(hash[it[1].p],hash[it[size].p]);
        swap(it[1],it[size]);
        hash[it[size].p] = 0;
        size--;
        down(1);
    }
    void dec(int p,int w)
    {
        int x = hash[p];
        it[x].w = w;
        up(x);
    }
    bool nonempty()
    {
        return size;
    }
};
char str[maxv + 5][10];
int mat[maxv + 5][maxv + 5];
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        heap Q(n);
        for(int i = 1;i <= n;i++)
            scanf("%s",str[i]);
        for(int i = 1;i <= n;i++)
        {
            for(int j = i;j <= n;j++)
            {
                if(i == j)
                    mat[i][j] = 0;
                else
                {
                    int t = 0;
                    for(int k = 0;k < 7;k++)
                    {
                        if(str[i][k] != str[j][k])
                            t++;
                    }
                    mat[i][j] = mat[j][i] = t;
                }
            }
        }
        for(int i = 1;i <= n;i++)
        {
            node t(i,INF);
            if(i == 1)
                t.w = 0;
            Q.push(t);
        }
        int sum = 0;
        while(Q.nonempty())
        {
            //for(int i = 1;i <= Q.size;i++)
            //    printf("%d : %d %d \n",i,Q.it[i].p,Q.it[i].w);
            node u = Q.top();
            Q.pop();
            sum += u.w;
            for(int i = 1;i <= n;i++)
            {
                if(u.p != i && Q.hash[i] != 0 && mat[u.p][i] < Q.it[Q.hash[i]].w)
                    Q.dec(i,mat[u.p][i]);
            }
        }
        printf("The highest possible quality is 1/%d.\n",sum);
    }
}
