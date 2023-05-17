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
    int pairSum(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        
        int i = 0;
        
        ListNode* prev = NULL;
        ListNode* next = head;
        
        while(i<cnt/2){
            ListNode* temp = next->next;
            next->next = prev;
            prev = next;
            next = temp;
            i++;
        }
        
        int twin = INT_MIN;
        for(int i = 1; i<=cnt/2; i++){
            int twinSum = prev->val + next->val;
            twin = max(twin,twinSum);
            prev = prev->next;
            next = next->next;
        }
        return twin;
    }
};