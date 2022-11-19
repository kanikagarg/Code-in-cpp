/**
 * @file isUnique.cpp
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
#include<unordered_set>
#include <ctime>
using namespace std;

/**
 * @brief isUnique determines whether the string is having all unique characters or not
 * @details Time Complexity: O(n*n), Space Complexity O(1) where n is the number of characters in the string
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool isUnique(string s){
    int sz= s.size();
    for(int i=0; i<sz; i++)
        for(int j=i+1; j<sz; j++)
            if(s[i]==s[j]) return false;
    return true;
}

/**
 * @brief isUnique_ determines whether the string is having all unique characters or not
 * @details Time Complexity: O(n), Space Complexity O(n) where n is the number of characters in the string
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool isUnique_(string s){
    unordered_set<char> charSet;
    for(int i=0, sz= s.size(); i<sz; i++)
    {    if (charSet.count(s[i])==1) return false;
        charSet.insert(s[i]);
    }
    charSet.clear();
    return true;
}


int main()
{   
    time_t start, finish;
    string s1, s2;
    cout<<"\nEnter string 1 ";
    getline(cin, s1);
    cout<<"\nEnter string 2 ";
    getline(cin, s2);
    time(&start);
    cout<<"\n String 1 : "<<s1<<" is unique? "<<(isUnique(s1)==true? "true":"false");
    time(&finish);
	cout << " Time :" << difftime(finish, start) << " seconds ["<<finish<<" - "<<start<<" ]";
    time(&start);
    cout<<"\n String 2 : "<<s2<<" is unique? "<<(isUnique_(s2)==true? "true":"false");
    time(&finish);
	cout << " Time :" << difftime(finish, start) << " seconds ["<<finish<<" - "<<start<<" ]";
 
    return 0;
}