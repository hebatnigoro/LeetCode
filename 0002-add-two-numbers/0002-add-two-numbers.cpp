class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2, *prev = nullptr;
        int carry = 0;
        while (p || q) {
            int sum = carry + (p ? p->val : 0) + (q ? q->val : 0);
            int digit = sum >= 10 ? sum - 10 : sum;
            carry = sum >= 10;
            if (p) {
                p->val = digit;
                prev = p;
                p = p->next;
                if (q) q = q->next;
            } else {
                prev->next = q;
                q->val = digit;
                prev = q;
                q = q->next;
            }
        }
        if (carry) prev->next = new ListNode(1);
        return l1;
    }
};
