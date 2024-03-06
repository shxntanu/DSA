// Floyd'd Cycle Deteciton Algorithm
bool hasCycle(struct ListNode *head) {
    if(head == NULL) return false;
        struct ListNode *fast = head;
        while (fast && fast->next) {
            head = head->next;
            fast = fast->next->next;
            if (head == fast) return true;
        }
    return false;
}
