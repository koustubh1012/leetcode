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
#include <vector>

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
        TreeNode* invertTree(TreeNode* root) {
            if (root == nullptr){
                return root;
            }
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            invertTree(root->left);
            invertTree(root->right);
            return root;
        }
    };

TreeNode* createTree(std::vector<int> values) {
    if (values.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    std::vector<TreeNode*> nodes;
    nodes.push_back(root);

    for (size_t i = 1; i < values.size(); ++i) {
        TreeNode* current = nodes[i / 2];
        if (i % 2 == 1) {
            current->left = new TreeNode(values[i]);
            nodes.push_back(current->left);
        } else {
            current->right = new TreeNode(values[i]);
            nodes.push_back(current->right);
        }
    }

    return root;
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Solution solution;
    std::vector<int> values = {4,2,7,1,3,6,9};
    TreeNode* root = createTree(values);
    std::cout << "Original tree: ";
    printTree(root);
    std::cout << std::endl;

    TreeNode* invertedRoot = solution.invertTree(root);
    std::cout << "Inverted tree: ";
    printTree(invertedRoot);
    std::cout << std::endl;

    return 0;
}