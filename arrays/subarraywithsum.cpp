/**
 * @brief Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

    In case of multiple subarrays, return the subarray which comes first on moving from left to right.

    

    Example 1:

    Input:
    N = 5, S = 12
    A[] = {1,2,3,7,5}
    Output: 2 4
    Explanation: The sum of elements 
    from 2nd position to 4th position 
    is 12.
    

    Example 2:

    Input:
    N = 10, S = 15
    A[] = {1,2,3,4,5,6,7,8,9,10}
    Output: 1 5
    Explanation: The sum of elements 
    from 1st position to 5th position
    is 15.
    

    Your Task:
    You don't need to read input or print anything. The task is to complete the function subarraySum() which takes arr, N and S as input parameters and returns an arraylist containing the starting and ending positions of the first such occurring subarray from the left where sum equals to S. The two indexes in the array should be according to 1-based indexing. If no such subarray is found, return an array consisting only one element that is -1.

    

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(1)

 

    Constraints:
    1 <= N <= 105
    1 <= Ai <= 109

 
 * 
 */



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        vector <int> subarray;
        long long sum=0;
        subarray.push_back(-1);
        // i for ith index and pi for last index removed 
        int left = 0, right =0;
        while(right<n and sum!=s)
        {
            sum+=arr[right++];
            while (sum>s){     
                sum-=arr[left++];
            };
        }
        if (sum>s){
            while (sum>s){     
                sum-=arr[left++];
            };
        }
        
        if (sum==s and left<right){
            subarray[0]=left+1;
            subarray.push_back(right);
            return subarray;
        }else 
        return subarray;
        // Your code here
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends