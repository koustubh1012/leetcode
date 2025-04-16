#include <iostream>

using namespace std;

// Problem: https://leetcode.com/problems/diameter-of-binary-tree/


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
        // initalise max diameter variable
        int max_diameter = 0;
        
        int calculateHeight(TreeNode* root){
            // Handle edge case
            if (root==nullptr) return 0;
    
            // Calculate height of left and right subtree
            int L = calculateHeight(root->left);
            int R = calculateHeight(root->right);
    
            // Calculate diameter from current root
            int diameter = L + R;
    
            // store max diameter
            max_diameter = max(max_diameter, diameter);
    
            // return height
            return 1 + max(L,R);
        }
    
        int diameterOfBinaryTree(TreeNode* root) {
            int height = calculateHeight(root);
            return max_diameter;
        }
    };

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    return 0;
}

