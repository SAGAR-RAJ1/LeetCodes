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
        if (lists.size() == 0)
            return nullptr;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (!pq.empty()) {
            auto a = pq.top();
            pq.pop();
            if (a.second->next)
                pq.push({a.second->next->val, a.second->next});

            temp->next = a.second;
            temp = a.second;
        }

        return dummy->next;
    }
};