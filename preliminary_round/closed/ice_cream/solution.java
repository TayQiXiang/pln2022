import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            //combination with repetition ( n+r-1 C r)
            System.out.println(factorial(n + r - 1).divide(factorial(n - 1).multiply(factorial(r))));
        }
    }

    static BigInteger factorial(int N) {
        BigInteger f = new BigInteger("1");
        // Multiply f with 2, 3, ...N
        for (int i = 2; i <= N; i++)
            f = f.multiply(BigInteger.valueOf(i));

        return f;
    }


}
