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
    public:

        void sortedArr(TreeNode *root, vector<int> &v)
        {

            if (!root) return;
            sortedArr(root->left, v);
            v.push_back(root->val);
            sortedArr(root->right, v);
        }

    bool findTarget(TreeNode *root, int k)
    {

        vector<int> v;
        sortedArr(root, v);

        int left = 0;
        int right = v.size() - 1;
        int sum;
        while (left < right)
        {
            sum = v[left] + v[right];
            if (sum == k) return 1;
            else if (sum > k) right--;
            else left++;
        }
        return 0;
    }
};