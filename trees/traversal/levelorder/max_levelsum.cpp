/**
 * @file max_levelsum.cpp
 * @author your name (you@domain.com)
 * @brief Maximum Level Sum of a Binary Tree
 * Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
 * Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
 * Example 1: 
 * Input: root = [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation: 
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 * 
 * Example 2:
 * Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * Output: 2
 * 
 * Constraints:
 * The number of nodes in the tree is in the range [1, 104].
 * -105 <= Node.val <= 105
 * 
 * 
 * @version 0.1
 * @date 2022-10-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<pair<int,int>>  levelsum;
    int maxLevelSum(TreeNode* root) {
        int level =1;  
        int maxsum = root->val;
        int maxlevel = level;
        TreeNode *cur = root;
        queue<TreeNode*> q, qn;
        q.push(root);
        do{
            cur= q.front();
            pair<int,int> p;
            p.first=level;
            p.second=0;
            
        while(!q.empty()){
            cur = q.front();
            p.second+=cur->val;
            if(cur->left){
                qn.push(cur->left);
            }
            if(cur->right){
                qn.push(cur->right);
            }
            q.pop();
        };
            if(p.second > maxsum){
                maxlevel=p.first;
                maxsum= p.second;
            }
            levelsum.push_back(p);
            
            q.swap(qn);
            level++;
            
        }while(!q.empty());
        
        return maxlevel;
    }
};