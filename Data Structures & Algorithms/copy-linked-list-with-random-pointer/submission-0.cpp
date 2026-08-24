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
        unordered_map<Node*, Node*> mpp;

        Node *p = head;

        while(p){
            mpp[p] = new Node(p->val);
            p = p->next;
        }
        p = head;
        
        while(p){
            mpp[p]->next = mpp[p->next];
            mpp[p]->random = mpp[p->random];
            p = p->next;
        }
        return mpp[head];
    }
};
