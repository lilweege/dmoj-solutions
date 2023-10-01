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
    ListNode* deleteDuplicates(ListNode* head) {
        // lol
        vector<int> f(201);
        while (head)
        {
            ++f[head->val + 100];
            head = head->next;
        }
        ListNode* ret = new ListNode(), *curr = ret;
        
        for (int i = 0; i <= 200; ++i)
        {
            if (f[i] == 1)
            {
                curr->next = new ListNode();
                curr = curr->next;
                curr->val = i - 100;
            }
        }
        return ret->next;
    }
};