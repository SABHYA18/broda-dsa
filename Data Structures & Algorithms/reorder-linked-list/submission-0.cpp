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
private: 
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr!=NULL){
            ListNode* nextNode = curr->next; 
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode *p = head, *q = head;
        while(q&&q->next){
            p = p->next;
            q = q->next->next;
        }
        ListNode* temp = p->next;
        p->next = NULL;
        q = reverseList(temp);
        p = head;
    

        while(q){
            ListNode* nextFirst= p->next;
            ListNode* nextSecond = q->next;

            p->next = q;
            q->next = nextFirst;

            p = nextFirst;
            q = nextSecond;

        }
    }
};
