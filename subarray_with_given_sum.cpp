#include<iostream>
#include<vector>
using namespace std;

vector <int> get_index(vector<int> a, int n, int sum)
{
    int start = 0, end;
    bool flag = false;
    vector<int>index;
    long c_sum = 0;
    for(int i=0; i<n; i++)
    {
        c_sum = c_sum + a[i];
        if(c_sum >= sum)
        {
            end = i;
            while(sum < c_sum && start < end)
            {
                c_sum = c_sum - a[start];
                start++;
            }
            
            if(c_sum == sum)
            {
                index.push_back(start+1);
                index.push_back(end+1);
                flag = true;
                break;
            }
            
        }
    }
    if(flag == false)
    {
        index.push_back(-1);
    }
    return index;
}


int main()
{
    vector<int>arr;
    int n, ele, sum;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter array elements: "<<endl;
    for(int i = 0; i<n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Enter the sum you want: ";
    cin>> sum;
    cout<<"Sum lies between the position are : ";
    vector <int> res;
    res = get_index(arr, n, sum);
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }

}