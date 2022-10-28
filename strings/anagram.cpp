/**
 * @file anagram.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief Given two strings a and b consisting of lowercase characters.
 *  The task is to check whether two given strings are an anagram of each other or not. 
 *  An anagram of a string is another string that contains the same characters,
 *  only the order of characters can be different. 
 *  For example, act and tac are an anagram of each other.
 * @details https://practice.geeksforgeeks.org/problems/anagram-1587115620/1
 * @version 0.1
 * @date 2022-10-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        map<char,int> dict;
        map<char,int> :: iterator it;
        for(auto c: a){
            if(dict.find(c)==dict.end()){
                // char not in dict
                dict[c]=1;
            }else{
                dict[c]+=1;
            }
        }
        
        for(auto c: b){
            if(dict.find(c)==dict.end()){
                // char not in dict
                return false;
            }else{
                dict[c]-=1;
            }
        }
        
        for(it = dict.begin(); it!=dict.end(); it++){
            if(it->second != 0){
                // unequal characters count
                return false;
            }
        }
        return true;
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends