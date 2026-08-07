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
        ListNode* temp = new ListNode(-1);
        ListNode* ans = temp;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            q;
        for (auto& a : lists) {
            if (a) q.push({a->val,a});
        }

        while(!q.empty()) {

            auto loc = q.top().second;
            q.pop();

            if (loc->next) {
                q.push({loc->next->val, loc->next});
            }

            temp->next = loc;
            temp = loc;
        }

        return ans->next;
    }
};