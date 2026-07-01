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
   
    bool isPalindrome(ListNode* head) {
        vector<int>a;

        while(head!=nullptr){
         a.push_back(head->val);
         head=head->next;
        }

        int n = a.size()-1;
        int i = 0;

        while(i<=n){
            if(a[i]!=a[n]){
                return false;
            }
            i++;
            n--;
        }
        return true;
    }
};