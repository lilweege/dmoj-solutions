/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* toDelete = node->next;
        node->val = toDelete->val;
        node->next = toDelete->next;
        delete toDelete;
    }
};