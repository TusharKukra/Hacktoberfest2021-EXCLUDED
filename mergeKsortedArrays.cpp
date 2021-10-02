#include <iostream>
#include <vector>
using namespace std;


#include<queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>output;
    
    for(int i=0;i<input.size();i++)
    {
        for(int j=0;j<input[i]->size();j++)
        {
            pq.push(input[i]->at(j));
        }
    }
    while(!pq.empty())
    {
        output.push_back(pq.top());
        pq.pop();
    }
    
    return output;
}
int main() {
    int k;
    cin >> k;

    vector<vector<int> *> input;

    for (int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;

        for (int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current->push_back(a);
        }

        input.push_back(current);
    }

    vector<int> output = mergeKSortedArrays(input);

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}
