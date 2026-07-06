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
    ListNode* sortList(ListNode* head) {

        vector<int>a;
         ListNode * p=head;

         while(p!=nullptr){
            a.push_back( p->val);
            p=p->next;
         }
         sort(a.begin(),a.end());
p=head;
int i =0;
         while(p!=nullptr){
            p->val=a[i];
            p=p->next;
            i++;
         }
        
        return head;
    }
};