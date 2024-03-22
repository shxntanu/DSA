/*
Question Link: https://leetcode.com/problems/palindrome-linked-list/

Explanation:

# How to think: O(n) and O(1)
* One thing that comes in our mind is to traverse the linked list till the end, keep a tail pointer at the end and increment head and decrement tail after checking whether their corresponding values are equal or not
* But, it is a singly linked list, so we can't traverse backwards from tail
* So, in order to traverse backwards, we will have to reverse the second half of the linked list
* Now, for that, we will have to know where the second half starts, so that we can call the reverseLinkedList function
* In order to find that, we will use tortoise and hare method --> slow and fast pointers
    * Or we can also use count to calculate the length of the linked list and then interate over the linked list again until (i<n/2)
* After we reach to the middle of the linked list(slow pointer), we can call the reverse function and proceed further in the above manner
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseLinkedList(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return head;
        }
        else
        {
            ListNode *newHead = reverseLinkedList(head->next);
            ListNode *front = head->next;
            front->next = head;
            head->next = nullptr;
            return newHead;
        }
    }

    bool isPalindrome(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        else if (head->next->next == nullptr)
        {
            ListNode *temp = head->next;

            if (head->val == temp->val)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            ListNode *slow = head;
            ListNode *fast = head;

            while (fast->next != nullptr && fast->next->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode *newHead = reverseLinkedList(slow->next);
            ListNode *first = head;
            ListNode *second = newHead;

            while (second != nullptr)
            {
                if (first->val != second->val)
                {
                    return false;
                }
                else
                {
                    first = first->next;
                    second = second->next;
                }
            }

            return true;
        }
    }
};