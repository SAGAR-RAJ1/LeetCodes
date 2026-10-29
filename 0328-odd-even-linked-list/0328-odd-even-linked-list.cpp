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
        if(!head || !head->next)return head;

        ListNode * oddcurr = head;
        ListNode * oddhead = head;
        ListNode * evencurr = head->next;
        ListNode * evenhead = head->next;

        while(evencurr && evencurr->next){

            oddcurr->next=oddcurr->next->next;
            evencurr->next=evencurr->next->next;

            oddcurr=oddcurr->next;
            evencurr=evencurr->next;
        }

        oddcurr->next=evenhead;
        return oddhead;
    }
};