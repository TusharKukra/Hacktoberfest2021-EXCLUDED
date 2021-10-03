def bubbleSort(array):
    for i in range(len(array)):
        for j in range(len(array) - i - 1):
            if array[j] > array[j + 1]:
                swap(j, j + 1, array)
    
    return array

def swap(i, j, array):
    array[i], array[j] = array[j], array[i]

# Time Complexity:  O(n^2)
# Space Complexity: O(1)