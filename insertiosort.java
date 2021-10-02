import java.util.*;
class insertionSort{
    public static void main(String[] args){
        int[] arr = {9,8,17,3,2,15,99,5};
        int j,temp;
        int len = arr.length;
        /*
Here first variable i will point to {9,8 -> i,17,3,2,15,99,5}, then we store that 8 in temp.
later we declare j = i-1 & compare the temp with the previous value. if it is greater then do
nothing. if temp<arr[j], then we need to move the elements until the while loop breaks
WORST-TIME CASE COMPLEXITY- O(n^2)
    BEST-TIME CASE - O(n)
    AVERAGE TIME CASE COMPLEXITY- O(n^2)
    SPACE COMPLEXITY- O(1)
Strengths:
    Intuitive. Ever arranged your cards while playing poker or go-fish?
    Chances are, you used something like insertion sort.
    Space efficient. Insertion sort can be done in-place O(1) additional space.
    Fast on a sorted list. If the input list is already sorted, then insertion sort runs in O(n) time.
Weaknesses:
    Slow. Insertion sort usually takes
    O(n^2)
    O(n^2) time—too slow to be used on super-big data sets.
Worst Case
    In the worst case, the input list is in descending order (reverse-sorted order).
    So each time we insert an element into the sorted portion,
    we'll need to swap it with each of the elements already in the sorted list to get it
    all the way to the start. That's 1 swap the first time, 2 swaps the second time,
    3 swaps the third time, and so on, up to n−1 swaps for the last item.
*/
        for(int i=1;i<len;i++){
            temp = arr[i];
            j = i-1;
            while(j>=0 && temp<arr[j]){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
        for(int i=0;i<len;i++){
            System.out.println(arr[i]);
        }
    }

}
