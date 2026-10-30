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
        ListNode * ans = new ListNode(-1);
        ListNode * temp = ans;
        
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>q;
        for(auto &i:lists){
            if(i){
                q.push({i->val,i});
            }
        }

        while(!q.empty()){
            auto node = q.top();
            q.pop();

            ListNode* neww= new ListNode(node.first);
            temp->next = neww;
            temp=neww;

            if(node.second->next){
                q.push({node.second->next->val,node.second->next});
            }
        }

        return ans->next;
    }
};