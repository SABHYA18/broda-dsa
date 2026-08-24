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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode dummy(0);
        ListNode *tail = &dummy;
        int carry = 0;

        while(p||q){
            int sum = 0;
            int x =(p) ? p->val : 0;
            int y = (q) ? q->val : 0;
            sum = carry+x+y;
            if(sum>9){
                int currVal = sum%10;
                tail->next = new ListNode(currVal);
                carry = sum/10;
            }
            else {
                tail->next = new ListNode(sum);
                carry = 0;    
            };

            if(p) p = p->next;
            if(q) q = q->next;
            tail= tail->next;
        }

        if(carry>0){
            tail->next = new ListNode(carry);
        }

        return dummy.next;
    }
};
