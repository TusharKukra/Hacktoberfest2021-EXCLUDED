Python program to print the smallest element in an array
In this program, we need to find out the smallest element present in the array. This can be achieved by maintaining a variable min which initially will hold the value of the first element. Loop through the array by comparing the value of min with elements of the array. If any of the element's value is less than min, store the value of the element in the min.

Python program to print the smallest element in an array
Consider above array. Initially, min will hold the value 25. In the 1st iteration, min will be compared with 11. Since 11 is less than 25. Min will hold the value 11. In a 2nd iteration, 11 will be compared with 7. Now, 7 is less than 11. So, min will take the value 7. Continue this process until the end of the array is reached. At last, min will hold the smallest value element in the array.

ALGORITHM:
STEP 1: Declare and initialize an array.
STEP 2: Store first element in the variable min.
STEP 3: Loop through the array from 0 to length of the array and compare the value of min with elements of the array.
STEP 4: If any element is less than min, min will hold the value of that element.
STEP 5: At last, min will represent the smallest element in the array.
PROGRAM:
#Initialize array     
arr = [25, 11, 7, 75, 56];     
     
#Initialize min with the first element of the array.    
    
min = arr[0];    
     
#Loop through the array    
for i in range(0, len(arr)):    
    #Compare elements of array with min    
   if(arr[i] < min):    
       min = arr[i];    
     
print("Smallest element present in given array: " + str(min));    
Output:

Smallest element present in given array: 7
Python program to print the elements of an array in reverse order
In this program, we need to print the elements of the array in reverse order that is; the last element should be displayed first, followed by second last element and so on.

Python program to print the elements of an array in reverse order
Above array in reversed order:

Python program to print the elements of an array in reverse order
ALGORITHM:
STEP 1: Declare and initialize an array.
STEP 2: Loop through the array in reverse order that is, the loop will start from (length of the array - 1) and end at 0 by decreasing the value of i by 1.
STEP 3: Print the element arr[i] in each iteration.
PROGRAM:
#Initialize array     
arr = [1, 2, 3, 4, 5];     
print("Original array: ");    
for i in range(0, len(arr)):    
    print(arr[i]),     
print("Array in reverse order: ");    
#Loop through the array in reverse order    
for i in range(len(arr)-1, -1, -1):     
    print(arr[i]),     
Output:

Original array: 
1	2   3   4   5
Array in reverse order:
5    4   3   2   1
