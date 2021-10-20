// https://leetcode.com/problems/odd-even-linked-list


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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return nullptr;
        vector<ListNode*> v;
        ListNode* cur = head;
        while (cur->next) {
            v.push_back(cur);
            cur = cur->next;
        }
        v.push_back(cur);
        int n = v.size();
        ListNode* newHead = new ListNode(head->val);
        cur = newHead;
        for (int i = 2; i < n; i += 2) {
            cur->next = new ListNode(v[i]->val);
            cur = cur->next;
        }
        for (int i = 1; i < n; i += 2) {
            cur->next = new ListNode(v[i]->val);
            cur = cur->next;
        }
        return newHead;
    }
};
/*
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* pre,
                * cur = head,
                * sec = head->next,
                * nex;

        int cnt = 0;
        while (cur->next) {
            pre = cur;
            cur = cur->next;
            nex = cur->next;
            pre->next = nex;
            ++cnt;
        }
        (cnt & 1 ? pre->next : cur->next) = sec;
        return head;
    }
};*/