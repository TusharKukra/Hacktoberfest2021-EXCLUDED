package Problems;

public class Knapsack {

    public static void main(String[] args) {

        int[] vals = { 10, 15, 40 };
        int[] wts = { 1, 2, 3 };

        System.out.println("Max: " + getMaxValue(vals, wts, 6, 3));

    }

    public static int getMaxValue(int[] values, int[] weights, int capacity, int n) {

        int[][] V = new int[n + 1][capacity + 1];

        int w = 0;

        for (int i = 0; i <= n; i++) {
            for (w = 0; w <= capacity; w++) {
                if (i == 0 || w == 0)
                    V[i][w] = 0;
                else if (w >= weights[i - 1]) {
                    V[i][w] = Math.max(V[i - 1][w], V[i - 1][w - weights[i - 1]] + values[i - 1]);
                } else {
                    V[i][w] = V[i - 1][w];
                }

            }
        }

        return V[n][capacity];

    }

    public static int getMaxValue(int[] values, int[] weights, int capacity) {
        return getMaxValue(values, weights, capacity, values.length);
    }

}
