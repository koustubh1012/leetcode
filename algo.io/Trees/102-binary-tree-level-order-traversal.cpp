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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        queue<TreeNode*> Q;
        if(!root){
            return order;
        }
        Q.push(root);
        while(!Q.empty()){
            int n = Q.size();
            vector<int> currOrder;

            for(int i = 0; i < n; i++){
                auto curr = Q.front();
                Q.pop();
                currOrder.push_back(curr->val);
                if(curr->left != nullptr){
                    Q.push(curr->left);
                }
                if(curr->right != nullptr){
                    Q.push(curr->right);
                }
            }

            order.push_back(currOrder);
        }
        return order;
    }
};
