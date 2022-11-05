/**
 * @file largestPalindromeProduct.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * @version 0.1
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<math.h>
#include<string>
int checkDigitCount(long num){
   int digits =0;
   long div, rem;
   do {
    div = long(num/10);
    rem = long(num%10);
    digits++;
    num=div;
   }while(div != 0);
   return digits;
};

bool palindromCheck(long num){
    int  digicount = checkDigitCount(num);
    std::string st = std::__cxx11::to_string(num);
    for(int i=0; i<digicount/2; i++){
        if (!(st[i]==st[digicount-i-1])){
            return false;
        }
    }
return true;
};



int main(){
    int test;
    std::cin>>test;
    while(test--){
        int digit;
        std::cout<<"Enter digits";
        std::cin>>digit;
        int md1=0, md2=0;
        while(digit--){
            md1 += 9*pow(10,digit); 
        }
        md2=md1;
        long res = md1*md2;
        std::string pal = (palindromCheck(res)==0? "false" : "True");
        std::cout<<"\n"<<md1<<" * "<<md2<<" = "<<res<<"\ndigits of res = "<<checkDigitCount(res)<<"\n ispalindrome "<<pal;
    }

    return 0;
}