import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String args[])
    {
        String ori;
        Scanner cin = new Scanner(System.in);
        BigDecimal a;
        while(cin.hasNextLine())
        {
            ori = cin.nextLine();
            a = BigDecimal.ZERO;
            for(int i = 2;i < ori.length();i++)
            {
                char []abc = new char[1000];
                abc = ori.toCharArray();
                int ccc = abc[i] - '0';
                BigDecimal t,temp = BigDecimal.valueOf(ccc);
                System.out.println(temp);
                t = BigDecimal.ONE;
                for(int j = 0;j <= i - 2;j++)
                    t = t.multiply(BigDecimal.valueOf(0.125));
                temp = temp.multiply(t);
                a = a.add(temp);
            }
            System.out.println(ori + " [8] = " + a + " [10]");
        }
    }
}
