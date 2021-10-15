#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// int main(){
//     string str= "athsjkjsbmccbk";

//     //convert into upper case

//     for(int i=0;i<str.size();i++){
//         if(str[i]>='a' && str[i]<='z'){
//             str[i] -= 32;
//         }
//     }
//     cout<<str<<endl;

//     // convert into lower case

//     for(int i=0;i<str.size();i++){
//         if(str[i]>='A' && str[i]<='Z'){
//             str[i] += 32;
//         }

//     }
//     cout<<str<<endl;

//     return(0);
// }

// using inbuilt function

int main()
{
    string s = "gvasajaa";
    transform(s.begin(), s.end(), ::toupper);
    cout << s << endl;

    transform(s.begin(), s.end(), ::tolower);
    cout << s << endl;
}
