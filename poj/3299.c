#include <stdio.h>
#include <math.h>
int main()
{
    double dewpoint,e,h,temperature,humidex;
    char c1,c2;
    scanf(" %c",&c1);
    while(c1!='E')
    {
        if(c1=='T')
            scanf("%lf",&temperature);
        else if(c1=='D')
            scanf("%lf",&dewpoint);
        else
            scanf("%lf",&humidex);
        scanf(" %c",&c2);
        if(c2=='T')
            scanf("%lf",&temperature);
        else if(c2=='D')
            scanf("%lf",&dewpoint);
        else
            scanf("%lf",&humidex);
        if((c1=='T'&&c2=='D')||(c2=='T'&&c1=='D'))
        {
            e = 6.11* exp(5417.7530 *((1.0/273.16) - (1.0/(dewpoint+273.16))));

            h = (0.5555)* (e - 10.0);
            humidex = temperature + h ;
        }
        else if((c1=='T'&&c2=='H')||(c2=='T'&&c1=='H'))
        {
            h=humidex-temperature;
            e= h / 0.5555 + 10.0;
            dewpoint = 1.0/((1.0/273.16) - log(e/6.11)/5417.7530) - 273.16 ;
        }
        else
        {
            e = 6.11* exp(5417.7530 *((1.0/273.16) - (1.0/(dewpoint+273.16))));
            h = (0.5555)* (e - 10.0);
            temperature =humidex - h ;
        }
        printf("T %.1lf D %.1lf H %.1lf\n",temperature,dewpoint,humidex);
        scanf(" %c",&c1);
    }
    return 0;
}
