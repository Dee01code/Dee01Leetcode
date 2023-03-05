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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        priority_queue<long long int> p;
        
        long long int sum = 0;
        
        while(!q.empty()){
            
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL) continue;
            sum += temp -> val;
            
            if(temp -> left) q.push(temp->left);
            if(temp -> right) q.push(temp->right);
            
            if(q.front() == NULL){
                p.push(sum);  
                cout << sum << " ";
                sum = 0;
                q.push(NULL);
            }
        }
        
        cout << endl;
        while(!p.empty() && --k){
            p.pop();
        }
        if(!p.empty()) return p.top();
        return -1;
        
    }
};