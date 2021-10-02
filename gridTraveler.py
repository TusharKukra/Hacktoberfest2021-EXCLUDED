#The problem is to count number of possible possible paths from top left to bottom right in m x n grid where you can either move right or move down.
#The problem falls under category of Dynamic Programming
#Time Complexity: O(n^2) # using the two loops
#Space Complexity: O(n^2) # utilizing the table

'''
Solution submitted by: Ansh Gupta (@ansh422) 
Date: 2/10/2021
'''
def gridTraveler(m,n):
    table=[[0 for _ in range(n+1)] for _ in range(m+1)]
    table[1][1]=1
    for i in range(m+1):
        for j in range(n+1):
            if j+1 <= n:
                table[i][j+1]+=table[i][j]
            if i+1 <= m:
                table[i+1][j]+=table[i][j]
    
    return table[m][n]
    
if __name__ == "__main__":
    m,n=map(int,input().split()) # input here storing the dimensions of grid
    ans=gridTraveler(m,n)
    print(ans)
