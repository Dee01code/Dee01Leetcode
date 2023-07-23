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
    
//     void copyTree(TreeNode* &from, TreeNode* &to, TreeNode* &curFrom, TreeNode* &curTo){
        
//         if(!from){
//             to = NULL;
//             return;
//         }
//         to = new TreeNode(0);
//         if(from == curFrom) curTo = to;
//         copyTree(from->left, to->left, curFrom, curTo);
//         copyTree(from->right,to->right, curFrom, curTo);
//     }
    
//     void Print(TreeNode* root){
//         if(!root){
//             cout << "Null" <<endl;
//             return;
//         }
        
//         cout << root->val << endl;
//         cout << "Root->left = ";
//         Print(root->left);
//         cout << "Root->right = ";
//         Print(root->right);
//     }
    
//     void solve(TreeNode* root, TreeNode* cur, int n, vector<TreeNode*> &ans){
        
//         if(n == 0){
//             if(!(count(ans.begin(),ans.end(),root)))
//                 ans.push_back(root);
//             return;
//         }
//         if(n==1) return;
        
//         if(n>=2){
            
//             cur->left = new TreeNode(0);
//             cur->right = new TreeNode(0);
            
//             if(n-2 == 0){
//                 if(!(count(ans.begin(),ans.end(),root)))
//                     ans.push_back(root);
               
//                 return;
//             }
//             if(n-2 == 1) return;
            
//             TreeNode* tree1 = new TreeNode(0); TreeNode* cur1;
//             TreeNode* tree2 = new TreeNode(0); TreeNode* cur2;
//             Print(root);
//             copyTree(root,tree1, cur, cur1);
            
//             cout << "Tree 1 is Copied"<< endl;
//             Print(tree1);
            
//             copyTree(root,tree2, cur, cur2);
            
//             cout << "Tree 2 is Copied"<< endl;
//             Print(tree2);
//             solve(tree1, cur1->left, n-2, ans);
//             solve(tree2, cur2->right, n-2, ans);
//         }
        
        
//     }
    
    vector<TreeNode*> helper(int n){
        
        if(n==1){
            vector<TreeNode*> base;
            base.push_back(new TreeNode(0));
            return base;
        }
        
        vector<TreeNode*> ans;
        
        for(int i = 1; i<n; i+=2){
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n-i-1);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* par = new TreeNode(0);
                    par->left = l;
                    par->right = r;
                    ans.push_back(par);
                }
            }
        }
        return ans;
        
        
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        
        return helper(n);
    }
};