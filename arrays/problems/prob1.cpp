/**
 * @file prob1.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief Leaders in an array
 * @version 0.1
 * @date 2022-10-04
 * @details description
 * Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. 
 * Example 1: Input: n = 6
 *              A[] = {16,17,4,3,5,2}
 *            Output: 17 5 2
 *            Explanation: The first leader is 17 as it is greater than all the elements to its right.  Similarly, the next leader is 5. The right most element is always a leader so it is also included. 
 * Example 2: Input:n = 5
 *            A[] = {1,2,3,4,0}
 *            Output: 4 0 
 * Your Task:
 * You don't need to read input or print anything. The task is to complete the function leader() which takes array A and n as input parameters and returns an array of leaders in order of their appearance.
 * Expected Time Complexity: O(n)
 * Expected Auxiliary Space: O(n)
 * Constraints:
 * 1 <= n <= 107
 * 0 <= Ai <= 107  
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;    
#include<algorithm>
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> leader;
        int prev_leader;
        for(int i=n-1;i>=0;i--){
            if (i==n-1){
                leader.push_back(a[i]);
                prev_leader=a[i];
            }else{
                if (a[i]>=prev_leader){
                    leader.push_back(a[i]);
                    prev_leader=a[i];
                }
            }
        }
        
        reverse(leader.begin(),leader.end());
        return leader;
        
    }
};


int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}