/**
 * @file prob1.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief  Interleaving Strings
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * @details description
 * Given A, B, C, find whether C is formed by the interleaving of A and B.
    Input Format:*
    The first argument of input contains a string, A.
    The second argument of input contains a string, B.
    The third argument of input contains a string, C.
    Output Format:

    Return an integer, 0 or 1:
        => 0 : False
        => 1 : True
    Constraints:

    1 <= length(A), length(B), length(C) <= 150
    Examples:

    Input 1:
        A = "aabcc"
        B = "dbbca"
        C = "aadbbcbcac"

    Output 1:
        1
        
    Explanation 1:
        "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

    Input 2:
        A = "aabcc"
        B = "dbbca"
        C = "aadbbbaccc"

    Output 2:
        0

    Explanation 2:
        It is not possible to get C by interleaving A and B.    
 */
#include<iostream>
using namespace std;
#include<string>

class Solution{
    public:
    int isInterleave(string A, string B, string C);
};
int Solution::isInterleave(string A, string B, string C) {
    bool flag = false;
    if (0<A.size() and A[0]==C[0]){
        if (C.substr(1,C.size()-1).empty()){
            flag = true;
        }else{
            flag |= isInterleave(A.substr(1,A.size()-1), B, C.substr(1,C.size()-1));
        }
    };
    if (0<B.size() and B[0]==C[0]){
        if (C.substr(1,C.size()-1).empty()){
            flag = true;
        }else{
            flag |= isInterleave(A, B.substr(1,B.size()-1), C.substr(1,C.size()-1));
        }
    }; 
    return flag;
}

int main(){
    string a, b, c;
    cout<<"Enter first string ";
    cin>>a;
    cout<<"Enter second string "; 
    cin>>b;
    cout<<"Enter check string ";
    cin>>c;
    Solution sol;
    cout<<"check string "<< (sol.isInterleave(a,b,c)==1?"can":"cannot")<<" be made while interleaving a and b ";
    return 0;
}