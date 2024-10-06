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

TreeNode* dfs(TreeNode* curr,int target){

    if(curr == nullptr)return nullptr;

    curr->left = dfs(curr->left,target);
    curr->right = dfs(curr->right,target);

    if(curr->left == nullptr && curr->right == nullptr && curr->val == target)return nullptr;
    return curr;
}

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        return dfs(root,target);

    }
};
