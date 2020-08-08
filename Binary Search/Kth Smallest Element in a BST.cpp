/*

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

*/

class Solution {
public:
TreeNode* solve(TreeNode *root, int &count, int k) {
	if(!root) return nullptr;
	TreeNode *left = solve(root->left,count,k); 

	if(left) return left;
	count++;

	if(count==k) return root;
	return solve(root->right,count,k);
}

int kthSmallest(TreeNode *root, int k) {
	int count=0;
	TreeNode* temp = solve(root,count,k);

	return temp->val;
}
};
