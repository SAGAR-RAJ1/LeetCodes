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
        
        ListNode * temp = head->next;
        ListNode * prev = head;
        int count = 1;
        if(!head->next->next)return {-1,-1};

        vector<int>critical;
        
        while(temp->next){
             ListNode * next = temp->next;
             if(temp->val > prev->val && temp->val > next->val){
                critical.push_back(count);
             }
             if(temp->val < prev->val && temp->val < next->val){
                critical.push_back(count);
             }
             prev=temp;
             temp=temp->next;
             count++;
        }
          int n =critical.size();
        
        if(n<2)return {-1,-1};

        int maxi = critical[n-1]-critical[0];
        int mini = INT_MAX;
        for(int i = 1 ; i<n; i++){
         mini = min(mini,critical[i]-critical[i-1]);
        }

        return {mini,maxi};
    }
};