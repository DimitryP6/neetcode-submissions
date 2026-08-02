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
    ListNode* reverseList(ListNode* head) {
        if ((head == nullptr) || (head->next == nullptr)) {
            return head;
        }
        ListNode* prevNode = head;
        ListNode* curNode = head->next;
        while (curNode != nullptr) {
            ListNode* nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        head->next = nullptr;
        head = prevNode;
        return head;
    }
};
