/**
 * @file licencekey.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief Licence key reformatting
 * @version 0.1
 * @date 2022-10-29
 * @details
 * You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.
 * We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.
 * Return the reformatted license key.
 * Example 1: Input: s = "5F3Z-2e-9-w", k = 4 Output: "5F3Z-2E9W" Explanation: The string s has been split into two parts, each part has 4 characters. Note that the two extra dashes are not needed and can be removed.
 * Example 2: Input: s = "2-5g-3-J", k = 2 Output: "2-5G-3J" Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.
 * Constraints: 1 <= s.length <= 105 ; s consists of English letters, digits, and dashes '-'. 1 <= k <= 104
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cctype>
using namespace std;


string licenseKeyFormatting(string s, int k) {
        string res="";
        int it = s.size()-1;
        int sz=0;
        int dashcount = 0, charc =0;
        for(int j=0, i=1; it>=0; it--,j++){
            if(i%(k+1) != 0){
                if(char(s[it]) != '-' and char(s[it]) != ' ' ){
                    res.push_back(toupper(s[it]));
                    i++;                    
                }else{
                    j = j-1;
                }              
            }else{
                res.push_back('-');
                dashcount++;
                i++;
                it =it+1;
            }    
            sz=j+1;
            charc =i;
        }
        res =  res.substr(0,sz);
        for(int i=0, sz=res.size(); i<sz/2 ; i++){
            char c  = res[i];
            res[i]=res[sz-1-i];
            res[sz-1-i]=c;
        }
        return res;
        
    }

int main(){
    string s ="5F3Z-2e-9-w"; int k =4;
    cout<<licenseKeyFormatting(s,k)<<endl;     // output "5F3Z-2E9W"
    cout<<licenseKeyFormatting("aaaa",2)<<endl;// AA-AA
    cout<<licenseKeyFormatting("aaaaa",2)<<endl; // A-AA-AA
    cout<<licenseKeyFormatting("AS-sdf-657ss-fe",3)<<endl; // ASS-DF6-57S-SFE   
     
    return 0;
}
