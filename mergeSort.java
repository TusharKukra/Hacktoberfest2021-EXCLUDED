import java.util.*;
class ms{
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of terms : ");
        int n = s.nextInt();
        int[] arr = new int[n];
        System.out.println("enter the numbers : ");
        for(int i=0;i<n;i++){
            arr[i] = s.nextInt();
        }
        System.out.println("unsorted array: " + Arrays.toString(arr));
        mergeSort(arr);// we are passing our array to the mergesort() function as input
        System.out.println("sorted array : ");
        for(int i=0;i<n;i++){
            System.out.println(arr[i]);
        }
    }
    public static void mergeSort(int[] arr){
        int n = arr.length;
        if(n<2)return;
        int mid = n / 2;
        int[] l = new int[mid];
        int[] r = new int[n-mid];
        for(int i=0;i<mid;i++){
            l[i] = arr[i];
        }
        for(int i=mid;i<n;i++){
            r[i-mid] = arr[i];
        }
        mergeSort(l);
        mergeSort(r);
        merge(arr,l,r);
    }
    public static void merge(int[] arr, int[] l,int[] r){
        int nL = l.length;
		int nR = r.length;
		int i = 0, j = 0, k = 0;
        /*
        if l = [3,2,1];
        if r = [6,7,8];
        then after entering the while loop,compare the elements of l & r arrays,
        if l<r, then replace the arr[k] with the lth element && increment i by 1
        else replace it with rth element && increment j by 1
        next, we have to check whether there are any leftovers in the left & right arrays.
        thats it, we have to do it recursively for both the left and right arrays.
        Strengths:
            Fast. Merge sort runs in
            O(nlog(n))
            O(nlog(n)), which scales well as n grows.
            Parallelizable. Merge sort breaks the input into chunks,
            each of which can be sorted at the same time in parallel.
        Weaknesses:
            Space. Merge sort takes up O(n) extra space, including
            O(lg(n)) space for the recursive call stack.
        Time complexity of Merge Sort is  θ(nLogn) in all 3 cases
        (worst, average and best) as merge sort always divides the array into two halves
        and takes linear time to merge two halves.
        Auxiliary Space: O(n)
        
        Algorithmic Paradigm: Divide and Conquer
        Sorting In Place: No in a typical implementation
        Stable: Yes
        */
		while(i<nL && j<nR){
            if(l[i]<=r[j]){
                arr[k] = l[i];
                i++;
            }
            else{
                arr[k] = r[j];
                j++;
            }
            k++;
        }
        while(i<nL){
            arr[k] = l[i];
            i++;
            k++;
        }
        while(j<nR){
            arr[k] = r[j];
            j++;
            k++;
        }
    }

}
