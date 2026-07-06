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
    ListNode* reverse(ListNode* head) {

       
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)return head;

        int elements = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            elements++;
        }
        k = k % elements;
        if(k==0)return head;
        head = reverse(head);
        temp = head;
        k--;
        while (k--)
        temp = temp->next;
        ListNode* l1 = head;
        ListNode* l2 = temp->next;
        temp->next = nullptr;

        l1 = reverse(l1);
        l2 = reverse(l2);
        temp = l1;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = l2;
        return l1;
    }
};