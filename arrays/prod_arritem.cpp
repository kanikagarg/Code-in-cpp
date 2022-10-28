/**
 * @file prod_arritem.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief Product of Array Except Self
 * @details Leetcode problem https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/827/
 * @version 0.1
 * @date 2022-10-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;
#include <vector>



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> zerosindex;
        bool prod_set = false;
        vector<int> answers;
        int prodall;
        
        for(int i=0; i<sz;i++){
            if(nums[i]==0){
                zerosindex.push_back(i);
            }else{
              if(prod_set==false){
                 prodall = nums[i];
                 prod_set = true;
              }else{
                  prodall *= nums[i];
              }
            }
        } //end of for loop
        int zerocount = zerosindex.size();
        if(zerocount > 1){
            // all answers are zero
            for(int i=0; i<sz; i++){
                answers.push_back(0);
            }
            return answers;
        }else if(zerocount == 1){
            //only one zero element
            for(int i=0; i<sz; i++){
                if (nums[i]!=0){
                    answers.push_back(0);
                }  else {
                    answers.push_back(prodall);
                }             
            } 
            
        }else {
            // no zero element
            for(int i=0; i<sz; i++){
                answers.push_back(prodall);
                answers[i] /= nums[i];                 
            }            
        }
        return answers;
    }
};
// driver code
int main(){
    int n;
    cin >> n;
    vector<int> input;
    vector<int> result;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        input.push_back(val);
    }
    Solution sol;
    result = sol.productExceptSelf(input);
    for(int i=0; i<n;i++){
        cout<<result[i];
        if(i!=n-1)
        cout<<" ";;
    }
    return 0;
}