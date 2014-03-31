/*
 * Coded by BUPT-[aswmtjdsj]@BSW in 915
 * TIME : 2010-09-16-15:43
 * */
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    public static void main(String args[])
    {
        BigDecimal n;
        int k;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNextBigDecimal())//读入
        { 
            n = cin.nextBigDecimal();
            k = cin.nextInt();
            BigDecimal kk,ans = BigDecimal.ONE;//赋初值
            kk = BigDecimal.valueOf(k);
            for(int i = 1;i <= k;i++)//模拟幂乘法
            {
                ans = ans.multiply(n);
            }
            char[] array = new char[10000];//转化字符数组
            String anss = ans.toPlainString();//转化字符串
            array = anss.toCharArray();
            boolean fuck = false;
            for(int i = 0;i <= array.length - 1;i++)//判断是否为整数，以防去掉整数的后缀0
            {
                if(array[i] == '.')
                    fuck = true;
            }
            if(fuck == false)
            {
                System.out.println(array);
                continue;
            }
            int i = array.length - 1;
            while(array[i] == '0')//去掉尾缀0
            {
                i--;
            }
            if(array[i] == '.')//如果是整数加一个小数点和一堆0，那么都去掉
                i--;
            for(int j = 0;j <= i;j++)
            {
                if(array[j] == '0' && j == 0 && i != 0)//去掉前缀0
                    continue;
                else if(array[j] == '0' && j == 0 && i == 0)//别把“0”也去掉了。。（只有一个0）
                {
                    System.out.println(0);
                    break;
                }
                System.out.print(array[j]);
            }
            System.out.println();//补换行
        }
    }
}
