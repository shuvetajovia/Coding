class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while (true) {
            ListNode* kth = prevGroup;

            // find kth node
            for (int i = 0; i < k && kth; i++)
                kth = kth->next;

            if (!kth) break;

            ListNode* groupStart = prevGroup->next;
            ListNode* nextGroup = kth->next;

            // reverse k nodes
            ListNode* prev = nextGroup;
            ListNode* curr = groupStart;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // reconnect
            prevGroup->next = kth;
            prevGroup = groupStart;
        }

        return dummy.next;
    }
};