#include "numbers.h"
#include <iostream>
using namespace std;

int main(){

    int num = 5;
    knks::Numbers a;
    cout<<"Is 534 a prime number? "<<(a.isPrime(534)==true?"True":"false")<<endl;
    cout<<"Prime factors of 534 are ";
    a.printPrimeFactors(a.findPrimeFactors(534));

    cout<<"\nfactors of 534  as product are ";
    a.printAllFactors(a.findAllFactors(534));

    std::cout<<"\nfactors of 1024  as product are ";
    a.printAllFactors(a.findAllFactors(1024));

    cout<<"\nIs 17 a prime ? "<<(a.isPrime(17)==true?"True":"false")<<endl;
    cout<<"5! is  "<<a.factorial(num)<<endl;
    cout<<"5P3 is  "<<a.findPermutation(5,3)<<endl;
    cout<<"5C3 is  "<<a.findCombination(5,3)<<endl;
    return 0;
}