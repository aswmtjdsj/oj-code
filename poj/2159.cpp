/*
 * POJ 2159 Ancient Cipher
 * coded by [BUPT]-aswmtjdsj
 * time:2010-07-19
 * @915
 * */
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#define eps 1e-7
#define MAX 1<<30
using namespace std;
typedef long long ll;
void qsort(int *arr,int p,int r)
{
    if(p<r)
    {  int x,i,j,q;
        q = rand()%(r-p+1);
        q += p;
        swap(arr[q],arr[r]);
        x=arr[r];
        i=p-1;
        for(j = p;j <= r-1;j++)
        {
            if(arr[j] <= x)
            {
                i++;              
                swap(arr[j],arr[i]); 
            }
        }
        swap(arr[r],arr[i+1]);
        q=i+1;
        qsort(arr,p,q-1);
        qsort(arr,q+1,r);
    } 
} 
int main()
{
    char final[105],origin[105];
    while(cin>>final)
    {
        cin>>origin;
        int a[30],b[30],i;
        for(i=0;i<30;i++)
            a[i]=b[i]=0;
        for(i=0;i<strlen(final);i++)
        {
            a[final[i]-'A']++;
            b[origin[i]-'A']++;
        }
        for(i=0;i<26;i++)
        {
            //  printf("%d %d\n",a[i],b[i]);
            //   if(a[i]!=b[i])
            //   break;
        }
        qsort(a,0,25);
        qsort(b,0,25);
        for(i=0;i<26;i++)
        {
            //  printf("%d %d\n",a[i],b[i]);
            if(a[i]!=b[i])
                break;
        }
        if(i==26)
            printf("YES\n");
        else
            printf("NO\n");
    }
    //  system("pause");
    return 0;
}
