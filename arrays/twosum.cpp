/**
 * @file twosum.cpp
 * @author Kanika garg ( reachkanikagarg@gmail.com)
 * @brief https://leetcode.com/problems/two-sum
 * @version 0.1
 * @date 2022-10-17
 * @details 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * Constraints:
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * Only one valid answer exists.
 * Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
 * @copyright Copyright (c) 2022
 * 
 */

#include <map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief this method returns the vector containing indices of elements whose sum is equal to target
     * in the nums list     * 
     * @param nums 
     * @param target 
     * @return vector<int> 
     */
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> mp;
    for(int i =0; i<nums.size(); i++){
        mp[nums[i]]=i;
    }
    vector<int> s;
    map<int,int>::iterator it;
    for(int i =0; i<nums.size(); i++){
        it = mp.find(target-nums[i]);
        if(it != mp.end() and i!=it->second){
            s.push_back(i);
            s.push_back(it->second);
            break;
        }
    }
    return s;       
    }
};