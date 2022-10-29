#pragma once
#include <vector>
#include <string>


namespace knks{
    class Numbers{
        public:
            bool isPrime(int num);
            int factorial(int num);
            double findPermutation(int n, int r);
            std::vector<int> findFistNPrimeNumbers(int n);
            double findCombination(int n, int r);
            std::vector<int> findPrimeFactors(int num);
            std::vector<int> findAllFactors(int num);
            void printAllFactors(std::vector<int> num);
            void printPrimeFactors(std::vector<int> num);
            /**
             * @brief The binary representation of a number in a computer is called its machine number. 
             * 
             * @param num 
             * @return std::string 
             */
            std::string findMachineNumber(int num);
    };
}