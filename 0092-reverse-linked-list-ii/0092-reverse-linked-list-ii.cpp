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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int>s;
        if(left == right || head->next==nullptr)return head;
        ListNode* temp = head;
        ListNode* l = nullptr;
        ListNode* r = nullptr;
        bool ignore = true;
        int pos =1 ;

        while(temp!=nullptr){
           if(pos == left){
            ignore = false;
            l = temp;
           }
           if(ignore){temp=temp->next;pos++;continue;}
           if(pos == right){
            ignore = true;
            r = temp;
           } 
           s.push(temp->val);
           temp=temp->next;
           pos++;
        }
         
         while(!s.empty()){
           l->val = s.top();
           s.pop();
           l=l->next;

        }
         return head;
    }
};