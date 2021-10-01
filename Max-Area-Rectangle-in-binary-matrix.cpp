#include<bits/stdc++.h>
using namespace std;

// Maximum Area Under Histogram Function

int MaxArea(vector<int>& arr){

    int i = 0;
    int n = arr.size();

    stack<int> s;

    vector<int> NSR(n);
    vector<int> NSL(n);

    // Nearest Smallest to right

    for ( i = n-1; i >= 0; i--)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        
        if(s.empty()){
            NSR[i] = n-1;
        }
        else{
            NSR[i] = s.top() -1;
        }

        s.push(i);
    }   

//////////////////////////////////////////////
    while (!s.empty())
    {
        s.pop();
    }    
/////////////////////////////////////////////

    // Nearest Smaller to Left

    for ( i = 0; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        
        if(s.empty()){
            NSL[i] = 0;
        }
        else{
            NSL[i] = s.top() +1;
        }
        s.push(i);
    }
    // Find Out Max Area

   vector<int> Height(n);
    vector<int> Area(n);

    int max_area = 0;
    for(i = 0; i<n; i++){

        Height[i] = ((NSR[i] - NSL[i])  + 1);
        Area[i] =  arr[i] * Height[i];
        max_area = max(max_area, Area[i]);

        //max_area = max(max_area, arr[i] * ((NSR[i] - NSL[i])  + 1));
    }
    return max_area;
}


// Max Area Rectangle in Binary Matrix [ 2D Matrix ---> 1D matrix ] Function

void MaxAreaUnderRectangleInBinaryMatrix(vector<vector<int>> matrix, int n){
 //vector<int> Arr = {6,2,5,4,5,1,6};

//int i = 10 + MaxArea(Arr);

vector<int> vec;

for (int j = 0; j < n; j++)
{   
    vec.push_back(matrix[0][j]);
}

int MAH_mx = MaxArea(vec);


for (int i = 1; i < n; i++)
{
    for (int j = 0; j < n; j++)
    {   
        if (matrix[i][j]==0)
        {
            vec[j] = 0;
        }
        else
        {
            vec[j]= vec[j] + matrix[i][j];
        }
    }

    MAH_mx = max(MAH_mx, MaxArea(vec));
    
}

cout<< MAH_mx;
}


int main()
{   
    vector<vector<int>> matrix{

        //test case 1 ---> O/P = 8

        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}

/*      //test case 2 ---> O/P = 6
        {0, 1, 1},
        {1, 1, 1},
        {0, 1, 1}

        //test case 3 ---> O/P = 4
        {1 1 1},
        {0 1 1},
        {1 0 0} 
*/

    };

   int n = matrix.size();

    MaxAreaUnderRectangleInBinaryMatrix(matrix,n);
    
        return 0;
}