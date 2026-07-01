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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int nodes = 0;
        ListNode* temp = head;

        while(temp!=nullptr){
            nodes++;
            temp=temp->next;
        }

        int dlt = nodes-n+1;
        if(dlt==1){
            return head->next;
        }
        temp = head;
        ListNode* prev = nullptr;
        nodes=0;

        while(temp!=nullptr){
            nodes++;
           
            if(nodes==dlt){
             prev->next=temp->next;
             delete(temp);
             return head;
            }
             prev=temp;
            temp=temp->next;

        }

        return head;
    }
};