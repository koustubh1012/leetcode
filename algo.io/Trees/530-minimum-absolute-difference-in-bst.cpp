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
    // inorder traveseral function
    void inOrder(TreeNode* node){
        if(!node){
            return;
        }

        // traverse left subtree
        inOrder(node->left);
        
        if(prev){
            minDiff = min(minDiff, node->val - prev->val);
        }

        prev = node;

        // traverse right subtree
        inOrder(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        minDiff  = INT_MAX;
        prev = nullptr;
        inOrder(root);
        return minDiff;
    }

    private:
        int minDiff;
        TreeNode* prev;
};
