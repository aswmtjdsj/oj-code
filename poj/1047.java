import java.util.*;
import java.math.*;
public class Main{
    public static void main(String args[])
    {
        String input;
        BigInteger a;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNext())
        {
            input = cin.next();
            int l = input.length();
            System.out.println(l);
            a = BigInteger.ZERO;
            BigInteger temp = BigInteger.ONE;
            char[] abc = new char[100];
            //for(int i = 0;i < abc.length;i++)
            //  System.out.print(abc[i]);
            abc = input.toCharArray();
            for(int i = l - 1;i >= 0;i --)
            {
                a = a.add(temp.multiply(BigInteger.valueOf(abc[i] - '0')));
                temp = temp.multiply(BigInteger.TEN);
            }
            a = a.multiply(BigInteger.valueOf(l + 1));
            abc = a.toString().toCharArray();
            boolean mark = true;
            for(int i = 0;i < abc.length;i++)
                if(abc[i] != '9')
                    mark = false;
            boolean flag = true;
            for(int i = 2;i < l + 1;i ++)
            {
                if((l + 1) % i == 0)
                    flag = false;
            }
            if(flag && mark)
                System.out.println(input + " is cyclic");
            else
                System.out.println(input + " is not cyclic");
            //System.out.println(a);
        }
    }
}
/*
 * 所谓循环数就是某个质数的倒数的小数部分，小学奥数有讲过。
 * 而且循环节长度恰好为原质数－1
 * 则只需要判断输入长度＋1是否为质数，且输入乘以循环节＋1是否等于一串9（即所谓的1，循环小数转化为分数的一个关键）
 * 所谓的余9法？类似那个数位加和函数的余9法。。。。
 */
