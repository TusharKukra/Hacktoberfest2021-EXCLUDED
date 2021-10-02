package ARRAYS;
import java.util.*;

import org.jetbrains.annotations.NotNull;

//e..g--> In array {12,342,5436,435},There are 2 elements (12 & 5436) with even number of digits.
public class EvenDigits {
	public static void main(String[] args) {
		int[] arr = {12, 342, 5436, 435, 321};
		int ans = search(arr);
		System.out.println(ans);
	}

	//more optimised and preferred method to calculate the number of digits..
	static int digits2(int element) {
		return (int) Math.log10(element) + 1;
	}

	static int search(int[] arr) {
		int even = 0;
		for (int element : arr) {
			if (digits2(element) % 2 == 0) {
				even++;
			}
		}
		return even;
	}

	static int digits(int element) {
		int number = 0;
		while (element > 0) {
			number++;
			element = element / 10;
		}
		return number;
	}


}
