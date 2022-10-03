/**
 * @brief Find max possible time
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @details You are given a string that represents time in the format hh:mm. Some of the digits are blank (represented by ?). Fill in ? such that the time represented by this string is the maximum possible. Maximum time: 23:59, minimum time: 00:00. You can assume that input string is always valid.
 * @date  3-oct-2022
 * Example 1:
 * Input: "?4:5?"
 * Output: "14:59"
 * 
 * Example 2:
 * Input: "23:5?"
 * Output: "23:59"
 * 
 * Example 3:
 * Input: "2?:22"
 * Output: "23:22"
 * 
 * Example 4:
 * Input: "0?:??"
 * Output: "09:59"
 * 
 * Example 5:
 * Input: "??:??"
 * Output: "23:59"
 * 
 * */
#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
void sol(string s){
    if (s[4]=='?'){
        s[4]='9';
    }
    if (s[3]=='?'){
        s[3]='5';
    }
    if (s[1]=='?'){
        if (s[0]=='?'){
            s[0]='2';
            s[1]='3';
        } else if (s[0]=='2'){
            s[1]='3';
        }else{
            s[1]='9';
        }
    } 
    if (s[0]=='?'){
        s[0]= ( int(s[1])<52? '2':'1');
    }

    cout<<s;
}
};

int main(){
    cout<<"Enter no. of test cases\n\n";
    int t;
    Solution sols;
    cin>>t;
    while(t--){
        cout<<"Give a time (in 24-hour format) \"HH:MM\" with missing digits marked as '?' :";
        string s;
        cin>>s;
        cout<<"\n Maximum time : for '"<<s<<"' is ";
        sols.sol(s);
    }

}