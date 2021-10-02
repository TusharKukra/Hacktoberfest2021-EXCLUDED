- [Qusetion link GEEKS FOR GEEKS](https://practice.geeksforgeeks.org/problems/range-minimum-query/1#)
- For single query question, linear serach ca be done, but for large query question, time complexity will be high
- so we use segment tree concept and do pre-calculation to store the min for range l to r

##### first we construct the tree
```cpp
// A recursive function that constructs
// Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se, int *st, int si){

    // If there is one element in array,
    // store it in current node of
    // segment tree and return
    if(ss==se){
        st[si] = arr[ss];
        return st[si];
    }
    
    // If there are more than one elements,
    // then recur for left and right subtrees
    // and store the minimum of two values in this node
    int mid = (ss+se)/2;
    st[si] = min(constructSTUtil(arr, ss, mid, st, 2*si+1),
                 constructSTUtil(arr, mid+1, se, st, 2*si+2));
    return st[si];
    
}

/* Function to construct segment tree
from given array. This function allocates
memory for segment tree and calls constructSTUtil() to
fill the allocated memory */
int *constructST(int arr[],int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)(pow(2,x)) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
  //Your code here
}
```
##### now we find the minimum for given range
```cpp
/* A recursive function to get the
minimum value in a given range
of array indexes. The following
are parameters for this function.
 
    st --> Pointer to segment tree
    index --> Index of current node in the
           segment tree. Initially 0 is
           passed as root is always at index 0
    ss & se --> Starting and ending indexes
                of the segment represented
                by current node, i.e., st[index]
    qs & qe --> Starting and ending indexes of query range */
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    // If segment of this node is a part
    // of given range, then return
    // the min of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node
    // is outside the given range
    if (se < qs || ss > qe)
        return INT_MAX;
 
    // If a part of this segment
    // overlaps with the given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 
// Return minimum of elements in range
// from index qs (query start) to
// qe (query end). It mainly uses RMQUtil()
int RMQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }
 
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
```
