#include<iostream>

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LL{
    private:
    /**
     * @brief removing nodes with value of val other than node n
     * 
     * @param n 
     * @param val 
     */
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
    
      
    public:
        ListNode *head; 

        LL(){
            head = nullptr;
        };  

        LL(int val){
            head = new ListNode(val);
        }; 

        /**
         * @brief Printing list when no explicit head given
         * 
         */
        void printLL(){
            std::cout<<"\n List is :";
            ListNode *start = head;
            while( start != nullptr){
            std::cout<<"->"<<start->val;
            start=start->next;
            }
            std::cout<<"-> nullptr\n";
        };

        /**
         * @brief Printing linked list when list node is given. all the nodes linked after this node gets printed
         * 
         * @param head 
         */
        void printLL(ListNode *node){
            std::cout<<"\n List is :";
            ListNode *start = node;
            while( start != nullptr){
                std::cout<<"->"<<start->val;
                start=start->next;
            }
            std::cout<<"-> nullptr\n";
        };

        /**
         * @brief adds a node with val as its node value;
         * 
         * @param val 
         */
        void addNodeatEnd(int val){
        ListNode *node = new ListNode(val);
        ListNode *start = head;
        if(start==nullptr){
            head=node;
            std::cout<<"\nadding val to list"<<head->val;
        }else{
        while(start->next != nullptr ){
            start=start->next;
        };
        start->next=node;
        std::cout<<"\nadding val to list"<<node->val;
        }
        // printLL();
        }

        /**
         * @brief removes nodes with duplicate data value
         * 
         * @param node 
         */
        void removeDuplicate(ListNode *node){
            if(node!=nullptr){
                int val = node->val;
                remove(node, val);
                removeDuplicate(node->next);
            }
        }


        ~LL(){
            while(head != nullptr){
                ListNode *node = head;
                std::cout<<"\nfreeing "<<head;
                head = head->next;
                delete node;
            }
            printLL();
        };

};