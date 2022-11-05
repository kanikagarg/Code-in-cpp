/**
 * @file climbingStairs.cpp
 * @author kanik Garg
 * @brief Climbing Stairs
 * @details You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 * @version 0.1
 * @date 2022-11-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
using namespace std;
#include<map>

class Solution {
public:
    map<int,int> cost;
    int climbStairs(int n) {
        if (n<0){
            return 0;
        }else if (n==2){
            cost[2]=2;
            return 2;
        }else if (n==1){
            cost[1]=1;
            return 1;
        }else if(n==0){
            cost[0]=0;
            return 0;
        }
        if ( cost.find(n-1) == cost.end() ){
        cost[n-1] = climbStairs(n-1);
        }
        if ( cost.find(n-2) == cost.end()){
        cost[n-2] = climbStairs(n-2);
        }
        cost[n]=cost[n-1]+cost[n-2];
        return int(cost[n]);
    }
};

int main(){
    Solution Solution;
    int t, n;
    cout<<"\nEnter test case count";
    cin>>t;
    while(t--){
        cout<<"\nEnter stairs count (n):";
        cin>>n;
        cout<<"\n"<<Solution.climbStairs(n)<<" distinct ways to climb "<<n<<" stairs.\n";
    }
    return 0;
}