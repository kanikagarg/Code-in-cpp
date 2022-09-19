#include <iostream>
#include <vector>
using namespace std;

struct   Node{
    int data;
    Node *next;
    Node *prev;
};

class LinkList{
    private:
        Node* start= nullptr;
    
    public:
        void add_node_at_beg(Node *node){
            if (start == nullptr){
                cout<<"\nlist empty adding node at list start "<<node->data;
                start = node;
                node->next = nullptr;
                node->prev = nullptr;
            } else {
                cout<<"\nlist not empty adding node at beginning "<<node->data;
                node->next = start;
                node->prev = nullptr; 
                start = node;
            }
            traverse();
        }

        void add_node_at_end(Node *node){
            Node *st = start;
            if (st == nullptr){
                cout<<"\nlist empty adding node at end "<<node->data;
                start=node;
                node->next=nullptr;
                node->prev=nullptr;
            }else{
            cout<<"\n list not empty adding node at end "<<node->data;
            while(st->next != nullptr){
                st = st->next;
            }
            st->next = node;
            node->prev = st;
            node->next = nullptr;
            }
            traverse();
        }

        void add_at_index(Node *node, int index){
            int pos = index, cpos = -1;
            Node *curNode = start;
            while(curNode){
                cpos++;
                if (cpos==pos){
                    if(curNode == start){
                        start = node;
                        node->next = start;
                        node->prev = nullptr;
                    }else{
                        node->prev = curNode->prev;
                        (curNode->prev)->next = node;
                        node->next = curNode;
                    }
                }else{
                    curNode = curNode->next;
                }
            }
            traverse();
        }

        void traverse(){
            Node *node = start;
            cout<<endl;
            while (node != nullptr){
                cout<< node->data<<" -> ";
                node = node->next;
            };
            cout<<"X";
        }

};

int main(){
    cout<<"main started";
    Node *N1 = new Node;
    Node *N2 = new Node;
    Node *N3 = new Node;
    Node *N4 = new Node;
    Node *N5 = new Node;
    N1->data = 4;
    N2->data = 5;
    N3->data = 7;
    N4->data = 3;
    N5->data = 6;
    LinkList *l1=new LinkList();
    l1->add_node_at_beg(N1);
    l1->add_node_at_end(N2);
    l1->add_node_at_end(N3);
    l1->add_node_at_beg(N4);
    l1->add_at_index(N5,3);
    l1->traverse();
    return 0;
}
