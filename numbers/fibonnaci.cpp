/**
 * @file fibonnaci.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief find fibonacci of a number
 * @version 0.1
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
class Solution {
public:
    int fib(int n) {
        if(n==0){
            return 0;
        }else if(n==1){
            return 1;
        }else{
            return fib(n-1)+fib(n-2);
        }
    }
};