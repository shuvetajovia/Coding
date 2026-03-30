class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        vals = []

        for l in lists:
            while l:
                vals.append(l.val)
                l = l.next

        vals.sort()

        dummy = ListNode(0)
        curr = dummy

        for v in vals:
            curr.next = ListNode(v)
            curr = curr.next

        return dummy.next