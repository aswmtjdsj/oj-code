import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    public static void main(String args[])
    {
        String sa,sb;
        Scanner cin = new Scanner(System.in);
        int t;
        while(cin.hasNextInt())
        {
            t = cin.nextInt();
            for(int i = 1;i <= t;i++)
            {
                sa = cin.next();
                sb = cin.next();
                if(sa.charAt(0) == '+')
                    sa = sa.substring(1);
                if(sb.charAt(0) == '+')
                    sb = sb.substring(1);
                BigInteger a = new BigInteger(sa);
                BigInteger b = new BigInteger(sb);
                System.out.println(a.add(b));
            }
        }
    }
}
