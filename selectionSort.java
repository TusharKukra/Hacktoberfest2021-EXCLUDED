import java.util.*;
class selectionSort{
    public static void main(String[] args){
        int[] arr = {10,9,12,5,1,6,25};
        /*
        It is just like swapping the next smallest element with the present element
        for example, if we are at 10, we search for the smallest element, that is 1, so we swap
        10 with 1. and next will become -> {1,9 -> i,12,5,10,6,25}
        next we are at i = 1, i.e @ 9, so we compare the next smallest number in the array except 1
        we find that as 5, so we swap 9 with 5
        {1,5,12 -> i,9,10,6,25}
        next we find the next the next smaller element in the array. we find that as 6
        so we swap that with 12
        {1,5,6,9,10,12,25}
        so on...........
        When the list is small. As the time complexity of selection sort is O(N^2)
        which makes it inefficient for a large list.
        When memory space is limited because it makes the minimum
        possible number of swaps during sorting.
        BEST-CASE TIME COMPLEXITY- O(n^2)
        AVERAGE-CASE TIME COMPLEXITY- O(n^2)
        WORST-CASE TIME COMPLEXITY- O(n^2)
        SPACE COMPLEXITY- O(1)
        Strengths:
            Intuitive. Ever packed a suitcase, putting in large
            items before smaller ones? That's selection sort!
            Space efficient. Selection sort only requires a constant amount of additional space O(1)
        Weaknesses:
            Slow. Selection sort takes
            O(n^2)time, even if the input is already sorted.
            That's too slow to be used on super-big data sets.
        */

        int len = arr.length;
        for(int i=0;i<len;i++){
            int pos = smallest(arr, len, i);
            int temp = arr[i];
            arr[i] = arr[pos];
            arr[pos] = temp;
        }
        for(int i=0;i<len;i++){
            System.out.println(arr[i]);
        }
    }
    public static int smallest(int[] arr, int n, int i){
        int pos=i;
        int small = arr[i];
        for(int j = i+1;j<n;j++){
            if(arr[j]<small){
                small = arr[j];
                pos = j;
            }
        }

        return pos;
    }
}
