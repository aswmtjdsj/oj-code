#include<stdio.h>
#include<stdlib.h>

void countOil(char [][100],int ,int  );
void try(char [][100],int ,int ,int ,int );
int line[8]={1,1,1,0,0,-1,-1,-1},cow[8]={1,0,-1,1,-1,1,0,-1};

main()
{
    int n,m,i=0,p=0;
    scanf("%d%d",&n,&m);

    while(n!=0)
    {
        char a[100][100];
        for(i=0;i<=n-1;i++)
        {
            for(p=0;p<=m-1;p++)
                scanf(" %c",&a[i][p]);
        }
        countOil(a,n,m);
        scanf("%d%d",&n,&m);   
    }

    //system("Pause");
    return 0;
}

void countOil(char grid[][100],int n,int m)
{
    int i=0,p=0,num=0;
    for(i=0;i<=n-1;i++)
        for(p=0;p<=m-1;p++)
        {
            if(grid[i][p]=='@')
            {
                try(grid,n,m,i,p);
                num++;
            }
        }

    printf("%d\n",num);
}

void try(char grid[][100],int n,int m,int x,int y)
{
    int i,x1,y1;
    grid[x][y]='*';
    for(i=0;i<=7;i++)
    {
        x1=x+line[i];
        y1=y+cow[i];
        if(x1<=n-1&&x1>=0&&y1<=m-1&&y1>=0&&grid[x1][y1]=='@')
            try(grid,n,m,x1,y1);
    }
}
