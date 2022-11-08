/**
 * @file 557_reverse_string_words.cpp
 * @author Kanika Garg
 * @brief Leet code problem 557: 
 * @details: Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * Example 2:
 * Input: s = "God Ding"
 * Output: "doG gniD"
 * Constraints:
 * 1 <= s.length <= 5 * 104
 * s contains printable ASCII characters.
 * s does not contain any leading or trailing spaces.
 * There is at least one word in s.
 * All the words in s are separated by a single space.
 * 
 * 
 * @version 0.1
 * @date 2022-11-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<string>
using namespace std;
#define MAX_STR 50000


class Solution {
public:
    string reverseWords(string s) {
        string word;
        int index = 0, start_index = -1, last_index = -1, sz=s.size();
        while( index < sz ){
            // code required if trailing or leading spaces or more than 1 space in between words
            if(start_index == -1){
                while(char(s[index])==' '){
                    index++;
                }
                start_index = index;
            }
            if(char(s[index])==' ' or index==sz-1){
                if(start_index!=-1){
                    if(index ==sz-1){
                        last_index = index;
                    }else{
                        last_index = index-1;
                    }
                }
                
                //reverse word starting at start_index and ending at last_index;
                char c;
                for(int i=start_index, end = int((start_index+last_index)/2); i<=end; i++){
                    c=s[i];
                    s[i]=s[last_index];
                    s[last_index--]=c;
                }
                
                start_index = -1;
            }
            index++;
        } // end of while
        return s;
    }
};

int main(){

    Solution obj;
    string s;
    cout<<"\nEnter string INPUT: ";
    getline(cin,s);
    cout<<"\nOUTPUT: "<<obj.reverseWords(s)<<".";

    return 0;
}