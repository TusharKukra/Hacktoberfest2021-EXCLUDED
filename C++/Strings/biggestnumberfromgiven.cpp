#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s="6491279911";

    sort(s.begin(),s.end(),greater<int>());
    cout<<s<<endl;
}