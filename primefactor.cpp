/**
 * @file primefactor.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief 
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 * @version 0.1
 * @date 2022-09-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<vector>

class Factors{
    private:
        long data_;
        std::vector<long> dataFactors_; 

    public:
        Factors(long data){
            data_=data;
            dataFactors_= getFactors();
        }
        /**
         * @brief Get the list of the factors of the numbers
         * 
         * @return std::vector<long> 
         */
        std::vector<long> getFactors();
        /**
         * @brief Get the prime factors 
         * 
         * @return long 
         */
        long getData();
        /**
         * @brief Get the Largest prime Factor
         * 
         * @return long 
         */
        long getLargestFactor();
        /**
         * @brief print the object of the Factor's class 
         * 
         * @param os 
         * @param fact 
         * @return ostream& 
         */
        friend std::ostream & operator<<(std::ostream &os, const Factors &fact){
            os<<"\nfactorial of "<<fact.data_<<" are ";
            std::vector<long> facts = fact.dataFactors_;
            for(int i=0; i<facts.size();i++){
                os<<facts[i]<<",";
            }
            os<<std::endl;
            return os;
        }
};


long Factors::getLargestFactor(){
    long largest = dataFactors_[0];
    for(int i=1; i<dataFactors_.size(); i++){
        if ( dataFactors_[i]>largest){
            largest=dataFactors_[i];
        };
    }
    return largest;
};
long Factors::getData(){
    return this->data_;
};

std::vector<long> Factors::getFactors(){
    std::vector<long> res;
    long i=2;
    long data = data_;
    while(data!=1 and data>1){
        if ( int(data%i)==0 ){
            res.push_back(i);
        };
        while(data%i==0){
            data = long(data/i);
        };
        i++;
    };
    return res;
};


int main(){
    int t;
    std::cout<<"Enter test cases count";
    std::cin>>t;
    while(t--){
        long num = 600851475143;
        std::cout<<"Enter number to find prime factors"<<std::endl;
        std::cin>>num;
        Factors *fact = new Factors(num);
        std::cout<<*fact;;
        std::cout<<"Largest factor  "<<fact->getLargestFactor()<<std::endl;
    }
    
}