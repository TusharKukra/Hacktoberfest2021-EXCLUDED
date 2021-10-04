package Math;

public class Permutations {

    public static int nPr(int n, int r) {

        if (n == r)
            return 1;

        if (n > r && r >= 0)
            return getFactorial(n) / getFactorial(r);

        return 0;

    }

    public static int getnPrSummation(int n) {

        int sum = 0;

        for (int i = 0; i <= n; i++) {

            sum += nPr(n, i);
        }

        return sum;

    }

    static int getFactorial(int n) {

        int ans = 1;

        for (int i = 1; i <= n; i++) {
            ans *= i;
        }

        return ans;
    }


}
