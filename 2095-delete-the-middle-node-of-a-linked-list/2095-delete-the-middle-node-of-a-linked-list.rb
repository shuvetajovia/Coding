# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end

# @param {ListNode} head
# @return {ListNode}
def delete_middle(head)
    return nil if head.next == nil

    slow = head
    fast = head
    prev = nil

    while fast && fast.next
        prev = slow
        slow = slow.next
        fast = fast.next.next
    end

    prev.next = slow.next

    head
end

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna