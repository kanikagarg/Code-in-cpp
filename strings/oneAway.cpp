/**
 * @file oneAway.cpp
 * @author Kanika Garg
 * @brief Check whether the given strings are one or zero edit away or not. (Edit means update, delete, add one character).
 * @version 0.1
 * @date 2022-11-20
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

/**
 * @brief method to check whether s1 and s2 are zero or one edit operation away
 * 
 * @param s1 
 * @param s2 
 * @return true 
 * @return false 
 */
bool isOneEditAway(string &s1, string &s2){
    int n=s1.size(), m=s2.size();
    if (abs(n-m)>1) return false;
    int diff =0;
    unordered_map<char,int> nMap, mMap;
    
    // O(n)
    for(int i=0; i<n; i++){
        if(nMap.find(s1[i])==nMap.end()){
            nMap[s1[i]]=1;
        }else nMap[s1[i]]++;
    }

    // O(m)
    for(int i=0; i<m; i++){
        if(mMap.find(s2[i])==mMap.end()){
            mMap[s2[i]]=1;
        }else mMap[s2[i]]++;
    }

    unordered_map<char,int>::iterator itr;
    int ncharDiffer =0, mcharDiffer = 0;

    for(itr=nMap.begin(); itr!=nMap.end(); itr++){
        char key=itr->first;

        unordered_map<char,int>::iterator itrKey=mMap.find(key);
        if(itrKey==mMap.end()){
            // key not found in string 2 which is present in s1
            ncharDiffer++;
            diff+=itr->second;
        } else{
            diff+=abs(itr->second - itrKey->second);
            mMap.erase(itrKey);
        }

        if (diff>1) return false;
    }

    int mDiff = 0;
    for(itr=mMap.begin(); itr!=mMap.end(); itr++){
        mDiff+=itr->second;
        mcharDiffer++;
        if (mDiff>1) return false;
    }

    if(mcharDiffer==ncharDiffer or ncharDiffer==1 or mcharDiffer==1){
        diff -= 1;
    }
    
    return (diff+mDiff)<=1;
}


int main()
{
   time_t start, finish;
    string s1, s2;
    cout<<"\nEnter the string 1 ";
    getline(cin, s1);
    cout<<"\nEnter the string 2 ";
    getline(cin, s2);
    time(&start);
    cout<<"\n whether \""<<s1<<"\" and \""<<s2<<"\" are one edit away ? "<<(isOneEditAway(s1, s2)==true? "true":"false");
    time(&finish);
    cout << " Time :" << difftime(finish, start) << " seconds ["<<finish<<" - "<<start<<" ]";
    return 0;
}