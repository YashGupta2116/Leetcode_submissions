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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head->next == nullptr || head->next->next == nullptr) return {-1, -1};

        int count = 1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int firstCriticalPoint = 0;
        int lastCriticalPoint = 0;
        int prev = head->val;
        head = head->next;
        while (head->next != nullptr) {
            count++;
            if ((head->val > prev && head->val > head->next->val) ||
    (head->val < prev && head->val < head->next->val)) {
                if (firstCriticalPoint != 0) {
                    mini = min(mini, count - lastCriticalPoint);
                    maxi = max(maxi, count - firstCriticalPoint);
                    lastCriticalPoint = count;
                } else {
                    firstCriticalPoint = count;
                    lastCriticalPoint = count;
                }
            }
            prev = head->val;
            head = head->next;
        }

        if (mini == INT_MAX || maxi == INT_MIN) return {-1, -1};
        return {mini, maxi};
    }
};