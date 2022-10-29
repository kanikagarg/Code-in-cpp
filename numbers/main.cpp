#include "numbers.h"
#include <iostream>
using namespace std;

int main(){

    int num = 5;
    knks::Numbers a;
    cout<<"Is 4 a prime number? "<<(a.isPrime(4)==true?"True":"false")<<endl;
    cout<<"Prime factors of 4 are ";
    a.printPrimeFactors(a.findPrimeFactors(4));

    cout<<"\nGive n to find first n prime numbers";
    int n;
    cin>>n;
    cout<<"\nFirst "<<n<<" Prime numbers are";
    a.printPrimeFactors(a.findFistNPrimeNumbers(n));

    cout<<"\nfactors of 534  as product are ";
    a.printAllFactors(a.findAllFactors(534));

    std::cout<<"\nfactors of 1024  as product are ";
    a.printAllFactors(a.findAllFactors(1024));

    cout<<"\nIs 17 a prime ? "<<(a.isPrime(17)==true?"True":"false")<<endl;
    cout<<"5! is  "<<a.factorial(num)<<endl;
    cout<<"5P3 is  "<<a.findPermutation(5,3)<<endl;
    cout<<"5C3 is  "<<a.findCombination(5,3)<<endl;
    cout<<"Machine number for 1234 base 10 is "<<a.findMachineNumber(1234)<<endl;
    return 0;
}