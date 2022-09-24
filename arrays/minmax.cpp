/**
 * @file minmax.cpp
 * @author kanika
 * @brief Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.You should make minimum number of comparisons. 
 * @version 0.1
 * @date 2022-09-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    int solve(vector<int> &A);
};

int Solution::solve(vector<int> &A) {
    int min= A[0], max=A[0];
    for (int i=1; i<A.size(); i++){
        if (A[i]<min){
            min=A[i];
        }else if(A[i]>max){
            max=A[i];            
        }
    }
    return min+max;
}



int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        vector<int> arr;
        int input;
        for(int i=0;i<n;i++){
            cin>>input;
            arr.push_back(input);
        }
        
        Solution ob;
        cout<<ob.solve(arr);
    }
}