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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head;
        if (list1->val < list2->val) {
            head = new ListNode(list1->val);
            list1 = list1->next;
        }
        else {
            head = new ListNode(list2->val);
            list2 = list2->next;
        }
        ListNode* curr = head;
        while (list1 || list2) {
            if (!list1) {
                curr->next = list2;
                break;
            }
            if (!list2) {
                curr->next = list1;
                break;
            }
            if (list1->val < list2->val) {
                curr->next = new ListNode(list1->val);
                list1 = list1->next;
                curr = curr->next;
            }
            else {
                curr->next = new ListNode(list2->val);
                list2 = list2->next;
                curr = curr->next;
            }
        }
        return head;
    }
};