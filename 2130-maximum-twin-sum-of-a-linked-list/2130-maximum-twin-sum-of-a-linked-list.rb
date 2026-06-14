# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val = 0, _next = nil)
#         @val = val
#         @next = _next
#     end
# end

# @param {ListNode} head
# @return {Integer}
def pair_sum(head)
    arr = []
    
    while head
        arr << head.val
        head = head.next
    end
    
    max_sum = 0
    n = arr.length
    
    (0...(n / 2)).each do |i|
        max_sum = [max_sum, arr[i] + arr[n - 1 - i]].max
    end
    
    max_sum
end

# Synced seamlessly with LeetHub Pro
# Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
# Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna