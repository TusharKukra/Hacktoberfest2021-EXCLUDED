#include <bits/stdc++.h>
using namespace std;

vector<int> findMax(vector<int> nums, int k)
{
    vector<int> res;
    deque<int> dq;
    int i;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for (; i < nums.size(); i++)
    {
        res.push_back(nums[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while (!dq.empty() && nums[i] >= nums[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(nums[dq.front()]);
    return res;
}

int main()
{
    int n, k;
    cout << "Enter number of integers" << endl;
    cin >> n;
    cout << "Enter " << n << " integers" << endl;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "Enter window size" << endl;
    cin >> k;
    vector<int> res;
    res = findMax(nums, k);

    cout << "ans" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
/*
Given a list of integers nums and an integer k, return the maximum values of each sublist of length k. 
input:
    nums = [10, 5, 2, 7, 8, 7]
    k = 3
Output:
    [10, 7, 8, 8]

Explanation:
    10 = max(10, 5, 2)
    7 = max(5, 2, 7)
    8 = max(2, 7, 8)
    8 = max(7, 8, 7)

n=number of integers;
Tc: O(n) -> every element is pushed and poped at most once. so total 2*n operations
Sc: O(k)
*/