#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 220000;

int a[1200][1200],b[1200][1200],c[1200][1200];
int p1[1200],p2[1200],p3[1200];
int n,m,k;

int cal(int x,int y){
    int ret=0;
    for (int i=1;i<=m;++i)
        ret+=a[x][i]*b[i][y];
    return ret;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
    for (int i=1;i<=m;++i)
        for (int j=1;j<=k;++j)
            scanf("%d",&b[i][j]);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=k;++j)
            scanf("%d",&c[i][j]);

    memset(p1,0,sizeof(p1));
    memset(p2,0,sizeof(p2));
    memset(p3,0,sizeof(p3));
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            p1[j]+=a[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=k;++j)
            p2[j]+=c[i][j];
    for (int i=1;i<=k;++i)
        for (int j=1;j<=m;++j)
            p3[i]+=p1[j]*b[j][i];
    int x=-1,y=-1;
    for (int i=1;i<=k;++i)
        if (p2[i]!=p3[i]) y=i;

    if (y==-1){
        puts("Yes");
        return 0;
    }

    memset(p1,0,sizeof(p1));
    memset(p2,0,sizeof(p2));
    memset(p3,0,sizeof(p3));
    for (int i=1;i<=m;++i)
        for (int j=1;j<=k;++j)
            p1[i]+=b[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=k;++j)
            p2[i]+=c[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            p3[i]+=p1[j]*a[i][j];
    for (int i=1;i<=n;++i)
        if (p2[i]!=p3[i]) x=i;

    if (x==-1){
        puts("Yes");
        return 0;
    }
    printf("No\n%d %d\n%d\n",x,y,cal(x,y));
    return 0;
}
