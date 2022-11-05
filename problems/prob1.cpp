/**
 * @file prob1.cpp
 * @author Kanika Garg
 * @brief Find the time taken to print text with the given keyboard
 * @details
 * Imagine you have a special keyboard with all keys in a single row. 
 * The layout of characters on a keyboard is denoted by a string keyboard of length 26. 
 * Initially your finger is at index 0.
 * To type a character, you have to move your finger to the index of the desired character. 
 * The time taken to move your finger from index i to index j is abs(j - i).
 * Given a string keyboard that describe the keyboard layout and a string text, 
 * return an integer denoting the time taken to type string text.
 * Example 1: Input: keyboard = "abcdefghijklmnopqrstuvwxy", text = "cba" 
 * Output: 4 
 * Explanation: Initially your finger is at index 0. First you have to type 'c'.
 * The time taken to type 'c' will be abs(2 - 0) = 2 because character 'c' is at index 2.
 * The second character is 'b' and your finger is now at index 2. 
 * The time taken to type 'b' will be abs(1 - 2) = 1 because character 'b' is at index 1.
 * The third character is 'a' and your finger is now at index 1.
 * The time taken to type 'a' will be abs(0 - 1) = 1 because character 'a' is at index 0.
 * The total time will therefore be 2 + 1 + 1 = 4.
 * Constraints:
 * length of keyboard will be equal to 26 and all the lowercase letters will occur exactly once;
 * the length of text is within the range [1..100,000];
 * string text contains only lowercase letters [a-z].
 * 
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include <string>
using namespace std;


int findTime(string keyboard, string text){
    int ksize = keyboard.size(), tsize = text.size();
    if (ksize >26 or ksize<26) return -1;
    int time=0, prev_ind =0, cur_index=0;
    auto ind = [](char c, string keyboard, int ksize){
     for(int i=0; i<ksize; i++){
        if( keyboard[i] == c)return i;
     }   
     return -1;
    };
    for(int tIndex=0; tIndex<tsize; tIndex++){
        cur_index =  ind(text[tIndex], keyboard, ksize);
        time+= abs(prev_ind -cur_index ); 
        prev_ind = cur_index;
    }
    return time;
}

int main(){
    string keyboard = "abcdefghijklmnopqrstuvwxyz", text = "cba" ;
    int t = findTime(keyboard,text);
    cout<<"\nkeyboard:"<<keyboard<<"\ttext:"<<text<<" \t time:"<<t<<endl;
    keyboard = "afghijklmnopqrstuvbwxyzcde", text = "cba" ;
    t = findTime(keyboard,text);
    cout<<"\nkeyboard:"<<keyboard<<"\ttext:"<<text<<" \t time:"<<t<<endl;
    return 0;
}