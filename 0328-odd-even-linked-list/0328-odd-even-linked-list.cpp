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
    ListNode* oddEvenList(ListNode* head) {
        vector<int>odd;
        vector<int>even;
        ListNode * temp= head;
        int count =1;
        while(temp!=nullptr){
           if(count%2==0){
            even.push_back(temp->val);
           }else if(count%2!=0){
            odd.push_back(temp->val);
           }

           count++;
           temp=temp->next;
        }
        temp=head;
        int i = 0 ; int j = 0;

        while(temp!=nullptr){
          if(j<odd.size()){
            temp->val=odd[j];j++;
           }else if(i<even.size()){
            temp->val=even[i];i++;
           }
           temp=temp->next;


        }

        return head;
    }
};