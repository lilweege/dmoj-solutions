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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool isEven = true;
        while (fast) {
            fast = fast->next;
            if (!fast) {
                isEven = false;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* prev = NULL;
        ListNode* half1 = head;
        while (half1 != slow) {
            ListNode* next = half1->next;
            half1->next = prev;
            prev = half1;
            half1 = next;
        }
        
        ListNode* half2 = prev;
        if (!isEven) half1 = half1->next;
        
        while (half1 && half2) {
            if (half1->val != half2->val)
                return false;
            half1 = half1->next;
            half2 = half2->next;
        }
        
        return true;
    }
};