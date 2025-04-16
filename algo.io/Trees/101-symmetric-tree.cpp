#include <iostream>

using namespace std;

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
    
        // function to check left and right subtree
        bool isSame(TreeNode* L, TreeNode* R){
            // handle edge case
            if(L == nullptr && R == nullptr) return true;
    
            // handle unequal leaf case
            if(L == nullptr || R == nullptr) return false;
    
            //check for values
            if(L->val != R->val) return false;
    
            return isSame(L->left, R->right) && isSame(L->right, R->left);
        }
    
        bool isSymmetric(TreeNode* root) {
            return isSame(root->left, root->right);
        }
    };

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSymmetric(root);
    cout << (result ? "Tree is symmetric." : "Tree is not symmetric.") << endl;

    return 0;
}