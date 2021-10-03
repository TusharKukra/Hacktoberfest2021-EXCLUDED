/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.*/

void util(vector<int>& A, int B, vector<vector<int> >& ans, vector<int>& temp,int idx, int sum){
       
    
    if(sum==B){
        ans.push_back(temp);
        return ;
    }
    else if(sum>B) return ;
    
    for(int i=idx;i<A.size();i++){  
        
        if(A[i]>B) return;
        if(i>idx && A[i]==A[i-1]) continue;

        temp.push_back(A[i]);
        util(A,B,ans,temp,i+1,sum+A[i]);
        temp.pop_back();
    }   
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
 
    sort(A.begin(),A.end());
   
    vector<vector<int> > ans;
    vector<int> temp;
    int sum=0;
   
    util(A,B,ans,temp,0,sum);
    
    return ans;
      
}