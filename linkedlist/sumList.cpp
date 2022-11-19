/**
 * @file sumList.cpp
 * @author Kanika Garg
 * @brief  You have two numbers represented by a linked list, where each node contains a single digit.
 * The digits are stored in reverse order, such that the unit digit is at the head of the list. 
 * Write a function that adds the two numbers and returns the sum as a linked list.
 * @version 0.1
 * @date 2022-11-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
  
struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void printNumber(ListNode *head){
    int unit =1;
    int num = 0;
    while(head!=nullptr){
        num+= head->val * unit;
        unit *=10;
        head=head->next;
    }
    cout<<num;
}

//O(n) as deleting n elements starting at head
void deleteLL(ListNode *head){
    ListNode *temp;
    while(head!=nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
} 

class Solution {
    private: 
        int carry=0;
        int place=0;
        int sum=0;
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
            ListNode *res = nullptr;
            ListNode *ref = nullptr;
            while(l1!=nullptr or l2!=nullptr){
                int num=0;
                if(l1 != nullptr){ 
                    num+=l1->val; 
                    l1 = l1->next;
                }
        
                if(l2 != nullptr){
                    num+=l2->val;
                    l2 = l2->next;
                }
                
                if ( carry != 0 ){
                    num+=carry;
                }
                
                carry  = int(num/10);
                num %= 10;
                if(res==nullptr){
                    res = new ListNode(num);
                    ref = res;
                }else{
                    res->next  =  new ListNode(num);
                    res = res->next;
                }
                
            };
            
            if(carry != 0){
                res->next = new ListNode(carry);
            }
            
            return ref;
            
        }// end of addTwoNumbers method
};


int main(){
    Solution sol;
    ListNode *firstNumber  = new ListNode(5);
    firstNumber->next = new ListNode(4);
    firstNumber->next->next = new ListNode(2);
    // firstNumber = 245
    // secondNumber = 847
    // res = 1092

    ListNode *secondNumber  = new ListNode(7);
    secondNumber->next = new ListNode(4);
    secondNumber->next->next = new ListNode(8);
    
    printNumber(firstNumber);
    cout<<"\n+";
    printNumber(secondNumber);
    ListNode *res = sol.addTwoNumbers(firstNumber, secondNumber);
    cout<<"\n=";
    printNumber(res);
    
    // deleting all the lists , freeing memory
    deleteLL(firstNumber);
    deleteLL(secondNumber);
    deleteLL(res);

    return 0;
}