package Problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class NQueen {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n:");
        int n = sc.nextInt();

        double a = System.nanoTime() / 1000000.0;

        List<Integer[]> x = NQueenSol(n);

        double b = System.nanoTime() / 1000000.0;

        System.out.println("\nThere are " + x.size() + " solutios - ");

        for (Integer[] y : x) {
            System.out.println(Arrays.toString(y));
        }

        System.out.println("\nIn time: " + (b - a));

        sc.close();
    }

    public static List<Integer[]> getPlaces(int n) { // Without reversing

        if (n <= 0) {
            return new ArrayList<>();
        }

        int[][] board = new int[n][n];
        List<Integer[]> result = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        int r = 1;
        int c = 0;
        board[0][0] = 1;
        stack.push(0);

        while (r >= 0) {

            if (c > n - 1) { // Case 0
                if (r == 0)
                    break;
                c = stack.pop() + 1;
                r--;
                board[r][c - 1] = 0;
                continue;
            }

            if (canBePlaced(board, r, c)) {
                if (r >= n - 1) { // Case 1

                    stack.push(c);

                    Integer[] epic = toArray(stack);
                    result.add(epic);

                    stack.pop();

                    r--;
                    c = stack.pop() + 1;

                    board[r][c - 1] = 0;

                } else { // Case 2
                    board[r][c] = 1;
                    stack.push(c);
                    c = 0;
                    r++;
                }
            } else {
                if (c >= n - 1) { // Case 3
                    if (r == 0)
                        break;

                    c = stack.pop() + 1;
                    r--;
                    board[r][c - 1] = 0;
                } else { // Case 4
                    c++;
                }
            }

        }

        return result;
    }

    public static List<Integer[]> NQueenSol(int n) { // With reversing

        if (n <= 0) {
            return new ArrayList<>();
        }

        int[][] board = new int[n][n];
        List<Integer[]> result = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        int r = 1;
        int c = 0;
        board[0][0] = 1;
        stack.push(0);

        while (r >= 0) {

            if (r == 0 && c > (n - 1) / 2)
                break;

            if (c > n - 1) { // Case 0
                if (r == 0)
                    break;
                c = stack.pop() + 1;
                r--;
                board[r][c - 1] = 0;
                continue;
            }

            if (canBePlaced(board, r, c)) {
                if (r >= n - 1) { // Case 1

                    stack.push(c);

                    Integer[] epic = toArray(stack);
                    result.add(epic);

                    stack.pop();

                    r--;
                    c = stack.pop() + 1;

                    board[r][c - 1] = 0;

                } else { // Case 2
                    board[r][c] = 1;
                    stack.push(c);
                    c = 0;
                    r++;
                }
            } else {
                if (c >= n - 1) { // Case 3
                    if (r == 0)
                        break;

                    c = stack.pop() + 1;
                    r--;
                    board[r][c - 1] = 0;
                } else { // Case 4
                    c++;
                }
            }

        }

        finalize(result);

        return result;
    }

    private static void finalize(List<Integer[]> result) {

        if (result.size() > 0) {
            List<Integer[]> temp = new ArrayList<>();

            int n = result.get(0).length;

            for (int i = 0; i < result.size(); i++) {

                if (result.get(i)[0] > n / 2)
                    break;

                temp.add(reverseIntegers(result.get(i)));

            }

            result.addAll(temp);

        }

    }

    private static Integer[] reverseIntegers(Integer[] a) {

        Integer[] b = Arrays.copyOf(a, a.length);

        int n = a.length;

        for (int i = 0; i < (n / 2); i++) {
            int temp = b[i];
            b[i] = b[n - 1 - i];
            b[n - 1 - i] = temp;
        }

        return b;

    }

    private static Integer[] toArray(Stack<Integer> stack) {

        Integer[] x = new Integer[stack.size()];

        for (int i = 0; i < x.length; i++) {
            x[i] = stack.get(i) + 1;
        }

        return x;

    }

    private static boolean canBePlaced(int[][] board, int r, int c) {
        return canPlaceInCol(board, c) && canPlaceInDiag(board, r, c);
    }

    private static boolean canPlaceInCol(int[][] board, int c) {

        for (int i = 0; i < board.length; i++)
            if (board[i][c] == 1)
                return false;

        return true;
    }

    private static boolean canPlaceInDiag(int[][] board, int r, int c) {

        int r1 = r, c1 = c, c2 = c;
        int n = board.length;

        while (r1 >= 0 && (c1 >= 0 || c2 < n)) {
            if (c1 >= 0)
                if (board[r1][c1] == 1)
                    return false;
            if (c2 < n)
                if (board[r1][c2] == 1)
                    return false;

            r1--;
            c1--;
            c2++;
        }

        return true;

    }

}
