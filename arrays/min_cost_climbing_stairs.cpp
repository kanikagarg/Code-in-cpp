/**
 * @file min_cost_climbing_stairs.cpp
 * @author Kanika Garg
 * @brief minimum cost to reach the top of the floor. https://leetcode.com/problems/min-cost-climbing-stairs/
 * @details Given an integer array cost where cost[i] is the cost of ith step on a staircase.
 * Once you pay the cost, you can either climb one or two steps.
 * You can either start from the step with index 0, or the step with index 1.
 * Return the minimum cost to reach the top of the floor.
 * Example 1: Input: cost = [10,15,20] Output: 15 
 * Explanation: You will start at index 1. Pay 15 and climb two steps to reach the top. The total cost is 15.
 * Example 2: Input: cost = [1,100,1,1,1,100,1,1,100,1] Output: 6
 * Explanation: You will start at index 0.
 * Pay 1 and climb two steps to reach index 2.
 * Pay 1 and climb two steps to reach index 4.
 * Pay 1 and climb two steps to reach index 6.
 * Pay 1 and climb one step to reach index 7.
 * Pay 1 and climb two steps to reach index 9.
 * Pay 1 and climb one step to reach the top.the total cost is 6.
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;
#include<map>
#include <vector>

class Solution {
public:
    map<int, int> mincost;
    int minCostClimbingStairs(vector<int>& cost, int n=0) {
        int sz = cost.size();
        if (n>=sz){
            return 0;
        }else{
            if(mincost.find(n)==mincost.end()){
                int res1 = cost[n] + minCostClimbingStairs(cost, n+1); 
                int res2 =  minCostClimbingStairs(cost, n+2); 
                if(n+1 < sz){   res2 +=  cost[n+1];  }
                if(res1<res2){  
                    mincost[n]=res1;    
                    return res1;
                }else{
                    mincost[n]=res2;
                    return res2;
                }
            }else{
                return int(mincost[n]);
            }
        }
    }
};


int main(){
    Solution sol1, sol2;
    vector<int> cost1 = {10,15,20};
    cout<< "\n min cost for example 1:"<< sol1.minCostClimbingStairs(cost1)<<endl;
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout<< "\n min cost for example 2:"<< sol2.minCostClimbingStairs(cost2)<<endl;
    return 0;
}