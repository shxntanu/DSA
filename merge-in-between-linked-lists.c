struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* temp = list1;
    int i;
    for(i=0; i<a-1; i++) {
        temp = temp->next;
    }
    struct ListNode* bNode = temp->next;
    temp->next = list2;
    while(i < b) {bNode = bNode->next; i++;}
    while(temp->next) temp = temp->next;
    temp->next = bNode;
    return list1;
}
