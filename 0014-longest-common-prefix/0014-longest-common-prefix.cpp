class Solution {
public:
    
class TrieNode{
public:
    int data;
    int terminal;
    TrieNode* kids[26] = {NULL};
    TrieNode(char ch){
        data = ch;
        terminal = false;
    }
};

class Trie{
public:    

    TrieNode* root;
    Trie(){ 
        root = new TrieNode('\0');
    }
    
    /*------------------------------------------------------------*/

    void  insertInner(TrieNode* root, string word){
        if(word.size() == 0){
            root -> terminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0]-'a';

        if(root->kids[index] != NULL){
            child = root->kids[index];
        }
        else{
            child = new TrieNode(word[0]);
            root -> kids[index] = child;
        }
        insertInner(child,word.substr(1));
    }

    /*------------------------------------------------------------*/

    /*------------------------------------------------------------*/
    
    int branchNumber(TrieNode* root){
        int ans = 0;
        for(int i = 0; i<26; i++){
            if(root->kids[i] != NULL) ans++;
        }
        return ans;
    }
    
    /*------------------------------------------------------------*/
    
    void lcp(TrieNode* root, string & ans){
        if(root->terminal || branchNumber(root) >1) {
            return;
        }   

        TrieNode* child;
        for(int i=0; i<26; i++){
            if(root->kids[i] != NULL){
                char ch = 'a'+i;
                child = root->kids[i]; 
                ans.push_back(ch);
            }
        }
        
        lcp(child,ans);
    }  
};

    
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string ans= "";
        
        Trie *t = new Trie();
        for(auto i : strs){
            if(i.size()==0) return ans;
            t->insertInner(t->root,i);
        }

        t->lcp(t->root,ans);
        return ans;
        
    }
};