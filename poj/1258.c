#include<stdio.h>
#include<stdlib.h>
#define maxlen 105

struct graph
{
    int vexnum;
    int arcs[maxlen][maxlen];
};

int prim(struct graph );

main()
{
    struct graph a;
    while(scanf("%d",&a.vexnum) == 1)
    {
        int i=0,p=0;
        for(i=0;i<=a.vexnum-1;i++)
            for(p=0;p<=a.vexnum-1;p++)
                scanf("%d",&(a.arcs[i][p]));
        printf("%d\n",prim(a));
    }
    return 0;
}

int prim(struct graph g)
{ 
    int   i,j,k,min,num=0; 
    int   lowcost[maxlen]; 
    int   closet[maxlen];
    for(i=1;i <g.vexnum;i++) 
    { 
        lowcost[i]=g.arcs[0][i]; 
        closet[i]=0; 
    } 
    closet[0]=1;    
    for(i=1;i <g.vexnum;i++) 
    { 
        min=10000000;
        for(j=1;j <g.vexnum;j++) 
            if(lowcost[j] <min&&closet[j]==0) 
            { 
                min=lowcost[j]; 
                k=j; 
            } 
        num+=min;
        closet[k]=1; 
        for(j=1;j <g.vexnum;j++) 
            if(g.arcs[k][j] <lowcost[j]&&closet[j]==0) 
            { 
                lowcost[j]=g.arcs[k][j]; 
            } 
    } 
    return num;
}
