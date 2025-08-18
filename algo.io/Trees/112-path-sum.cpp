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
    // function to calculate the sum of number below a certain node
    bool hasSum(TreeNode* node, int currentSum, int targetSum){

        // return fasle if node is nullptr
        if(!node) return false;
        
        //update the current sum
        currentSum += node->val;
        
        // check the target sum if it is a leaf node
        if(!node->left && !node->right){
            return currentSum == targetSum;
        }

        // else, recurse on left and right trees
        return hasSum(node->left, currentSum, targetSum) || hasSum(node->right, currentSum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasSum(root, 0, targetSum);
    }
};
