/* Count Valid Hours

Given a time (in 24-hour format) with missing digits marked as '?', we want to replace all of the question marks with digits (0-9) in such a way as to obtain a valid time. The earliest possible time is 00:00 and the latest valid time is 23:59.

Write a function:
class Solution { public int solution(String T); }

that, given a string T in the format "HH:MM", returns an integer denoting the number of valid times that can be obtained by replacing the question marks.

Examples:

Given T = "2?:45", the function should return 4. We can obtain four valid times: "20:45", "21:45", "22:45" and "23:45".
Given T = "?9:32", the function should return 2. Valid times are: "09:32" and "19:32".
Given T = "0?:?0", the function should return 60.
Given T = "?4:0?", the function should return 20.
Given T = "29:01", the function should return 0.
Assume that: T consists of exactly five characters; the third one is ':'; the others are digits (0-9) or '?'.

In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.*/

/*
Range of values: 
00:00 - 23:59

Range of input
0 ? - 14:34 -> 0
1 ? - 1?:00 -> (a) t[1]>3 -> (b)
2 ? - 18:?? -> (a) t[1]>3 ->
3 ? - ?2:?? -> (a) t[1]>3 ->
4 ? - ??:?? -> [(a) t[1]>3 -> XXX] + []

(a) t[1]>3
1   ?  :  0   0
0 * 10 *  1 * 0 -> 10

1   2  :  0   ?
1 * 1 *  1 * 10 -> 10

(a) t[1]>3
1   2  :  ?   ?
1 * 1  *  6 * 10 -> 10


*/
#include<vector>
// #include <bits/stdc++.h>
#include<iostream>
// #include <cstdlib>
#include<string>
using namespace std;



class Solution { 
    public:
     int solution1(string T){
        int count = 0;
        int count_question = 0; 
        vector<int> v;
        for (int i=0; i<T.size(); i++){
            if (i!=2 and T[i]=='?'){
            count_question++;
            v.push_back(i);
            };
        }
        if (count_question == 0){  return (0); 
        }
        int i = 0;
        count = 1;
        while((count_question--) >0){            
            if (v[i]==0){
                if( T[1] == '?'){ 
                    count *= (4*1 + 10*2);
                }else if(int(T[1])<52 and int(T[1])>47)
                {  
                    count *= 3;
                }else{
                    count *= 2;
                }
            };

            if (v[i]==1){
                if (T[0]=='?'){
                    ;
                }else if (T[0]=='2'){
                    count *=4; 
                }else{
                    count *=10;
                }
            };

            if (v[i]==3){
                count *= 6;
            };

            if (v[i]==4){
                count *= 10;
            };

            i++;
        }
        return (count);

    } // end of function
    int solution2(string T){
        int count = 1;
        bool isQuestion = false;
        for(int i=T.size()-1; i>=0; i--){     
            if (i==2){
                i--;
            };
            if (T[i]=='?'){
                if (isQuestion == false ){
                    isQuestion = true;
                };       
                switch(i) {
                case 4:  count *=10;
                    break;
                case 3: count *=6;
                    break;
                case 1: if (T[0] =='2'){
                            count *= 4;
                        }else if (T[0]=='?'){
                            count *= (10*2 + 4*1);
                        }else{
                            count *= 10;
                        }
                        i--;
                        break;
                case 0: if (T[1] == '?'){
                            break;
                        }else {
                            if (int(T[1])<52 and int(T[1])>47){ // 52 is ascii 4
                                count *= 3;
                            }else{
                                count *= 2;
                            }
                        }
                        break;
                }
            }
        }

        if (isQuestion) {
        return (count);
        } else {
        return (0);
        }
    }
}; // end of class

int main(){
    cout<<"Enter no. of test cases\n\n";
    int t;
    cin>>t;
    while(t--){
        cout<<"Give a time (in 24-hour format) \"HH:MM\" with missing digits marked as '?' :";
        string s;
        cin>>s;
        Solution sol;
        cout<<"[sol1] ---> The number of valid times that can be obtained by replacing the question marks in '"<<s<<"' is "<<sol.solution1(s)<<" valid times."<<endl;
        cout<<"[sol2] ---> The number of valid times that can be obtained by replacing the question marks in '"<<s<<"' is "<<sol.solution2(s)<<" valid times."<<endl;
    }

}