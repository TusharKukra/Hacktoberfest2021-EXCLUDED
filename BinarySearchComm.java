public class BinarySearchComm {
    public static void main(String[] args) {

        int[] arr= {12,23,34,45,67,89};
        int target=23;

        int ans=binarySearch(arr,target);
        System.out.println(ans);

    }

    // To write the function for binary search

    static int binarySearch(int[] arr , int target){
        int start=0;
        int end=arr.length-1;

        while(start<=end){
            // Now find the middle value
            int mid= start + ( end - start )/2;

            if(target<arr[mid]){
                end=mid-1;

            }
            else if(target>arr[mid]){
                start=mid+1;

            }
            else{
                return mid;
            }
        }
        return -1;



    }
}
