/**
 * @file fastModularExponential.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/**
 * find value of a^n % mod
*/
#include<iostream>
using namespace std;

long long raiseton(int a,int n){
    if (n == 1){
        return a;
    }
    if(n%2==0){
        
        long long res = raiseton(a, n/2);
        return res * res;
        
    } else{
        long long res = raiseton(a, (n-1)/2);
        return a * res*res;
    }
}




int main(){
    int a = 5, n=13, mod=1000000007;
    long long res = raiseton(a,n);
    cout << "\n" << res%mod;
    return 0;
}