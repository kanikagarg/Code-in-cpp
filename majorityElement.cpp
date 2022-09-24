/**
 * @brief Majority element in an array
 * 
 * Given an array A of N elements. Find the majority element in the array. 
 * A majority element in an array A of size N is an element that appears more than N/2 times in the array
 * If no majority element is present in the array return -1
 */

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        map<int,int> ele;
        map<int,int> :: iterator iter;
        for(int i=0; i<size; i++){
            // if (ele.count(a[i]) == 0)
            if (ele.find(a[i])==ele.end() ){
                ele[a[i]]=1;
            }else{
                ele[a[i]] += 1;
            }
        }
        
        
        for(iter=ele.begin(); iter!=ele.end(); iter++){
            if (iter->second > size/2){
                return iter->first;
            }
        }
       return -1; 
        
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends