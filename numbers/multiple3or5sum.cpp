/**
 * @file multiple3or5sum.cpp
 * @author Kanika Garg
 * @brief Find the sum of all the multiples of 3 or 5 below 1000.
 * Problem statement
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * 
 * @version 0.1
 * @date 2022-09-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
int main(){
    const int three = 3;
    const int five = 5;
    int sumOfMultiples = 0;
    for(int i=3;i<1000;i++){
        if (i%three == 0  or i%five ==0){
            sumOfMultiples+=i;
        }
    }
    std::cout<<sumOfMultiples<<std::endl;
}