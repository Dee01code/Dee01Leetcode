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
    
    ListNode* reverse(ListNode* head, ListNode* &ans){
        
        if(!head->next){
            ans = head;
            return head;
        } 
        ListNode* temp = reverse(head->next,ans);
        temp -> next = head;
        return head;
    }
    
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> s1,s2;
        
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* ans = NULL;
        int cry = 0;
        
        while(!s1.empty() && !s2.empty()){
            int a = s1.top();
            int b = s2.top();
            s1.pop(); s2.pop();
            
            int sum = a+b+cry;
            if(sum > 9){
                sum = sum%10;
                cry = 1;
            }
            else cry = 0;
            
            ListNode* temp = new ListNode(sum);
            temp -> next = ans;
            ans = temp;
            
        }
        while(!s1.empty()){
            int a = s1.top();
            s1.pop();
            
            int sum = a+cry;
            if(sum > 9){
                sum = sum%10;
                cry = 1;
            }
            else cry = 0;
            
            ListNode* temp = new ListNode(sum);
            temp -> next = ans;
            ans = temp;
            
        }
        while(!s2.empty()){
    
            int b = s2.top();
            s2.pop();
            
            int sum = b+cry;
            if(sum > 9){
                sum = sum%10;
                cry = 1;
            }
            else cry = 0;
            
            ListNode* temp = new ListNode(sum);
            temp -> next = ans;
            ans = temp;
            
        }
        
        if(cry){
            ListNode* temp = new ListNode(cry);
            temp -> next = ans;
            ans = temp;
        }
        return ans;
    }
};