#include<bits/stdc++.h>
using namespace std;
int main()
{
//o(n)
string s="Kalyan";
  int len=s.length();
        int high=0;int i=0;
        vector<int>lastindex(no_of_char,-1);
        for(int j=0;j<len;j++)
        {
           i=max(i,lastindex[s[j]]+1);
            high=max(high,j-i+1);
            lastindex[s[j]]=j;
        }
        cout<<high<<endl;


o(n^2)
int n = s.size(); 
	int res = 0; // result 

	for (int i = 0; i < n; i++) { 
		
		// Note : Default values in visited are false 
		vector<bool> visited(256); 

		for (int j = i; j < n; j++) { 

			// If current character is visited 
			// Break the loop 
			if (visited[s[j]] == true) 
				break; 

			// Else update the result if 
			// this window is larger, and mark 
			// current character as visited. 
			else { 
				res = max(res, j - i + 1); 
				visited[s[j]] = true; 
			} 
		} 

		// Remove the first character of previous 
		// window 
		visited[s[i]] = false; 
	} 
	cout<<res;

return 0;
}
