/*Given a collection of integers that might contain duplicates, S, return all possible subsets.*/
//Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
//The subsets must be sorted lexicographically.

void util(vector<vector<int> >& result, vector<int> temp ,vector<int>& A,int n, int idx){

    for(int i=idx;i<n;i++){

        if(i>idx && A[i]==A[i-1]) continue;

        temp.push_back(A[i]);
        result.push_back(temp);
        util(result,temp,A,n,i+1);
        temp.pop_back();
    }  
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {

int n=A.size();
sort(A.begin(),A.end());

vector<vector<int> > result;
vector<int> temp;
result.push_back(temp);

util(result,temp,A,n,0);

return result;
}