//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends


// User function template for C++
class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int beg = 0;
        int end = n-1;
        int mid;
        while(beg<=end){
            mid =int((beg+end)/2);
            if (arr[mid]==k){
                return mid;
            }else if (arr[mid]>k){
                end=mid-1;
            }else{
                beg = mid+1;
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
        for(int i = 0;i<n;i++) cin >> arr[i];
        int key;
        cin>>key;
        Solution obj;
        cout << obj.binarysearch(arr, n, key) << endl;
    }

    return 0;
}
// } Driver Code Ends