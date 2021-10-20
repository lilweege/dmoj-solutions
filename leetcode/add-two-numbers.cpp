// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr)
        {
            int n1 = 0, n2 = 0;
            if (l1)
            {
                n1 = l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                n2 = l2->val;
                l2 = l2->next;
            }
            int n = n1 + n2 + carry;
            curr->val = n % 10;
            carry = n / 10;
            
            curr->next = new ListNode();
            prev = curr;
            curr = curr->next;
        }
        if (carry)
        {
            curr->val = carry;
        }
        else
        {
            curr = prev;
            curr->next = nullptr;
        }
        return head;
    }
};