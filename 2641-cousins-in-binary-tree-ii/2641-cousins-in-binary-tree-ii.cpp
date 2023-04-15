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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        vector<vector<pair<int,TreeNode*>>> ans;
        unordered_map<int, pair<long long, unordered_map<TreeNode*,long long>>> m; 
        
        queue<pair<TreeNode*,pair<TreeNode*,int>>> q;
        q.push({root,{NULL,1}});
        q.push({NULL,{NULL,NULL}});

        unordered_map<TreeNode*,long long> lvlmap;
        long long lvlsum = 0;
        
        int curlvl = 1;
        while (!q.empty())
        {
            pair<TreeNode*,pair<TreeNode*,int>> p = q.front();
            TreeNode *temp = p.first;

            q.pop();

            if(!temp){
                m[curlvl] = {lvlsum,lvlmap};
                lvlmap.clear();
                lvlsum = 0;
                curlvl++;

                if(!q.empty()) q.push({NULL,{NULL,NULL}});
               
             }
            else
            {
                lvlsum += temp->val;
                
                cout << temp-> val << " ";
                
                pair<TreeNode*,int> lwise = p.second;
                TreeNode* parent  = lwise.first;

                int lvl = lwise.second;

                if(parent){
                    lvlmap[parent] += temp->val;
                }

                if (temp->left) q.push({temp->left,{temp,lvl+1}});
                if (temp->right) q.push({temp->right,{temp,lvl+1}});
                
            }
        }
        

        queue<pair<TreeNode*,pair<TreeNode*,int>>> q2;
        q2.push({root,{NULL,1}});
        q2.push({NULL,{NULL,NULL}});

        while (!q2.empty())
        {
            pair<TreeNode*,pair<TreeNode*,int>> p = q2.front();
            TreeNode *temp = p.first;

            q2.pop();

            if(!temp){
  
                if(!q2.empty()) q2.push({NULL,{NULL,NULL}});
    
             }
            else
            {
                cout << temp-> val << " ";
                pair<TreeNode*,int> lwise = p.second;
                TreeNode* parent  = lwise.first;

                int lvl = lwise.second;


                if(lvl<3) temp->val = 0;
                else{temp -> val = m[lvl].first - (m[lvl].second[parent]);}



                if (temp->left) q2.push({temp->left,{temp,lvl+1}});
                if (temp->right) q2.push({temp->right,{temp,lvl+1}});

            }
        }
        
        
        return root;
        
    }
};