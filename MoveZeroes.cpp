#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {

    /* Alternative solution without swap algorithm
int nonZeros = 0;

for (int i = 0; i < nums.size(); i++) {
if (nums[i] != 0)
  nums[nonZeros++] = nums[i];
}

for (int i = nonZeros; i < nums.size(); i++) {
nums[i] = 0;
}

for (auto it : nums)
std::cout << it << " ";

    */
    // Optimal solution with swap
    for (int nonZeross = 0, cur = 0; cur < nums.size(); cur++) {
      if (nums[cur] != 0) {
        std::swap(nums[nonZeross++], nums[cur]);
      }
    }

    for (auto it : nums) {
      std::cout << it << " ";
    }
  }
};

int main() {
  std::vector<int> nums = {0, 1, 0, 3, 12};
  Solution s;
  s.moveZeroes(nums);
}
