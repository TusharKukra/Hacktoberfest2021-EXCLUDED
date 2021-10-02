/*Sampad Patra
  Hacktober 2021
  Dynamic Programming
*/


#include<bits/stdc++.h>
using namespace std;

//Memoization and top down or bottom up approach have the same complexity.
//However top down or bottom up are still considered better than memoization due to 
//decrease in number of function calls.


int dp[50][50]; //size of dp should be set according to the constraints given in the problem.

//function to find the maximum value that the knapsack of given capacity can hold.

int knapsack(int weight[],int val[],int n,int cap)
{
	
	
	if(n<=0||cap<=0)
		return 0;
	if(dp[n-1][cap]!=-1)
		return dp[n-1][cap];
	if(cap>=weight[n-1])			//we have two choice to include and not include the item
	{	
		dp[n-1][cap] = max(val[n-1]+knapsack(weight,val,n-1,cap-weight[n-1]),knapsack(weight,val,n-1,cap));
		return dp[n-1][cap];
	}
	else							// we cannot include the item.
	{
		dp[n-1][cap] = knapsack(weight,val,n-1,cap);
		return dp[n-1][cap];
	}
}

int main()
{
	memset(dp,-1,sizeof(dp));			//memoise the array to -1 initially. 
	int weight[5] = {4,5,6,5,9};		// can take user input 
	int value[5] = {40,60,80,70,100};
	int capacity = 11;
	cout<<knapsack(weight,value,5,capacity); //The maximum value that our knapsack can hold
	return 0;
}