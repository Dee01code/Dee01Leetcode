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
class compare{
    public: 
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
}; 
class Solution {
 
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        int n = lists.size();
        for(int i = 0; i<n; i++){
            if(lists[i] != NULL) pq.push(lists[i]);
        }
        
        
        ListNode* head = NULL;
        ListNode* tale = NULL;
        while(!pq.empty()){
            
            ListNode* mini = pq.top();
            pq.pop();
            
            if(mini -> next != NULL){
                pq.push(mini->next);
            }
            
            if(head == NULL){
                head = mini;
                tale = mini;
            }
            else{
                tale -> next = mini;
                tale = mini;
            }
            
        }
        return head;
    }
};