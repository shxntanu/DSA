struct ListNode* middleNode(struct ListNode* head) {
    if(head == NULL || head -> next == NULL) return head;
    struct ListNode *temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        temp = temp -> next;
    }
    if(cnt % 2 == 0) cnt = cnt/2;
    else cnt = ceil(cnt/2);
    temp = head;
    while(cnt != 0){
        temp = temp -> next;
        cnt--;
    }
    return temp;
}
