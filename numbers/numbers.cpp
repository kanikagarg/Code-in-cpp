#include"numbers.h"
#include <math.h>
#include <vector>
#include <iostream>

namespace knks{
 int Numbers::factorial(int num){
     if (num <=1){
         return 1;
     };
     int fact = 1;
     for(int i=num; i>1;i--){
         fact*=i;
     }
     return fact;
 }

 bool Numbers::isPrime(int num){
     if(num < 2){
         return false;
     };
     for(int i=2, till=sqrt(num); i<till; i++){
         if (num%i==0){
             return false;
         }
     }
     return true;
 }

 double Numbers::findPermutation(int n, int r){
    if ( 0<=r and r<=n){ 
     int num = factorial(n);
     int denom = factorial(n-r);
     double res = num/denom;
     return (res) ;
    }else{
        return -1;
    }
 }
 double Numbers::findCombination(int n, int r){
    if ( 0<=r and r<=n){

     double num = findPermutation(n,r);
     int denom = factorial(r);
     if (num!=-1){
         return (num/denom) ;
     }else{
         return -1;
     }
     
    }else{
        return -1;
    }
 }

 std::vector<int> Numbers::findPrimeFactors(int num){
     std::vector<int> pf;
     if (isPrime(num)){
         pf.push_back(num);
         return pf;
     };

     for(int i=2; i<=num; i++){
         if (isPrime(i)){
            if(num%i==0){        
            pf.push_back(i);
            while(num%i==0){
                num = num/i;
            };
            }
         }
     }
    return pf;
 }

 std::vector<int> Numbers::findAllFactors(int num){
     std::vector<int> pf;
     if (isPrime(num)){
         pf.push_back(num);
         return pf;
     };

     for(int i=2; i<=num; i++){
         if (isPrime(i)){
            if(num%i==0){        
           
            while(num%i==0){
                pf.push_back(i);
                num = num/i;
            };
            }
         }
     }
    return pf;
 }

 void Numbers::printAllFactors(std::vector<int> factors){
    for(int i=0, till=factors.size(); i<till; i++){
        std::cout<<factors[i];
        if(i<till-1){
            std::cout<<" * ";
        }
    }
 };

void Numbers::printPrimeFactors(std::vector<int> factors){
    for(int i=0, till=factors.size(); i<till; i++){
        std::cout<<factors[i];
        if(i<till-1){
            std::cout<<" , ";
        }
    }
 };
}
