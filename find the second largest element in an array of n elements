#include <iostream>
using namespace std;
int main(){
   int n, num[50], largest, second;
   cout<<"Enter number of elements: ";
   cin>>n;
   for(int i=0; i<n; i++){
      cout<<"Enter Array Element"<<(i+1)<<": ";
      cin>>num[i];
   }
   /* Here we are comparing first two elements of the
    * array, and storing the largest one in the variable
    * "largest" and the other one to "second" variable.
    */
   if(num[0]<num[1]){ 
      largest = num[1];
      second = num[0];
   }
   else{ 
      largest = num[0];
      second = num[1];
   }
   for (int i = 2; i< n ; i ++) {
      /* If the current array element is greater than largest
       * then the largest is copied to "second" and the element
       * is copied to the "largest" variable.
       */
      if (num[i] > largest) {
         second = largest;
         largest = num[i];
      }
      /* If current array element is less than largest but greater
       * then second largest ("second" variable) then copy the
       * element to "second"
       */
      else if (num[i] > second && num[i] != largest) {
         second = num[i];
      }
   }
   cout<<"Second Largest Element in array is: "<<second;
   return 0;
}
