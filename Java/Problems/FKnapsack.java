package Problems;

import java.util.Arrays;

public class FKnapsack {

    public static void main(String[] args) {
        int[] vals = { 10, 15, 40, 20, 25, 5 };
        int[] wts = { 5, 3, 4, 10, 6, 1 };

        System.out.println(getMaxValue(vals, wts, 20, 6));

    }

    public static double getMaxValue(int[] values, int[] weights, int capacity) {
        return getMaxValue(values, weights, capacity, values.length);
    }

    public static double getMaxValue(int[] values, int[] weights, int capacity, int n) {

        Item[] items = new Item[n];

        int added = 0;
        double cp = 0;

        for (int i = 0; i < n; i++) {
            items[i] = new Item(weights[i], values[i]);
        }

        Arrays.sort(items);

        for (Item i : items) {
            if (i.wt + added <= capacity) {

                added += i.wt;
                cp += i.val;

                if (added == capacity) {
                    break;
                }

            } else {
                double ratio = (capacity - added) * 1.0 / i.wt;

                cp += i.val * ratio;
                break;

            }

        }

        return cp;
    }

    static class Item implements Comparable<Item> {
        int wt, val;

        double vbw;

        public Item(int wt, int val) {
            this.wt = wt;
            this.val = val;
            vbw = val * 1.0 / wt;
        }

        @Override
        public int compareTo(Item i) {

            double temp = i.vbw - this.vbw;

            if (temp != 0)
                return temp > 0 ? 1 : -1;

            temp = i.val - this.val;

            if (temp != 0)
                return temp > 0 ? 1 : -1;

            temp = this.wt - i.wt;

            return temp >= 0 ? 1 : -1;
        }

        @Override
        public String toString() {
            return "Item [val=" + val + ", vbw=" + vbw + ", wt=" + wt + "]";
        }

    }

}
