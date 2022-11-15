/**
 * @file Sliding_window_prob.cpp
 * @author Kanika Garg
 * @brief Find the max length subarray with k distinct elements
 * @version 0.1
 * @date 2022-11-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include<vector>
#include<map>
// using namespace std;

void maxkdistinctEle(int arr[], int n, int k, int &maxL, int &maxR){
    std::map<int, int> frq;
    int left =0, right =0;
    int count=0;
    auto checksize = [&](int left, int right)->int{
        return right-left+1;
    };
    auto printArr = [&](int left, int right, int arr[]){
        std::cout<<"[";
        for(int i=left; i<=right; i++){
            std::cout<<arr[i];
            if(i!=right)
                std::cout<<",";
        };
        std::cout<<"]\n";
    };

    std::cout<<"Array is ";
    printArr(0,n-1,arr);

    // moving right counter towards right untill count becomes k or reach end of array
    for(; right<n; right++){
        // element not in freq map therefore a unique element encountered
        if(frq.find(arr[right])==frq.end()){
            frq[arr[right]]=1;
            // increase unique element count
            ++count;
        }else{
            // element was already scanned thus no need to increase the count
            frq[arr[right]]+=1;
        }
        
        // one non unique element was added more than k
        if(count>k){
            // added element removed from freq map
            frq.erase(arr[right]);
            right--;
            count--;
            std::cout<<"\n substring with"<<k<<" distinct element start at "<<left<<", end at "<<right<<" ";
            printArr(left,right,arr);
            maxL=left;
            maxR=right;
            break;
        }
    }

    for(++left; left<n; left++){
        frq[arr[left-1]]-=1;
        count =  frq[arr[left-1]]==0? --count: count;
        while(++right<n){
            if(frq.find(arr[right])==frq.end()){
                frq[arr[right]]=1;
                // increase unique element count
                ++count;
            }else{
                // element was already scanned thus no need to increase the count
                frq[arr[right]]+=1;
            }
             // one non unique element was added more than k
            if(count>k){
                // added element removed from freq map
                frq.erase(arr[right]);
                right--;
                count--;
                std::cout<<"\n substring with "<<k<<" distinct element start at "<<left<<", end at "<<right;
                printArr(left,right,arr);
                if(checksize(maxL,maxR)<checksize(left,right)){
                    maxL=left;
                    maxR=right;
                }
                break;
            }
        }
    }

};

int main(){
    //assumption 0<=arr[i]<=n
    int maxL = 0, maxR=0, k=4,n=17;
    int ar[17]={0,1,2,3,4,4,4,1,2,3,3,1,2,5,6,7,8};
    maxkdistinctEle(ar, n, k, maxL, maxR);
    std::cout<<" longest substring with "<<k<<" distinct element is between "<<maxL<<" and "<<maxR;
    return 0;
}