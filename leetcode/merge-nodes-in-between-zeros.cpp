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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* lastZero = head;
        ListNode* curr = lastZero->next;
        int tot = 0;
        ListNode* newlistHead = new ListNode();
        ListNode* newlistCurr = newlistHead;
        while (curr) {
            tot += curr->val;
            if (curr->val == 0) {
                newlistCurr = newlistCurr->next = new ListNode(tot);
                tot = 0;
            }
            curr = curr->next;
        }
        return newlistHead->next;
    }
};