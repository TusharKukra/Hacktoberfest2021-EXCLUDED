/*The set [1,2,3,…,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order
Given n and k, return the kth permutation sequence.
For example, given n = 3, k = 4, ans = "231" */

int fact(int n)
{
    if(n>12)
        return INT_MAX;
    if(n==0)
        return 1;
    return n*fact(n-1);
}
string result(int B, vector<int> &v)
{
    int A=v.size();

    if(A==0) return "";

    int f=fact(A-1);
    int pos=B/f;
    B%=f;
    string c=to_string(v[pos]);
    v.erase(v.begin()+pos);
    return c+result(B,v);
}
string Solution:result:getPermutation(int A, int B) 
{
    vector<int> v;
    for(int i=1;i<=A;i++)
        v.push_back(i);

    return result(B-1,v);
}
