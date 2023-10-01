# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        
        n = 0
        cur = head
        while cur:
            n += 1
            cur = cur.next

        m = n // k
        rem = n % k
        ans = []
        cur = head
        for _ in range(k):
            x = m
            if rem:
                rem -= 1
                x += 1
            if x == 0:
                ans.append(None)
                continue
            ans.append(cur)
            for _ in range(x-1):
                cur = cur.next
            if cur and cur.next:
                nxt = cur.next
                cur.next = None
                cur = nxt
        return ans