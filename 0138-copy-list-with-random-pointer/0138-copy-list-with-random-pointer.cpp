/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*,int> nodeInd; 
        unordered_map<int,Node*> nodeIndCpy;
        
        Node* copy;
        Node* prev = new Node(0);
        Node* temp = head;
        
        copy = prev;
        int cnt = 1;
        
        while(temp){
            prev -> next = new Node(temp -> val);
            prev = prev -> next;
            nodeInd[temp] = cnt;
            nodeIndCpy[cnt++] = prev;
            temp = temp -> next;
        }
        cnt = 1;
        while(head){
            nodeIndCpy[cnt++]->random = nodeIndCpy[nodeInd[head->random]];
            head = head-> next;
        }
        
        return copy->next;
        
    }
};