 Merged sort application
# Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
# Merge them in sorted order without using any extra space. Modify arr1 so that it contains the
# first N elements and modify arr2 so that it contains the last M elements.

def merge(arr1,arr2,n,m):
    result = []
    merged = []
    i = 0
    j = 0
    while i < n and j < m:
        if arr1[i] < arr2[j]:
            merged.append(arr1[i])
            i += 1
        else:
            merged.append(arr2[j])
            j += 1
    while i < n:
        merged.append(arr1[i])
        i += 1
    while j < m:
        merged.append(arr2[j])
        j += 1
    arr1.clear()
    arr2.clear()
    for i in range(n):
        arr1.append(merged[i])
    for j in range(m):
        arr2.append(merged[n + j])

    return arr1+arr2

if __name__ == '__main__':
    n = 4
    arr1 = [1,3,5,7]
    m = 5
    arr2 = [0,2,6,8,9]
    print(merge(arr1,arr2,n,m))