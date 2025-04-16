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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            // handle case if null pointer
            if(p == nullptr && q == nullptr) return true;
    
            // handle unequal roots
            if(p == nullptr || q == nullptr) return false;
    
            // handle unequal root
            if(p->val != q->val) return false;
    
            // check left subtree
            if(!isSameTree(p->left, q->left)) return false;
    
            // check right subtree
            if(!isSameTree(p->right, q->right)) return false;
    
            return true;
        }
    };

int main() {
    // Example usage
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSameTree(root1, root2);
    cout << (result ? "Trees are the same." : "Trees are not the same.") << endl;

    return 0;
}
//     return 0;