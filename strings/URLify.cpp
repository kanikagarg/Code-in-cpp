/**
 * @file URLify.cpp
 * @author Kanika Garg
 * @brief Write a method to replace all spaces in a string with '%20'.
 *  You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
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
using namespace std;
/**
 * @brief replaces space character with %20
 * 
 * @param s 
 */
void urlify(string &s){
    for(int i=0, sz=s.size(); i<sz; i++){
        if(s[i]==' '){
            for(int j=sz-1; j-2>i;j--)
                s[j]=s[j-2];
            s[i]='%';
            s[i+1]='2';
            s[i+2]='0';
        }
    }
}

int main()
{
    time_t start, finish;
    string s1="i like coding    ", s2;
    // cout<<"Enter the string 1 ";
    // getline(cin, s1);
    s2=s1;
    time(&start);
    urlify(s1);
    time(&finish);
    cout<<"\nBefore URLify : \""<<s2<<"\"";
    cout<<"\n After :\""<<s1<<"\"";
    cout << "\n Time :" << difftime(finish, start) << " seconds ["<<finish<<" - "<<start<<" ]";
    return 0;
}