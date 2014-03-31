#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) {long long c=a;a=b;b=c;}
int total=0;
long long heap[20010];
void up(int t)
{
    int p;
    while (t>1)
    {
        //printf("up:%d:%lld\n",t,heap[t]);
        p=t >>1;
        if (heap[t]<heap[p])
        {
            swap(heap[t],heap[p]);
            t=p;
        }
        else break;
    }
}
void down(int t)
{
    int p;
    while ((t<<1)<=total)
    {
        //printf("down:%d:%lld\n",t,heap[t]);
        p=t <<1;
        if ((heap[p]>heap[p+1])&&(p<total)) p++;
        if (heap[t]>heap[p])
        {
            swap(heap[t],heap[p]);
            t=p;
        }
        else break;
    }
}
void insert(long long v)
{
    total++;
    heap[total]=v;
    up(total);
}
void del()
{
    heap[1]=heap[total];
    total--;
    down(1);
}
int main()
{
    int m,n,i;
    long long ans=0,tmp;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    for (i=1; i<=n; i++)
    {
        scanf("%d",&m);
        insert(m);
    }
    for (i=1; i<=n-1; i++)
    {
        tmp=heap[1];
        del();
        tmp+=heap[1];
        del();
        ans+=tmp;
        insert(tmp);
    }
    printf("%lld\n",ans);
    return 0;
}
