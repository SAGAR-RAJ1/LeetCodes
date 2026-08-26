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
        
        int n = lists.size();
        if(n==0 )return {};
        ListNode * temp = new ListNode(-1);
        ListNode * ans = temp;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        for(auto & a :lists){
            if(a)pq.push({a->val,a});
        }
        while(!pq.empty()){
            auto node = pq.top().second;
            pq.pop();
            temp->next=node;
            temp=temp->next;

            if(node->next){
                pq.push({node->next->val,node->next});
            }
        }

        return ans->next;
    }
};