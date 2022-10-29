/**
 * @file main.cpp
 * @author Kanika Garg (reachkanikagarg@gmail.com)
 * @brief Binary Tree implementation
 * @version 0.1
 * @date 2022-10-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <vector>
#include "binarytree.hpp"

using namespace std;


int main(){
    cout<<"\nCreating a Binary Tree\n";
    vector<int> in={1, 3, 5, 8, 11};
    int data;
    BinaryTree<int> bt;
    //       8
    //      / \
    //     3   11
    //    / \
    //   1   5
    // create the above tree: method 1
    // bt.setRootNode(in[3]); //8 root node
    // bt.getRootNode()->left = bt.createNode(in[1]); // 3 - 8
    // bt.getRootNode()->right = bt.createNode(in[4]); // 3 - 8 - 11
    // bt.getRootNode()->left->left = bt.createNode(in[0]); //  1 - (3 - 8- 11)
    // bt.getRootNode()->left->right = bt.createNode(in[2]);// 1 - (3-8-11)-5

    // creating the above tree method 2

    bt.setRootNode(in[3]); //8 root node
    bt.setLeftNode( bt.getRootNode(),bt.createNode(in[1]));
    bt.setRightNode(bt.getRootNode(),bt.createNode(in[4]));
    bt.setLeftNode( bt.getRootNode()->left,bt.createNode(in[0]));
    bt.setRightNode(bt.getRootNode()->left,bt.createNode(in[2]));


    cout<<"\nin order: ";
    bt.inOrder();
    cout<<"\n post order: ";
    bt.postOrder();
    cout<<"\n pre order: ";
    bt.preOrder();
    cout<<"\nexiting program!";
    return 0;

}