/**
 * @file removeDuplicate.cpp
 * @author Kanika Garg
 * @brief remove duplicates from an unsorted linked list without temporary data buffer.
 * @version 0.1
 * @date 2022-11-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<iostream>
#include "ll.h"
#include<string>
using namespace std;


void remove(ListNode *n, int val){
    ListNode * prev=n, *cur=n->next;
    while(cur!=nullptr){
        if(cur->val==val){
            //duplicate found
            //storing referemce to  current node to be deleted
            ListNode *nodeToDelete  = cur;
            //updating the prev and current node
            prev->next=cur->next;
            cur=cur->next;
            // deleting the removed node
            delete nodeToDelete;
        }else{
            prev=cur;
            cur=cur->next;
        }
    }
}
void removeDuplicate(ListNode *node){
    if(node!=nullptr){
        int val = node->val;
        remove(node, val);
        removeDuplicate(node->next);
    }
}


int main()
{   LL *lst = new LL(4);
    lst->addNodeatEnd(5);
    lst->addNodeatEnd(5);
    lst->addNodeatEnd(5);
    lst->addNodeatEnd(5);
    lst->addNodeatEnd(3);
    lst->addNodeatEnd(2);
    lst->addNodeatEnd(1);
    lst->addNodeatEnd(5);
    lst->addNodeatEnd(0);

    lst->printLL();
    removeDuplicate(lst->head);
    lst->printLL();
    delete lst;
    return 0;
}