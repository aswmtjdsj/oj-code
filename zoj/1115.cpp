import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner read = new Scanner(System.in);
        while(read.hasNextBigInteger())
        {
            BigInteger a = read.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO) == 0)
                break;
            if(a.compareTo(BigInteger.valueOf(10)) < 0)
                System.out.println(a);
            else
            {
                int ans = 0;
                BigInteger []b = new BigInteger[2];
                while(a.compareTo(BigInteger.valueOf(10)) >= 0)
                {
                    b = a.divideAndRemainder(BigInteger.valueOf(10));
                    ans += b[1].intValue();
                    a = b[0];
                }
                ans += a.intValue();
                int temp = ans;
                while(ans >= 10)
                {
                    ans = 0;
                    while(temp >= 10)
                    {
                        ans += temp % 10;
                        temp /= 10;
                    }
                    ans += temp;
                    temp = ans;
                }
                System.out.println(ans);
            }
        }
    }
}
