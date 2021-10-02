//Put n items with given wieght and value in a knapsack of capacity W to get the maximum total value in the bag
#include <iostream>
using namespace std;

int knapsack(int value[],int weight[],int n, int W)
{
    if(n==0 || W==0) return 0;
    if(weight[n-1]>W)  //do not include the item in the bag
        return knapsack(value,weight,n-1,W);
    return max(knapsack(value,weight,n-1,W),knapsack(value,weight,n-1,W-weight[n-1])+ value[n-1]);
}

int main()
{
    int wght[] = {10,20,30};
    int value[] = {100,50,150};
    int w = 50;
    cout<<knapsack(value,wght,3,w);
    return 0;
}