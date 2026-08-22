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
    bool hasCycle(ListNode* head) {
        if(head==NULL || head->next==NULL) return false;

        ListNode* p = head;
        ListNode* q = head;

        while(q && q->next){
            p = p->next;
            if(q->next) q = q->next->next;

            if(p==q) return true;
        }
        return false;
    }
};
