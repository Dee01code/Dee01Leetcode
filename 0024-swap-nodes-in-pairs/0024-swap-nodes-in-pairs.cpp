/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* prev = head;
        ListNode* next = head->next;
        
        while(next){
            swap(prev->val,next->val);
            if(!next->next) break;
            else if(next -> next -> next == NULL) break;
            prev = next->next;
            next = prev->next;
        }
        return head;
    }
};