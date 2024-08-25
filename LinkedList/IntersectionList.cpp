#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != temp2) {
            temp1 = (temp1 == nullptr) ? headB : temp1->next;
            temp2 = (temp2 == nullptr) ? headA : temp2->next;
        }
        return temp1;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked lists
    ListNode* list1 = new ListNode(4);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(8);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(1);
    list2->next->next->next = list1->next->next; // intersect at node with value 8

    printList(list1);
    printList(list2);
    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(list1, list2);

    if (intersection != nullptr) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection" << endl;
    }
    printList(intersection);

    return 0;
}
