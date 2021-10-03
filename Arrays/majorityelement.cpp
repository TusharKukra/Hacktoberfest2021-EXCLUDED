// Example 
//Input: nums = [3,2,3]
//Output: 3

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>counter;
        for(int num:nums){
            if(++counter[num]>nums.size()/2){
                return num;
            }
        }
        return 0;  
    }
};
