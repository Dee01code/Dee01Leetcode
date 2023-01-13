/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{

    int cntNode(TreeNode *root)
    {
        if (!root) return 0;
        return 1 + cntNode(root->left) + cntNode(root->right);
    }

    bool solve(TreeNode *root, int ind, int cnt)
    {
        if (!root) return 1;
        if (ind >= cnt) return 0;
        else
        {
            bool left = solve(root->left, 2 *ind + 1, cnt);
            bool right = solve(root->right, 2 *ind + 2, cnt);
            return left && right;
        }
    }

    public:
        bool isCompleteTree(TreeNode *root)
        {

            int totNode = cntNode(root);
            return solve(root, 0, totNode);
        }
};