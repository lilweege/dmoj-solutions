// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        multimap<int, ListNode*> m;
        for (ListNode* p : lists)
            if (p)
                m.emplace(p->val, p);
        
        if (m.empty())
            return nullptr;
        
        
        ListNode* root = begin(m)->second;
        m.erase(begin(m));
        ListNode* p = root->next;
        if (p)
            m.emplace(p->val, p);
        
        // cout << root->val << "\n";
        ListNode* cur = root;
        while (!m.empty()) {
            auto [val, node] = *begin(m);
            // cout << val << "\n";
            cur->next = node;
            cur = cur->next;
            
            m.erase(begin(m));
            ListNode* p = node->next;
            if (p)
                m.emplace(p->val, p);
        }
        
        return root;
    }
};