#include <bits/stdc++.h>
using namespace std;

/*
Explanation:
CRUX: In a singly linked list, one node can point to at most one node, BUT there can be multiple nodes pointing to the same node

# How to think(recursion):
* In the questions of recursion we should always think of breaking down the problem into smaller and smaller parts untill we reach the base condition
* Now, here we need to reverse the linked list with suppose 5 nodes
    * Now, I can't reverse the linked list with 5 nodes all at once
    * So, I will try to reverse 4 nodes
    * But, I can't do it either
    * So, I will try for 3 and so on untill I reach a single node
    * Then, will start to backtrack and start the process of reversal

# Process of reversal:
* Keep a pointer to the head's next node
* And then reverse their pointers accordingly
* Then return the newHead, which remains the same after reversing the last 2 nodes, i.e, newHead
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    else
    {
        ListNode *newHead = reverseList(head->next);

        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
}