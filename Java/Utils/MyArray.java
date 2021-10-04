package Utils;

public class MyArray {

    public static int[] getRemovedArray(int[] arr, int x) {

        int[] newArr = new int[arr.length - 1];
        int j = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != x) {
                newArr[j] = arr[i];
                j++;
            }
        }

        return newArr;

    }

}
