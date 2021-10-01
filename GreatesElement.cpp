#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> replaceElements(std::vector<int> &arr) {
    // Solution with double loop
    //
    int max = 0;
    for (int i = 0; i < arr.size(); i++) {
      max = 0;
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] > max) {
          max = arr[j];
        }
      }
      arr[i] = max;
    }

    arr[arr.size() - 1] = -1;

    return arr;

    // Alternate solution

    /*

           // alternate solution using *max_element

       for(int i = 0; i < arr.size(); i++){
               if(arr.begin() + 1 + i < arr.end()){
                    int g = *max_element(arr.begin() + i + 1, arr.end());
                    arr[i] = g;
               }
       }

       arr[arr.size() - 1] = -1;
       return arr;
       */
  }
};

int main() {
  std::vector<int> arr = {0, 1, 2, 3};

  Solution s;
  s.replaceElements(arr);
  for (auto i : arr)
    std::cout << i << " ";
}
