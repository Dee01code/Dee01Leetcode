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
    
    void inorder(TreeNode *root, vector<int> &sorted)
        {
            if (!root) return;
            inorder(root->left, sorted);
            sorted.push_back(root->val);
            inorder(root->right, sorted);
        }

    void solve(TreeNode *root, vector<int> &postSum, int &ind)
    {
        if (!root) return;
        solve(root->left, postSum, ind);
        root->val = postSum[ind++];
        solve(root->right, postSum, ind);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        
        vector<int> sorted;

        inorder(root, sorted);

        int nodes = sorted.size();
        vector<int> postSum(nodes, 0);
        int sum = 0;

        for (auto i = nodes - 1; i >= 0; i--)
        {
            sum += sorted[i];
            postSum[i] = sum;
        }

        int ind = 0;

        solve(root, postSum, ind);
        return root;
        
    }
};