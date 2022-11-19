/**
 * @file checkPermutation.cpp
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
using namespace std;

bool checkPermutation(string &s1, string &s2 ){
    unordered_map<char, int> chmap;
    //O(n)
    for( auto c: s1){
        if(chmap.find(c)==chmap.end()){
            chmap[c]=1;
        }else chmap[c]++;
    }
    //O(m)
    for( auto c: s2){
        if(chmap.find(c)==chmap.end()){
            return false;
        }else chmap[c]--;
    }

    for(auto c: chmap){
        if (c.second!=0) return false;
    }

    return true;
}


int main()
{
   time_t start, finish;
   string s1, s2;
    cout<<"Enter the string 1 ";
    getline(cin, s1);
    cout<<"Enter the string 2 ";
    getline(cin, s2);
    time(&start);
    cout<<"whether \""<<s1<<"\"  is  permutation of \""<<s2<<"\" ? "<<(checkPermutation(s1, s2)==true? "true":"false");
    time(&finish);
    cout << " Time :" << difftime(finish, start) << " seconds ["<<finish<<" - "<<start<<" ]";
return 0;
}