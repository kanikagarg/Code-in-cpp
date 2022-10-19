/**
 * @file primenumber_sieve_of_eratosthenes.cpp
 * @author your name (reachkanikagarg@gmail.com)
 * @brief to find all the prime numbers in the range 1, n
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int>  findPrimes(int n){
    vector<int> prime;
    if (n<=1){
        return prime;
    }
    vector<int> numbers(n+1, 1);
    numbers[0]=0;
    numbers[1]=0;
    for(int i=2; i<n; i++){
        if (numbers[i]!=0){
            if (!((i*2)>n)){
            for(int k=2; (i*k)<=n; k++){
                numbers[i*k]=0;
            }
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(numbers[i]==1){
            prime.push_back(i);
        }
    }
    
    return prime;
}

void printvector(vector<int> res){
    for(int i=0; i<res.size(); i++){
        cout<<" "<<res[i]<<",";
    }
    cout<<"\n";
}

int main(){
    int t;
    cin>>t;
    while( t-- >0){
        int n;
        cout<<"\nEnter value of n";
        cin >> n;
        vector<int> res = findPrimes(n);
        cout<<"\nprime numbers till "<<n<<" are";
        printvector(res);
          
    }
    return 0; 
}