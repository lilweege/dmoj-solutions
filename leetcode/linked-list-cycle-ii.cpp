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
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> vis;
        while (head) {
            if (vis.find(head) != vis.end()) {
                return head;
            }
            vis.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};