/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* s[100];
int sp;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    sp = 0;
    struct ListNode* p = head;
    while (p) {
        s[sp++] = p;
        p = p->next;
    }
    
    
    if (sp - n - 1 < 0) {
        return head->next;
    }
    struct ListNode* pv = s[sp - n - 1];
    struct ListNode* v = s[sp - n];
    pv->next = v->next;
    
    return head;
}