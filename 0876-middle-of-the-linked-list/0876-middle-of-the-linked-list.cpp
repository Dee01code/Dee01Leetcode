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
    ListNode* ans;
    void solve(ListNode* head,int& size,int &temp){
        if(head->next == NULL) return;
        size++;
        solve(head->next,size,temp);
        temp++;
        if(temp == size/2) ans = head;
        return; 
    }
    
public:
    ListNode* middleNode(ListNode* head) {
        if(head->next != NULL && head->next->next == NULL) return head->next;
        int size=0,temp=0;
        ans = head;
        solve(head,size,temp);
        return ans;
    }
};