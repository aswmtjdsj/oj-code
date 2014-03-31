#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
#define SIZE 100010
long long f(long long a)
{
    return a>0?a:-a;
}
typedef struct E{
    int to,next;
}E;
E edge[SIZE*2];
int v[SIZE];
long long num[SIZE];
long long sum;
bool vis[SIZE];
long long dfs(int x,int par)
{
    long long ans=sum;
    vis[x]=true;
    int i;

    for(i=v[x];i!=-1;i=edge[i].next){
        if(vis[edge[i].to]==false)
            ans=min(ans,dfs(edge[i].to,x));
    }
    for(i=v[x];i!=-1;i=edge[i].next){
        if(edge[i].to!=par)
            num[x]+=num[edge[i].to];
    }
    ans=min(ans,f(sum-2*num[x]));
    //  printf("%d %lld\n",x,ans);
    return ans;
}

long long dp(int n)
{
    int i,j;
    long long ans;
    sum=0;
    for(i=1;i<=n;i++)
        sum+=num[i];
    memset(vis,0,sizeof(vis));
    ans=min(sum,dfs(1,-1));
    return ans;
}

int main()
{
    int n,m;
    int i,j;
    int a,b;
    int cs=0;

    while(scanf("%d %d",&n,&m)==2&&(n||m)){
        for(i=1;i<=n;i++)
            scanf("%lld",&num[i]);
        memset(v,-1,sizeof(v));
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            edge[i*2-1].to=a;
            edge[i*2-1].next=v[b];
            v[b]=i*2-1;
            edge[i*2].to=b;
            edge[i*2].next=v[a];
            v[a]=i*2;
        }
        printf("Case %d: %lld\n",++cs,dp(n));
    }
    return 0;
}
