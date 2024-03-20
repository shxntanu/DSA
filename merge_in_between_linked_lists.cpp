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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {

        ListNode *start = list1;
        ListNode *end = list1;

        a--;
        while (a)
        {
            start = start->next;
            a--;
        }
        b++;
        while (b)
        {
            end = end->next;
            b--;
        }

        start->next = list2;
        start = start->next;
        while (start->next != nullptr)
        {
            start = start->next;
        }

        start->next = end;

        return list1;
    }
};