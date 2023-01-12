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
    ListNode* kreversal(ListNode* head, int k, int &len){
        if(len<k) return head;
        if(head == NULL) return NULL;
        ListNode* frwd = NULL;
        ListNode* prev = NULL;
        ListNode* cur = head;
        int cnt = 0;
        
        while(cur != NULL && cnt<k){
                frwd = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = frwd;     
                cnt++;
                len--;
        }  
        
        if(frwd != NULL){
        head -> next =  kreversal(cur,k,len);
            
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            len++; 
        }
        // cout << len<< endl;
        return kreversal(head,k,len);
    }
};