
import java.util.*;
class bubbleSort{
    public static void main(String[] args){
        int[] arr = {9,8,7,6,5,4,3,2,1};
        int n = arr.length;
        int tmp;
        /*
        This sorting algorithm is the simplest sorting algorithm that works by repeatedly
        swapping the adjacent elements if they are in the wrong order.
        If we have total N elements, then we need to repeat the above process for N-1 times.
        We can use Bubble Sort as per below constraints :
        It works well with large datasets where the items are almost sorted because it
        takes only one iteration to detect whether the list is sorted or not.
        But if the list is unsorted to a large extend
        then this algorithm holds good for small datasets or lists.
        This algorithm is fastest on an extremely small or nearly sorted set of data.
        ***Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
        Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
        Auxiliary Space: O(1)
        Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
        Sorting In Place: Yes
        Stable: Yes****(IMP)
        */
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i]<arr[j]){
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        for(int i=0;i<n;i++){
            System.out.print(arr[i]);
        }
    }
}
