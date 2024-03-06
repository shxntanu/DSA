# Floyd's Circle Detection Algorithm

## Introduction

Floyd's Circle Detection Algorithm, also known as the Tortoise and Hare Algorithm, is an efficient technique for determining whether a linked list contains a cycle (loop). It employs two pointers, aptly named tortoise and hare, that traverse the list at different speeds. This clever approach enables it to detect cycles effectively and efficiently.

## Key Points

- Utilizes only two pointers, offering a memory-efficient solution.
- Operates in linear time complexity, making it suitable for large linked lists.
- Applicable to various data structures that permit pointer advancement, including singly and doubly linked lists.
- Simple to implement and understand, making it a popular choice for cycle detection.

## Algorithm Steps

1. Initialization:
        Create two pointers, tortoise and hare, and initialize them to the head of the linked list.

2. Iteration:
        While both pointers are not nullptr:
            Move the tortoise pointer one node forward (tortoise = tortoise->next).
            Move the hare pointer two nodes forward (hare = hare->next->next, if applicable; handle potential nullptr cases carefully).
            If the tortoise and hare pointers meet at any point, it signifies the presence of a cycle.

3. Cycle Detection
        If the hare pointer reaches nullptr before meeting the tortoise, the linked list does not contain a cycle.

## C/C++ Implementation

`C++`

```cpp
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

bool hasCycle(Node* head) {
    Node* tortoise = head;
    Node* hare = head;

    while (hare != nullptr && hare->next != nullptr) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = head; // Create a cycle

    if (hasCycle(head)) {
        cout << "Linked list contains a cycle." << endl;
    } else {
        cout << "Linked list does not contain a cycle." << endl;
    }

    return 0;
}
```

## Explanation

1. Header Inclusion: Include the iostream header for input/output operations.
2. Node Structure: Define a Node structure to represent a node in the linked list. Each node contains an integer data field and a next pointer to the next node.
3. hasCycle Function:
   - Takes a pointer to the head node of the linked list as input.
   - Initializes tortoise and hare pointers to the head node.
   - Employs a while loop to iterate through the linked list:
     - Advances the tortoise pointer by one node.
     - Advances the hare pointer by two nodes (with null pointer checks).
     - If tortoise and hare meet, a cycle is detected, so the function returns true.
     - If the loop completes without finding a cycle, the function returns false.
4. main Function:
        Creates a sample linked list with a cycle.
        Calls the hasCycle function to determine if the list contains a cycle.
        Prints a message based on the result.

