#pragma once
#include <iostream>

template <typename T>
class BinaryTree{
    private:
        class TreeNode{
            public:
            T data;
            TreeNode *left, *right;
            TreeNode(T & data): data(data), left(nullptr), right(nullptr){};
        };
        TreeNode *root_;

        void _destroyTree(TreeNode *node);
            
        /**
         * @brief Printing tree in inorder
         * 
         * @param node 
         */
        void _printInOrder(TreeNode *node);
        /**
         * @brief Printing tree in pre order
         * 
         * @param node 
         */
        void _printPreOrder(TreeNode *node);
        /**
         * @brief Printing tree in Post order
         * 
         * @param node 
         */
        void _printPostOrder(TreeNode *node);

    public:
    /**
     * @brief Get the Root Node object
     * 
     * @return TreeNode* 
     */
    TreeNode * getRootNode();

    /**
     * @brief Set the Root Node object
     * 
     * @param data 
     */
    void setRootNode(T & data){
        std::cout<<"creating root node:"<<data;
        root_ = new TreeNode(data);
    }

    /**
     * @brief Create a Node object
     * 
     * @param data 
     * @return TreeNode* 
     */
    TreeNode * createNode(T & data);
    /**
     * @brief Set the Left Node object
     * 
     * @param parent 
     * @param leftchild 
     */
    void setLeftNode(TreeNode *parent,TreeNode *leftchild);
    /**
     * @brief Set the Right Node object
     * 
     * @param parent 
     * @param rightchild 
     */
    void setRightNode(TreeNode *parent,TreeNode *rightchild);


    /**
     * @brief height of the tree is the number of edges in the longest path from leaf node to the root node
     */
    int height; 
    /**
     * @brief isFull tells whether the binary tree is full or not. 
     * A binary Tree is full if and only if every node in the tree has either zero children or two children
     * 
     */
    bool isFull;

    /**
     * @brief isPerfect determines whether the binary tree is perfect or not. A binary tree is considered perfect if and only if all the internal nodes have two children and leaves are at same level.
     * 
     */
    bool isPerfect;

    /**
     * @brief isComplete tells whether the binary tree is complete or not. Binary tree is complete if and only if the tree is perfect up untill the last level AND all Leaf nodes are PUSHED TO the Left on last level.
     */
    bool isComplete;

    /**
     * @brief isEmpty tells whether the tree is empty or not
     * 
     */
    bool isEmpty;

    /**
     * @brief pre order traversal of the tree
     * 
     */
    void preOrder();

    /**
     * @brief post order traversal of tree
     * 
     */
    void postOrder();

    /**
     * @brief in Order traversal of tree
     * 
     */
    void inOrder();

    /**
     * @brief Construct a new Binary Tree object
     * 
     */
    BinaryTree();

    /**
     * @brief Construct a new Binary Tree object
     * 
     * @param data 
     */
    BinaryTree(T & data);

    /**
     * @brief Destroy the Binary Tree object
     * 
     */
    ~BinaryTree();

};