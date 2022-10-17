/**
 * @file pangram.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief https://leetcode.com/problems/check-if-the-sentence-is-pangram
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 */


#include<map>
using namespace std;
class Solution {
public:
    /**
     * @brief following method finds whether the sentence is a pangram or not
     * Time Complexity O(sizeof(sentence))
     * Space Complexity O(1)
     * 
     * @param sentence 
     * @return true 
     * @return false 
     */
    bool checkIfPangram(string sentence) {
        
        char ch;
        for (int i=0; i<26;i++){
            ch = 'a' + i;
            bool charfound = false;
            for(auto c:sentence){
                if (c==ch){
                    charfound = true;
                    break;
                }
            }
            if (!charfound) return false;
        }
        return true;
    }
    /**
     * @brief the following code is a bit slower and less memory efficient than the above solution
     * Time Complexity : O(sizeof(sentence))
     * Space Complexity : O(1) 
     * 
     * @param sentence 
     * @return true 
     * @return false 
     */
    bool checkIfPangram_sol2(string sentence) {
        bool isPangram = false;
        map<int, int> chmap;
        
        for(int i=0; i<sentence.size(); i++){
            if (chmap.find( int(sentence[i])) == chmap.end()){
            chmap [ int(sentence[i])] +=1; 
            }else {
                chmap [ int(sentence[i])] =1; 
            }    
        }
        
        for(char ch ='a', z='z'; ch<=z; ch++){
            if( chmap.find(int(ch))==chmap.end())
            {
                isPangram = false;
                return isPangram;
            }
        }
        isPangram = true;
        return isPangram;
        
    }
};