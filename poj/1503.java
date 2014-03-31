import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String args[])
    {
        Scanner cin = new Scanner(System.in);
        BigInteger a;
        BigInteger sum = BigInteger.ZERO;
        while(cin.hasNextBigInteger())
        {
            a = cin.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO) == 0)
                break;
            sum = sum.add(a);
        }
        System.out.println(sum);
    }
}
