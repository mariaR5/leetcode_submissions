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
        priority_queue<int, vector<int>, greater<int>> pq;

        for (ListNode* list: lists) {
            ListNode* node = list;

            while (node) {
                pq.push(node->val);
                node = node->next;
            }
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!pq.empty()) {
            cur->next = new ListNode(pq.top());
            pq.pop();
            cur = cur->next;
        }

        return dummy->next;
    }
};