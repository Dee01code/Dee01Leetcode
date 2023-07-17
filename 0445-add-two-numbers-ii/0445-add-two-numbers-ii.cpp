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
        ListNode* rv1 = NULL;
        ListNode* temp1 = reverse(l1,rv1);
        temp1 -> next = NULL;
        
        ListNode* rv2 = NULL;
        ListNode* temp2 = reverse(l2,rv2);
        temp2 -> next = NULL;
        
        int cry = 0;
        ListNode* ans = NULL;
        while(rv1 && rv2){
            cout << "Hi" << endl;
            int sum = rv1->val + rv2->val + cry;
            if(sum > 9){
                sum = sum % 10;
                cry = 1;
            }
            else cry = 0;
            ListNode* temp = new ListNode(sum);
            temp -> next = ans;
            ans = temp;
            rv1 = rv1->next;
            rv2 = rv2->next;
        }
        cout << "Hi" << endl;
        while(rv1){
            cout << "Hi" << endl;
            int sum = rv1->val+cry;
            if(sum > 9){
                sum = sum % 10;
                cry = 1;
            }
            else cry = 0;
            cout << sum << " ";
            ListNode* temp = new ListNode(sum);
            temp -> next = ans;
            ans = temp;
            rv1 = rv1->next;
        }
        cout << "Hi" << endl;
        while(rv2){
            cout << "Hi" << endl;
            int sum = rv2->val+cry;
            if(sum > 9){
                sum = sum % 10;
                cry = 1;
            }
            else cry = 0;
            ListNode* temp = new ListNode(sum);
            temp -> next = ans;
            ans = temp;
            rv2 = rv2->next;
        }
        if(cry){
            ListNode* temp = new ListNode(cry);
            temp -> next = ans;
            ans = temp;
        }
        cout << "Hi" << endl;
        return ans;
        
    }
};