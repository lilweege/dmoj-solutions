// https://leetcode.com/problems/merge-two-sorted-lists

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode* root;
        
        if (l1->val < l2->val) {
            root = l1;
            l1 = l1->next;
        }
        else {
            root = l2;
            l2 = l2->next;
        }
        
        ListNode* cur = root;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        if (l1) {
            while (l2) {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        else {
            while (l1) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
        }
        if (l1)
            cur->next = l1;
        else if (l2)
            cur->next = l2;
        return root;
    }
};