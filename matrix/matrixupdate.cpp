/**
 * @brief You are given a matrix of dimension n*n. All the cells are initially, zero. You are given Q queries, which contains 4 integers a b c d where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix. Now, all the cells of this submatrix have to be incremented by one. After all the Q queries have been performed. Your task is to find the final resulting Matrix.
 * Note : Zero-Based Indexing is used for cells of the matrix. 
 * Input: n = 6, q = 6,
 * Queries = {
    {4,0,5,3},
    {0,0,3,4},
    {1,2,1,2},
    {1,1,2,3},
    {0,0,3,1},
    {1,0,2,4}}.
* Output: 
    2 2 1 1 1 0
    3 4 4 3 2 0 
    3 4 3 3 2 0
    2 2 1 1 1 0
    1 1 1 1 0 0
    1 1 1 1 0 0
 * @author Kanika Garg
 * @date 25 sept 2022
 * 
 */


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        // Code here
        vector<vector<int>> matrix;
        // matrix initialised to 0
        for(int i=0;i<n;i++){
            vector<int> row;
            for(int j=0;j<n;j++){
                row.push_back(0);
            }
            matrix.push_back(row);
        }
        
        
        for(int q=0; q<Queries.size(); q++){
            int a = Queries[q][0];
            int b = Queries[q][1];
            int c = Queries[q][2];
            int d= Queries[q][3];
            for(int i=a; i<=c; i++){
                for(int j=b; j<=d;j++){
                    matrix[i][j]+=1;
                }
            }
        }
        
        return matrix;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends