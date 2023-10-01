# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        gen = count()
        h = []
        for head in lists:
            if head:
                heappush(h, (head.val, next(gen), head))

        if not h:
            return None

        _, _, root = heappop(h)
        if root.next:
            heappush(h, (root.next.val, next(gen), root.next))

        cur = root
        while h:
            _, _, node = heappop(h)
            cur.next = node
            cur = cur.next

            if node.next:
                heappush(h, (node.next.val, next(gen), node.next))

        return root