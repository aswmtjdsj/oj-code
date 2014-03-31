#include<stdio.h>
int n,m,a[100005];
bool judge(int mid){
    int group=1,sum=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i]<=mid)
            sum=sum+a[i];
        else{
            sum=a[i];
            group++;
        }
    }
    if(group>m)  return 1;
    else   return 0;
}
int main()
{
    int low=-1,high=0,mid;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        high=high+a[i];
        if(a[i]>low)
            low=a[i];
    }
    mid=(high+low)/2;
    while(low<high){
        if(judge(mid)==1)
            low=mid+1;
        else
            high=mid-1;
        mid=(high+low)/2;
    }
    printf("%d\n",mid);
}
