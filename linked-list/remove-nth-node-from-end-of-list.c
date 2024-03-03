int length(struct ListNode* head) {
    struct ListNode* curr = head;
    int len = 0;
    while(curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int len = length(head);
    if(len == 1 && n == 1) return NULL;
    if(len == n) return head->next;
    int index = len - n - 1;
    struct ListNode *curr = head;
    while(index > 0) {
        curr = curr->next;
        index--;
    }
    curr->next = curr->next->next;
    return head;
}
