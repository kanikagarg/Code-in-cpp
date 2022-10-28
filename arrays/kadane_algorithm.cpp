/**
 * @file kadane_algorithm.cpp
 * @author Kanika Garg(reachkanikagarg@gmail.com)
 * @brief 
 * @details Given an array Arr[] of N integers. 
 * Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.
 * The idea of Kadane’s algorithm is to maintain a variable max which stores the maximum sum contiguous subarray ending at current index.
 * and a variable max_sum stores the maximum sum of contiguous subarray found so far.
 * Everytime there is a positive-sum value in sum compare it with max_sum 
 * and update max_sum if it is greater than sum.
 * 
 * @version 0.1
 * @date 2022-10-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        long long maxsum = INT_MIN, sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if (sum > maxsum){
                maxsum = sum;
            }
            
            if (sum<0){
                sum=0;
            }
        }
        return maxsum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends