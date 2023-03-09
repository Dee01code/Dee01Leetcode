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
        
        while(head->next != NULL){
            if(m.count(head->next)) return 1;
            m[head->next] = head;
            head = head->next;
        }
        return 0;
    }
};