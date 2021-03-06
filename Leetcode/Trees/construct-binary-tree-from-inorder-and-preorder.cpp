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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return buildTree(preorder, inorder, 0, 0, inorder.size()-1);
    }
    
    TreeNode* buildTree(vector<int> &preorder, vector<int>&inorder, int pos, int in_start, int in_end)
    {
        if(in_start>in_end)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[pos]);
        int in_pos;
        for(int i=in_start;i<=in_end;i++)
        {
            if(inorder[i]==root->val)
            {
                in_pos=i;
                break;
            }
        }
        
        int left_nodes=in_pos-in_start+1;
        
        root->left=buildTree(preorder, inorder, pos+1, in_start, in_pos-1);
        root->right=buildTree(preorder, inorder, pos+left_nodes, in_pos+1, in_end);
        
        return root;
        
        
    }
};