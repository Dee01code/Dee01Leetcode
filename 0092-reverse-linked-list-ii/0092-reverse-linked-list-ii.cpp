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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* frwd = NULL;
        ListNode* st = NULL;
        ListNode* reverseHead = NULL;
        
        int cnt = 0;
        
        while(1){
            if(cnt == left){
                // st = prev;
                // reverseHead = cur;
                while(cnt != right){
                    cnt++;
                    frwd = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = frwd;  
                    
                }
                break;
            }
            cnt++;
            if(cnt == left){
                st = prev;
                reverseHead = cur;
            }
            prev =cur;
            frwd = cur->next;
            cur = frwd;
        }
        if(!st){
            reverseHead->next = frwd;
            return prev;
        }
        st->next = prev;
        reverseHead->next = frwd;
        return head;
    }
};