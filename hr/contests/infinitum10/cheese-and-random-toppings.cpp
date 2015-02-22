#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long LL;
const int maxn=200003;
int ans,n,k,p,T,F[maxn],c[maxn],a[maxn],t[maxn],tot;
int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}

int calc()
{
    F[0]=1,F[1]=0;
    for(int i=2;i<2*p;i++)F[i]=LL(i-1)*(F[i-1]+F[i-2])%p;
    return F[(n-k)%(2*p)];
}

void init(int p)
{
    tot=0;
    int pp=p;
    for(int i=2;i*i<=pp;i++)
    {
        if(p%i!=0)continue;
        a[++tot]=i,c[tot]=1,t[tot]=0;
        while(p%i==0)c[tot]*=i,p/=i,t[tot]++;
    }
    if(p!=1)a[++tot]=p,c[tot]=p,t[tot]=1;
}

void ext_gcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x=1,y=0;
        return;
    }
    ext_gcd(b,a%b,x,y);
    LL tp=x;
    x=y;
    y=tp-a/b*y;
}

LL Pow(LL a,LL b,int P)
{
    LL res=1;
    for(;b>0;b/=2)
    {
        if(b%2==1)res=res*a%p;
        a=a*a%p;
    }
    return res;
}

LL calc(int n,int p,int _p)
{
    if(n<_p)return F[n];
    return (LL(F[n%p])*calc(n/_p,p,_p)%p*Pow(F[p-1],n/p,p)%p+p)%p;
}

int count(int n,int p)
{
    if(n<p)return 0;
    return n/p+count(n/p,p);
}

int C(int n,int k,int p,int _p,int t)
{
    F[0]=1;
    for(int i=1;i<=p;i++)
        if(i%_p!=0)F[i]=LL(F[i-1])*i%p;else F[i]=F[i-1];
    int t3=count(n,_p)-count(k,_p)-count(n-k,_p);
    if(t3>=t)return 0;
    LL t1=calc(n,p,_p),t2=calc(k,p,_p)*calc(n-k,p,_p)%p;
    LL x,y;
    ext_gcd(t2,p,x,y);
    return (t1*x%p*Pow(_p,t3,p)+p)%p;
}

int work()
{
    int res=0,tp,inv;
    LL x,y;
    for(int i=1;i<=tot;i++)
    {
        ext_gcd(p/c[i],c[i],x,y);
        tp=C(n,k,c[i],a[i],t[i]);
        res+=x*tp*(p/c[i])%p,res%=p;
    }
    return (res+p)%p;
}

int main()
{
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        cin >> n >> k >> p;
        // cout << "biu" << endl;
        init(p);
        ans=/*LL(ans)**/work()%p;
        //printf("Case %d: %d\n",i,ans);
        cout << ans << endl;
    }
    return 0;
}