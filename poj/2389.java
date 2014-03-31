import java.util.*;
import java.math.*;
import java.io.*;

public class Main {
    public static void main(String args[])
    {
        BigInteger a,b;
        Scanner cin = new Scanner(System.in);
        while(cin.hasNextBigInteger())
        {
            a = cin.nextBigInteger();
            b = cin.nextBigInteger();
            System.out.println(a.multiply(b));
        }
    }
}
