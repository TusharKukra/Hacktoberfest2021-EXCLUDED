# Contains some competetive coding questions with solutions.
<hr/>

## Question : 1 
## Solution : [longest-common-prefix](./longest-common-prefix.py)

The longest common prefix for N strings of length at most M each is defined as a string K
Such that every string has K as a prefix.
You are given the task of finding the longest common prefix for N such strings.

Constraints:

1<=N<=10000

1<=M<=100

### Input Description:
The first line contains a single integer N : the number of strings The next N line contains the N strings - one in each line All strings consists of only lowercase alphabets from ‘a’-’z’

### Output Description:
Output a single line : the longest common prefix of the N strings . If no longest common prefix exists output “No common prefix exists”

### Sample Input :
4 <br/>
abcdjkhkjh <br/>
ahhjk <br/>
abcdhjjj <br/>
aa <br/>

### Sample Output :
a

<hr/>

## Question : 2
## Solution : [paths-in-a-maze](./paths-in-a-maze.py)

Feeling adventurous Kumar decides to explore a maze which is in the form of a matrix . The matrix's cells are numbered as (r,c) where r is the row number and c is the column number.

The dimensions of the matrix are N x M (having N rows and M columns) . The maze consists of a total of N*M rooms. From a room you can only move to any room to its right or below it.

So if you are present in a room (i,j) , you can move only to either room (i + 1, j ) or ( i , j + 1). You can not make any move that will take you out of the maze at any point . Some rooms in this maze are blocked and cannot be accessed so you cannot pass throught them even if you want to. Kumar , through sheer luck finds a map of the maze when he is in the starting room of the maze (1,1) (the topmost left cell) and the exit to the maze is at (N,M) (bottomost right cell) . Instead of actually navigating the maze he decides to find the number of ways there is to navigate the maze successfully from (1,1) to (N,M)

 The maze will be given to you as a binary matrix. Output the total number of paths modulo 1000000007

### Input Description:
First line contains two integers : N M denoting the no of rows and the no of columns of the matrix The next N lines contain M integers each . Each of these integers are either 0 or 1. 0 means that the room is free to pass through 1 means that the room is blocked and cannot be accessed

### Output Description:
Output must consist of a single integer , the total number of paths modulo 1000000007

### Sample Input : 
2 2 <br/>
0 0 <br/>
1 0 <br/>
### Sample Output : 
1

<hr/>

## Question : 3

## Solution : [reverse_vowels_in_a_string](./reverse_vowels_in_a_string.py)
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

### Constraints
1 <= s.length <= 3 * 10000
s consist of printable ASCII characters.

### Sample Input
Input: s = "hello"

### Sample Output
Output: "holle"

