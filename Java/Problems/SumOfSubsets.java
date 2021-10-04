package Problems;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class SumOfSubsets {

    List<List<Integer>> result;

    public SumOfSubsets() {
        this.result = new ArrayList<>();
    }

    public static void main(String[] args) {

        int[] arr = { 2, 3, 4, 5, 6, 7 };
        int sum = 10;
        List<List<Integer>> ans = SumOfSubsets.subOfSubsets(arr, sum);

        for (List<Integer> list : ans)
            System.out.println(list.toString());

    }

    public static List<List<Integer>> subOfSubsets(int[] arr, int sum) {

        SumOfSubsets sos = new SumOfSubsets();
        Stack<Integer> stack = new Stack<>();

        sos.getSets(arr, sum, stack, 0, 0);

        return sos.result;

    }

    public void getSets(int[] arr, int sum, Stack<Integer> current, int cSum, int index) {

        if (cSum >= sum || index == arr.length) {
            if (cSum == sum)
                result.add(new ArrayList<>(current));
            return;
        }

        int val = arr[index];

        getSets(arr, sum, current, cSum, index + 1);

        if (val <= sum) {
            current.push(arr[index]);
            getSets(arr, sum, current, cSum + val, index + 1);
            current.pop();
        }

    }

    public void getSets1(int[] arr, int sum, Stack<Integer> current, int cSum, int added) {

        if (cSum >= sum) {
            if (cSum == sum)
                result.add(new ArrayList<>(current));
            return;
        }

        for (int i = 0; i < arr.length; i++) {

            int ele = arr[i];

            if (current.contains(ele))
                continue;

            current.push(ele);
            getSets1(arr, sum, current, cSum + ele, added + 1);
            current.pop();

        }

    }

}
