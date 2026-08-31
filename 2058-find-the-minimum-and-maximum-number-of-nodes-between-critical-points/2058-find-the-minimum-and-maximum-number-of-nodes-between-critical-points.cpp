class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int index = 1;

        int first = -1;
        int last = -1;

        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {

            // Check local maximum or local minimum
            bool critical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);

            if (critical) {

                // First critical point
                if (first == -1) {
                    first = index;
                }
                else {
                    // Distance from previous critical point
                    minDistance = min(minDistance, index - last);
                }

                // Current becomes last critical point
                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Fewer than 2 critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }

        int maxDistance = last - first;

        return {minDistance, maxDistance};
    }
};