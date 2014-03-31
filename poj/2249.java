import java.math.*;
import java.io.*;
import java.util.*;
public class Main
{
    public static void main(String args[])
    {
        BigInteger a,temp;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNextInt())
        {
            int n,k;    
            n = cin.nextInt();
            k = cin.nextInt();
            if(n == 0 && k == 0)
                break;
            if(k > n - k)
                k = n - k;
            temp = BigInteger.valueOf(1);
            a = temp;
            for(int i = n;i > n - k;i--)
                a = a.multiply(BigInteger.valueOf(i));
            for(int i = 1;i <= k;i++)
                temp = temp.multiply(BigInteger.valueOf(i));
            System.out.println(a.divide(temp));
        }
    }
}
