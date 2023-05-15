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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        
        while(temp){
            cnt++;
            temp = temp->next;
        }
        
        if(cnt-k+1 == k) return head;
        
        ListNode* swap1;
        ListNode* swap2;
        temp = head;
        
        for(int i = 1; i <= cnt; i++){
            if(i == k) swap1 = temp;
            temp = temp->next;
        }
        
        temp = head;
        
        for(int i = 1; i <= cnt; i++){
            if(i == cnt-k+1){
                swap2 = temp;
                break;
            }
            temp = temp->next;
        }
        
        swap(swap1->val,swap2->val);
        return head;
    }
};