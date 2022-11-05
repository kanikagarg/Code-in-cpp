/**
 * @file rotateArrRight.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief To rotate an array k times to the right
 * @version 0.1
 * @date 2022-11-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
using namespace std;
#include<vector>

// rotate the array k times to the right, k>=0
void rotateRight(vector<int> &arr, int k){
    k = k % arr.size();
    if(k>0){
    vector<int> result(arr.size(),0);
    for(int i=0; i<arr.size(); i++){
        result[(i+k)%arr.size()]=arr[i];
    }
    arr = result;     
    }
}

int main(){
    int testcase;
    cout<<"Enter testcases";
    cin>>testcase;
    while(testcase--){
        int n;
        cout<<"Enter n";
        cin>>n;
        vector <int>  ar(n,0);
        for(int i=0; i<n; i++)
            cin>>ar[i];
        int k;
        cout<<"Enter times to rotate";
        cin>>k;
        rotateRight( ar, k);
        cout<<"[";
        for(auto ch:ar){
            cout<<ch<<",";
        }
        cout<<"]";
    }
    return 0;
}
