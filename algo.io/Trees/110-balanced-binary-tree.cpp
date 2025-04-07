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

#include <iostream>
#include <string>

#include <vector>
#include <queue>

using namespace std;
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
        int calculateDepth(TreeNode* N){
            if (!N) return 0;
            int L = calculateDepth(N->left);
            int R = calculateDepth(N->right);
            return 1 + max(L,R);
        }
    
        bool isBalanced(TreeNode* root) {
            if (!root) return true;
            queue<TreeNode*> Q;
            Q.push(root);
            while(!Q.empty()){
                auto current = Q.front();
                Q.pop();
                int L = calculateDepth(current->left);
                int R = calculateDepth(current->right);
                if (abs(L - R) > 1) return false;
                if(current->left) Q.push(current->left);
                if(current->right) Q.push(current->right);
            }
            return true;
        }
    };

int main() {
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    bool balanced = solution.isBalanced(root);
    cout << "Is the binary tree balanced? " << (balanced ? "Yes" : "No") << endl;

    return 0;
}