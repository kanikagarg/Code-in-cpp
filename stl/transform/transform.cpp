
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int pluss(int x, int y){ return x+y; }
int inc(int x){ return x+1; }
int main(){
    vector<int> arr1= {11,12,33,44};
    vector<int> arr2= {-1,-2,-3,-4};
    cout<<"Before transformation binary arr1";
    for(int i=0; i<arr1.size(); i++){
        cout<<"\n i :"<<i<<" arr1["<<i<<"] = "<<arr1[i];
    }
    cout<<"\nBefore transformation binary arr2";
    for(int i=0; i<arr2.size(); i++){
        cout<<"\n i :"<<i<<" arr2["<<i<<"] = "<<arr2[i];
    }
    cout<<"\nAfter arr2::";
    transform(arr1.begin(),arr1.end(), arr2.begin(), arr2.begin(), pluss);   
    for(int i=0; i<arr2.size(); i++){
        cout<<"\n i :"<<i<<" arr2["<<i<<"] = "<<arr2[i];
    }
    cout<<"\nAfter urinary transformation on arr2 to increment by 1";
    transform(arr2.begin(),arr2.end(), arr2.begin(), inc);   
    for(int i=0; i<arr2.size(); i++){
        cout<<"\n i :"<<i<<" arr2["<<i<<"] = "<<arr2[i];
    }
    cout<<"\nafter all transformation arr1";
    for(int i=0; i<arr1.size(); i++){
        cout<<"\n arr1["<<i<<"] = "<<arr1[i];
    }
    cout<<endl;
    return 0;
}