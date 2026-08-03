/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) {
            return false;
        }
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;
        while (fastPointer->next && slowPointer->next && slowPointer->next->next) {
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next->next;
            if (fastPointer == slowPointer) {
                return true;
            }
        }
        return false;
    }
};
