/**
 * @file palindromePermutation.cpp
 * @author Kanika Garg
 * @brief 
 * @version 0.1
 * @date 2022-11-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
#include<string>
#include <ctime>
#include<unordered_map>
#include <cctype>
using namespace std;

/**
 * @brief Checks whether the string has palindrome Permutation or not
 * Assuming uppercase and lowecase characters to be different
 * @param s1 
 * @return true 
 * @return false 
 */
bool isPalindromePermutation(string &s1){
    unordered_map<char,int> frqMap;
    frqMap.clear();

    //O(n)      ; n char in s1
    for(auto c: s1){
        if(frqMap.find(c)==frqMap.end()){
            frqMap[c]=1;
        }else{
            frqMap[c]++;
        }
    }

    unordered_map<char, int>::iterator itr;
    int oddFreqCount = 0;
    for(itr=frqMap.begin(); itr!=frqMap.end(); itr++){
        if(itr->second%2==1)
            oddFreqCount++;
        if(oddFreqCount>1) return false;
    }
    return oddFreqCount<=1;
}



/**
 * @brief Checks whether the string has palindrome Permutation or not
 * Assuming uppercase and lowecase characters to be same
 * @param s1 
 * @return true 
 * @return false 
 */
bool isPalindromePermutationNoCase(string &s1){
    unordered_map<char,int> frqMap;
    frqMap.clear();

    //O(n)      ; n char in s1
    for(auto c: s1){
        char lc = islower(c)? c: tolower(c);
        if(frqMap.find(tolower(lc))==frqMap.end()){
            frqMap[lc]=1;
        }else{
            frqMap[lc]++;
        }
    }

    unordered_map<char, int>::iterator itr;
    int oddFreqCount = 0;
    for(itr=frqMap.begin(); itr!=frqMap.end(); itr++){
        if(itr->second%2==1)
            oddFreqCount++;
        if(oddFreqCount>1) return false;
    }
    return oddFreqCount<=1;
}


int main()
{
   time_t start, finish;
string s1, s2;
cout<<"\nEnter the string 1 ";
getline(cin, s1);
s2=s1;
// cout<<"\nEnter the string 2 ";
// getline(cin, s2);
time(&start);
cout<<"\n Is \""<<s1<<"\" is palindrome permutation ? "<<(isPalindromePermutation(s1)==true? "true":"false");
time(&finish);
cout << " Time :" << difftime(finish, start) << " seconds ["<<finish<<" - "<<start<<" ]";
time(&start);
cout<<"\n Is \""<<s2<<"\" is palindrome permutation (assuming both uppercase and lowercase characters to be same) ? "<<(isPalindromePermutationNoCase(s2)==true? "true":"false");
time(&finish);
cout << " Time :" << difftime(finish, start) << " seconds ["<<finish<<" - "<<start<<" ]";
return 0;
}