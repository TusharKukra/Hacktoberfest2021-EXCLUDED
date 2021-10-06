#include<bits/stdc++.h>
int main()
{
    using namespace std;
    //ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int t;
    cin>>t;
    for(int test_case = 1;test_case<=t;test_case++)
    {
        int N,K;
        cin>>N>>K;
        string S;
        cin>>S;
        int score=0;
        for(int i = 0;i<N/2;i++){
            score+=(S[i]!=S[N-1-i]);
        }
        cout<<"Case#"<<test_case<<": "<<abs(score-K)<<'\n';
    }
    return 0;
}
