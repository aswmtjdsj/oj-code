#include<stdio.h>
#include<string.h>
#define max(a,b) ((a>b)? a:b)
int a[105][105],dp[105][105],r,c;
int sousuo(int i,int j);
int main()
{
    int i,j,max;

    while(scanf("%d%d",&r,&c)==2)
    {memset(dp,-1,sizeof(dp));
        for(i=0;i<=r-1;i++)
            for(j=0;j<=c-1;j++){
                scanf("%d",&a[i][j]);

            }
        for(i=0;i<=r-1;i++){
            for(j=0;j<=c-1;j++)
                dp[i][j]=sousuo(i,j);//进行记忆化搜索
        }
        max=dp[0][0];
        for(i=0;i<=r-1;i++){
            for(j=0;j<=c-1;j++){
                if(max<dp[i][j])
                    max=dp[i][j];//找出最大值
            }
        }
        printf("%d\n",max);}
}


int sousuo(int i,int j){
    int aaa=0;
    if(dp[i][j]>=0)
        return dp[i][j];//已搜索过的直接返回
    if(i+1<=r-1&&a[i+1][j]<a[i][j])//找符合要求的最大路径
        aaa=max(aaa,sousuo(i+1,j));

    if(j+1<=c-1&&a[i][j+1]<a[i][j])
        aaa=max(aaa,sousuo(i,j+1));

    if(i-1>=0&&a[i-1][j]<a[i][j])
        aaa=max(aaa,sousuo(i-1,j));

    if(j-1>=0&&a[i][j-1]<a[i][j])
        aaa=max(aaa,sousuo(i,j-1));

    return dp[i][j] = aaa+1;//返回最大路径
}
