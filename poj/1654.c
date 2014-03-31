#include<stdio.h>
#include<stdlib.h>
#include<math.h>


main()
{
    int n,i=0,p=0,num,x1=0,y1=0,x2=0,y2=0;
    double total=0;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        scanf("%1d",&num);
        if(num==5)
        {
            printf("0\n");
            continue;
        }
        else switch(num)
        {
            case 1:
                y1=y2-1;
                x1=x2-1;
                break;
            case 2:
                y1=y2-1;
                x1=x2;
                break;
            case 3:
                y1=y2-1;
                x1=x2+1;
                break;
            case 4:
                y1=y2;
                x1=x2-1;
                break;
            case 6:
                y1=y2;
                x1=x2+1;
                break;
            case 7:
                y1=y2+1;
                x1=x2-1;
                break;
            case 8:
                y1=y2+1;
                x1=x2;
                break;
            case 9:
                y1=y2+1;
                x1=x2+1;
                break;
        }
        scanf("%1d",&num);
        while(num!=5)
        {
            x2=x1;
            y2=y1;
            switch(num)
            {
                case 1:
                    y1=y2-1;
                    x1=x2-1;
                    break;
                case 2:
                    y1=y2-1;
                    x1=x2;
                    break;
                case 3:
                    y1=y2-1;
                    x1=x2+1;
                    break;
                case 4:
                    y1=y2;
                    x1=x2-1;
                    break;
                case 6:
                    y1=y2;
                    x1=x2+1;
                    break;
                case 7:
                    y1=y2+1;
                    x1=x2-1;
                    break;
                case 8:
                    y1=y2+1;
                    x1=x2;
                    break;
                case 9:
                    y1=y2+1;
                    x1=x2+1;
                    break;

            }
            total+=(double)(x1*y2-x2*y1)/2;
            scanf("%1d",&num);
        }
        if((long long)fabs(total * 2.0) % 2ll == 0)
            printf("%.0f\n",fabs(total));
        else
            printf("%.1f\n",fabs(total));
        total=0;
        x1=0;
        y1=0;
        x2=0;
        y2=0;
    }

    return 0;
}
