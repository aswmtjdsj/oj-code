#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int hashsize = 16000057;
struct hash
{
    int v,next;
    hash(){}
    hash(int a,int b):v(a),next(b){}
} table[hashsize + 5],ls[hashsize + 100];
int n,nc,tot;
bool insert(int x)
{
    int h = x % hashsize;
    int k = table[h].next;
    bool flag = true;
    for(;k != 0;)
    {
        if(ls[k].v == x)
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        ls[tot] = hash(x,table[h].next);
        table[h].next = tot++;
    }
    return flag;
    //ls[tot] = hash(x,table[h].next);
    //table[h].next = tot++;
}
int q[1000],head,tail,qsize = 500;
int co[100];
int now;
int main()
{
    int ans = 0;
    tot = 1;
    head = tail = 0;
    scanf("%d %d",&n,&nc);
    now = 1;
    getchar();
    while(1)
    {
        char a = getchar();
        if(a == '\n' || a == '\r' || a == '\0')
            break;
        int temp;
        if(a >= 'a')
        {
            if(co[a - 'a'] == 0)
                co[a - 'a'] = now++;
            temp = co[a - 'a'];
        }
        else
        {
            if(co[a - 'A' + 30] == 0)
                co[a - 'A' + 30] = now++;
            temp = co[a - 'A' + 30];
        }
        q[head] = temp;
        head ++;
        head %= 500;
        int l;
        if(head > tail)
            l = head - tail;
        else
            l = head + 500 - tail;
        if(l == n)
        {
            int sum,step,ncc = 1;
            for(sum = 0,step = 1;step <= l;step++)
            {
                int tmp = tail + step - 1;
                tmp %= qsize;
                sum += q[tmp] * ncc;
                ncc *= nc;
            }
            bool flag = insert(sum);
            if(flag)
                ans++;
            tail++;
            tail %= qsize;
        }
    }
    printf("%d\n",ans);
}
