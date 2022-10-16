/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include<iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



class Solution {
public:
    ListNode* partition_at_x(ListNode* head, int x) {
        ListNode *current = head, *insertAt=head, *nextNode = nullptr, *prev = nullptr;
        while(current){

            while(current->val < x){
                insertAt = current;
                current = current->next;
                prev = insertAt;
            }
            
            while(current)
            {    if(current->val < x){
                    nextNode = current->next;
                    prev->next = nextNode;

                    if(head->val >= x){
                        ListNode *temp = head;
                        head = current;
                        current->next = temp;
                        prev = current;
                        current = temp;
                        insertAt = head;
                        break;
                    }else{

                      ListNode *temp = insertAt->next;
                      insertAt->next = current;
                      (insertAt->next)->next=temp;
                      insertAt = insertAt->next;
                      current = nextNode;
                    }      
                    
                }else{
                    prev = current;
                    current = current->next;
                }
            }
        }
        return head;
    }
};


class LL{
    public:
    ListNode *head;    
    LL(){
        head = nullptr;
    }
    void printLL(){
        cout<<"\n List is :";
        ListNode *start = head;
        while( start != nullptr){
        std::cout<<"->"<<start->val;
        start=start->next;
        }
        cout<<"-> nullptr";
    };void printLL(ListNode *head){
        cout<<"\n List is :";
        ListNode *start = head;
        while( start != nullptr){
        std::cout<<"->"<<start->val;
        start=start->next;
        }
        cout<<"-> nullptr";
    };
    void addNodeatEnd(int val){
        ListNode *node = new ListNode(val);
        ListNode *start = head;
        if(start==nullptr){
            head=node;

        cout<<"adding val to list"<<head->val;
        }else{
        while(start->next != nullptr ){
            start=start->next;
        };
        start->next=node;

        cout<<"adding val to list"<<node->val;
        }
        // printLL();
    }
    ~LL(){
        while(head != nullptr){
            ListNode *node = head;
            std::cout<<"freeing "<<head;
            head = head->next;
            delete node;
        }
        printLL();
    };

};


int main(){
    LL *a = new LL();
    LL *b = new LL();
    a->addNodeatEnd(1);a->addNodeatEnd(4);a->addNodeatEnd(3);a->addNodeatEnd(0);a->addNodeatEnd(2);a->addNodeatEnd(5);a->addNodeatEnd(2);
    a->printLL();
    b->addNodeatEnd(2);b->addNodeatEnd(1);
    b->printLL();
    cout<<"\nSolution :\n";
    Solution sol;
    a->printLL(sol.partition_at_x(a->head,3));
    // a->printLL();
    b->printLL(sol.partition_at_x(b->head,2));
    // b->printLL();
    cout<<"\n\ndone!!!\n";
       
    return 0;
}