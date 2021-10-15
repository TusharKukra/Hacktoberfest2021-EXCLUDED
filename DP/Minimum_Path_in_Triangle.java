class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        return findMinPath(triangle,0,0);
    }
    public int findMinPath(List<List<Integer>> list,int index,int lindex){
        if(index>=list.size())
            return 0;
        int min=Integer.MAX_VALUE-10000;
        int val=Math.min(findMinPath(list,index+1,lindex),findMinPath(list,index+1,lindex+1));
        min=Math.min(min,val+list.get(index).get(lindex));
        return min;
        
    }
}
Method 2:Recursive Dynamic Programming (Using cache/Memoization) (Top Down Approach)
class Solution {
    int [][]cache;
    public int minimumTotal(List<List<Integer>> triangle) {
        cache=new int[triangle.size()][triangle.size()];
        for(int i=0;i<cache.length;i++){
            Arrays.fill(cache[i],Integer.MAX_VALUE);
        }
        return findMinPath(triangle,0,0);
    }
    public int findMinPath(List<List<Integer>> list,int index,int lindex){
        if(index>=list.size())
            return 0;
        if(cache[index][lindex]!=Integer.MAX_VALUE)
            return cache[index][lindex];
        int min=Integer.MAX_VALUE-10000;
        int val=Math.min(findMinPath(list,index+1,lindex),findMinPath(list,index+1,lindex+1));
        min=Math.min(min,val+list.get(index).get(lindex));
        cache[index][lindex]=min;gvvf
        return min;
        
    }
}
Method 3: Dynamic Programming (Bottom up Iterative) Without using Extra Space
class Solution{
    public int minimumTotal(List<List<Integer>> triangle){
     for(int i=triangle.size()-2;i>=0;i--){
        int val=triangle.get(i).size();
         for(int j=0;j<val;j++){
             int val1=triangle.get(i).get(j)+Math.min(triangle.get(i+1).get(j),triangle.get(i+1).get(j+1));
             triangle.get(i).set(j,val1);
         }
     }
        return triangle.get(0).get(0);
    }
}