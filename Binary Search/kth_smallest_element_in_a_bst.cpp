/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Another approaches - Can be also solved using augmented tree(will be solving after).

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(!root) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> v;
        inorder(root,v);
      
        return v[k-1];
    }
};
// Complexity of above solution : Time - O(n), Space - O(h), where h is the height of the tree.
