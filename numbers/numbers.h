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
            /**
             * @brief The original code is the sign bit of the machine number plus the absolute value of the truth value of the machine number
             * 
             */
            /**
             * The inverse code is obtained from the original code. The inverse code of non-negative numbers is the same as the original code. The inverse of negative numbers is to flip every bit of the original code except the sign bit. Flip means changing 00 to 11 or changing 11 to 00
            */
           /**
            * Complement code

The complement code is obtained from the inverse code. The complement code of non-negative numbers is the same as the original code and the inverse code. The complement of negative numbers is obtained by adding 1 to the inverse code.
           */
    };
}