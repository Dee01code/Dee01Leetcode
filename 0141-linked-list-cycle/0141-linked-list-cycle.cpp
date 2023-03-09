/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        if(!head || !head->next) return false;
        
        unordered_map<ListNode*, ListNode*> m;
        
        ListNode* cur = head->next;
        ListNode* prev = head;
        
        while(cur != NULL){
            if(m.count(cur)) return 1;
            m[cur] = prev;
            prev = cur;
            cur = cur->next;
        }
        return 0;
    }
};