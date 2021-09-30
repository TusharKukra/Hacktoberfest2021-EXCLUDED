#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){

    // Map: Maps are associative containers that store elements formed by a combination of a key value and a mapped value.
    // or Map is a data structure in which data is store with its key value.

    map<int, string> m;  // here default map will be Ordered Map (all the values are in sorted order (key value))
    
    m[2] = "def";
    m[1] = "abc";
    m[15] = "ghi";

    // here 1,2,15 are the key and abc, def, ghi are their corresponing value

    // another way of inserting elements:
    m.insert( {19, "jkl" });

    //now to print them, create a iterator
    for(auto i : m){
        cout<<"Key: "<<i.first<<" "<<"Value: "<<i.second<<endl;
    }

    cout<<"Finding element (let say: 15) "<<m.count(15)<<endl;

    // erase operation
    cout<<"After Erase: ";
    m.erase(15);  // by entering Key ,we can erase key and a corresponding value
    
    for(auto i : m){
        cout<<"Key: "<<i.first<<" "<<"Value: "<<i.second<<endl;
    }


    return 0;
}
