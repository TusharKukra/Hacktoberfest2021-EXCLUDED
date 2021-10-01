// User: Samrat Mitra
// Username: lionelsamrat10

// Approach-01 Brute Force Linear Traversal Approach
// Time Complexity: T(n) = O(n)
// Space Complexity: S(n) = O(1)

import java.io.*;

class FindMaxMinFromArray {
	public static void main (String[] args) {
	    int arr[] = {1, 2, 3, 4, 5, 6, 7};
	    int max = arr[0], min = arr[0];
	    for(int i=0; i<arr.length; i++){
	        //Logic to get the max element
	        if(max < arr[i])
	            max = arr[i];
	        //Logic to get the min element
	        if(min > arr[i])
	            min = arr[i];
	    }
	    System.out.println("Maximum: " + max);
	    System.out.println("Minimum: " + min);
	}
}


//Approach: 02 Tournament Method (Minimize the Number of comparisons)

/* Algorithm
* Divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.Pair MaxMin(array, array_size)
*  if array_size = 1
*      return element as both max and min
*   else if arry_size = 2
*      one comparison to determine max and min
*      return that pair
*   else     array_size  > 2
*      recur for max and min of left half
*      recur for max and min of right half
*      one comparison determines true max of the two candidates
*      one comparison determines true min of the two candidates
*      return the pair of max and min
*/
public class FindMaxMinFromArray {
/* Class Pair is used to return two values from getMinMax() */
	static class Pair {

		int min;
		int max;
	}

	static Pair getMinMax(int arr[], int low, int high) {
		Pair minmax = new Pair();
		Pair mml = new Pair();
		Pair mmr = new Pair();
		int mid;

		// If there is only one element
		if (low == high) {
			minmax.max = arr[low];
			minmax.min = arr[low];
			return minmax;
		}

		/* If there are two elements */
		if (high == low + 1) {
			if (arr[low] > arr[high]) {
				minmax.max = arr[low];
				minmax.min = arr[high];
			} else {
				minmax.max = arr[high];
				minmax.min = arr[low];
			}
			return minmax;
		}

		/* If there are more than 2 elements */
		mid = (low + high) / 2;
		mml = getMinMax(arr, low, mid);
		mmr = getMinMax(arr, mid + 1, high);

		/* compare minimums of two parts*/
		if (mml.min < mmr.min) {
			minmax.min = mml.min;
		} else {
			minmax.min = mmr.min;
		}

		/* compare maximums of two parts*/
		if (mml.max > mmr.max) {
			minmax.max = mml.max;
		} else {
			minmax.max = mmr.max;
		}

		return minmax;
	}

	/* Driver program to test above function */
	public static void main(String args[]) {
		int arr[] = {1000, 11, 445, 1, 330, 3000};
		int arr_size = 6;
		Pair minmax = getMinMax(arr, 0, arr_size - 1);
		System.out.printf("\nMinimum element is %d", minmax.min);
		System.out.printf("\nMaximum element is %d", minmax.max);

	}
}
// Time Complexity: O(n) 
/*
* Total number of comparisons: let the number of comparisons be T(n). T(n) can be written as follows: 
* Algorithmic Paradigm: Divide and Conquer 
* 
*              
*   T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
*   T(2) = 1
*   T(1) = 0
* If n is a power of 2, then we can write T(n) as: 
* 
* 
* 
*    T(n) = 2T(n/2) + 2
* After solving the above recursion, we get 
* 
*   T(n)  = 3n/2 -2
* Thus, the approach does 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.
*/
