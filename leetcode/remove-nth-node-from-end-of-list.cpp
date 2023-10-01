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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* root = head;
        
//         ListNode* cur = head;
//         // sz <= 30
//         vector<ListNode*> v;
//         v.reserve(30);
//         v.push_back(cur);
//         while (cur->next) {
//             cur = cur->next;
//             v.push_back(cur);
//         }
//         // ignore the memory leaks lol
//         int i = size(v) - n;
//         if (i == 0) {
//             root = root->next;
//             return root;
//         }
//         ListNode* prev = v[i - 1];
//         if (i == size(v)-1) {
//             prev->next = nullptr;
//         }
//         else {
//             prev->next = prev->next->next;
//         }
        
        ListNode* cur = head;
        ListNode* cur_minus_n = head;
        int sz = 0;
        for (int i = 0; i <= n && cur; ++i) {
            cur = cur->next;
            ++sz;
        }
        while (cur) {
            cur = cur->next;
            cur_minus_n = cur_minus_n->next;
            ++sz;
        }
        if (sz == n) {
            root = root->next;
            return root;
        }
        // cur_minus_n->next to remove
        if (cur_minus_n->next == nullptr) {
            return root;
        }
        cur_minus_n->next = cur_minus_n->next->next;
        return root;
    }
};