#include <iostream>
using namespace std;

void subseq(string s,string ans)
{
    if(s.length()==0) {cout<<ans<<endl; return;}

    char ch = s[0];
    string temp = s.substr(1);
    subseq(temp,ans);
    subseq(temp,ans+ch);
    // subseq(temp,ans+to_string((int)(ch))); //for ascii code also
}

int main()
{
    subseq("AB","");
    // cout<<"\n";
    return 0;
}