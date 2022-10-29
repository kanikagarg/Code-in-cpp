#pragma once
#include "binarytree.h"

#include <iostream>
using namespace std;

template <class T>
typename BinaryTree<T>::TreeNode*  BinaryTree<T>::getRootNode(){
    return root_;
} 

template <class T>
typename BinaryTree<T>::TreeNode* BinaryTree<T>::createNode(T& data){
        TreeNode *node = new TreeNode(data);
        cout<<"\n creating node: "<<node->data;
        return node;
}

template <class T>
void BinaryTree<T>::setLeftNode(BinaryTree<T>::TreeNode *parent, BinaryTree<T>::TreeNode *leftChild){
    parent->left=leftChild;
}

template <class T> void BinaryTree<T>::setRightNode(BinaryTree<T>::TreeNode *parent, BinaryTree<T>::TreeNode *rightChild){
    parent->right=rightChild;
}

template <class T>
BinaryTree<T>::BinaryTree(){
    cout<<"\nBinary Tree constructor called...";
    height=0;
    isFull=true;
    isComplete=true;
    isPerfect=true;
    root_ = nullptr;
}

template <class T>
BinaryTree<T>::BinaryTree(T & data){
    cout<<"\nBinary Tree constructor called...";
    height=1;
    isFull=true;
    isComplete=true;
    isPerfect=true;
    root_ = new TreeNode(data);
}

template <class T>
BinaryTree<T>::~BinaryTree(){
    cout<<"\nBinary Tree destructor called...";
    _destroyTree(root_);
}


template <class T>
void BinaryTree<T>::_destroyTree(TreeNode *root){
    if(root != nullptr){
        _destroyTree(root->left);
        _destroyTree(root->right);
        cout<<"\nDeleting node: "<<root->data;
        delete root;
    }
}

template <class T>
void BinaryTree<T>::inOrder(){
    _printInOrder(root_);
}

template <class T>
void BinaryTree<T>::preOrder(){
    _printPreOrder(root_);
}

template <class T>
void BinaryTree<T>::postOrder(){
    _printPostOrder(root_);
}

template <class T>
void BinaryTree<T>::_printInOrder(TreeNode *root){
    if(root != nullptr){
        cout<<" (";
        _printInOrder(root->left);
        cout<<"<-"<<root->data<<"-> ";
        _printInOrder(root->right);
        cout<<")";
    }else{
        cout<< "x";
    }
    cout<<" ";
}

template <class T>
void BinaryTree<T>::_printPreOrder(TreeNode *root){
    if(root != nullptr){
        cout<<root->data<<" ";
        _printPreOrder(root->left);
        _printPreOrder(root->right);
    }
}

template <class T>
void BinaryTree<T>::_printPostOrder(TreeNode *root){
    if(root != nullptr){
        _printPostOrder(root->left);
        _printPostOrder(root->right);
        cout<<root->data<<" ";
    }
}


