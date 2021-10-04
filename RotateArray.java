class Solution {
    public void rotate(int[] nums, int k) {
        int[] arr=new int[nums.length];int n=nums.length;
        while(k>n)
            k=k-n;
        for(int i=0;i<n;i++)
        {
            if(i<k)
            arr[i]=nums[n-k+i];
            else
                arr[i]=nums[i-k];
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=arr[i];
        }
    }
}
