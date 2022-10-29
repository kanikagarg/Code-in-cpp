#include"numbers.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <string>

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
     for(int i=2, till=sqrt(num); i<=till; i++){
         if (num%i==0){
             return false;
         }
     }
     return true;
 }

 std::vector<int> Numbers::findFistNPrimeNumbers(int n){
     std::vector<int> primenumbers;
     for(int i=2; n>0; i++){
         if (isPrime(i)){
             primenumbers.push_back(i);
             n--;
         }
     }
     return primenumbers;
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

 std::string Numbers::findMachineNumber(int num){
    std::string binary_representation="";
    std::vector<int> bits;
    if (num<0){
        // number is negative
        return binary_representation;
    }else{
        // number is positive
        // non decimal number
        while( num!=0){
            int rem = num %2;
            binary_representation.push_back(char(rem));
            num = floor(num/2);
        }
        while(binary_representation.size()>0){
            bits.push_back(int(binary_representation.back()));
            binary_representation.pop_back();
        }

        for(int i=0; i<bits.size(); i++){
            binary_representation.push_back('0'+bits[i]);
        }
        return binary_representation;
        }
 };
}
