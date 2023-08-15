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
    ListNode* partition(ListNode* head, int x) {
        vector<int> before,after;
        ListNode* temp = head;
        while(temp){
            int num = temp->val;
            if(num < x) before.push_back(num);
            else after.push_back(num);
            temp = temp->next;
        }
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        ListNode* small;
        for(auto i : before){
            small = new ListNode(i);
            ans -> next = small;
            ans = small;
        }
        
        for(auto i : after){
            small = new ListNode(i);
            ans -> next = small;
            ans = small;
        }
        return res->next;
    }
};